/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_TYPES_ARITHMETIC_HPP
#define FUSE_TYPES_ARITHMETIC_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "fuse/detail/check_size.hpp"

#include "fuse/exception.hpp"

#include <type_traits>

FUSE_NS_BEGIN

template <class Reader, class T>
auto read(Reader& r, T& val) ->
    typename std::enable_if<std::is_arithmetic<T>::value>::type
{
  detail::check_size(r, sizeof(T),
                     "not enough data for arithmetic");

  // TODO(tim): endianness

  val = *static_cast<const T*>(r.data());
  r.consume(sizeof(T));
}

template <class Writer, class T>
auto write(Writer& w, T const& val) ->
    typename std::enable_if<std::is_arithmetic<T>::value>::type
{
  detail::check_size(w, sizeof(T),
                     "not enough data for arithmetic");

  *static_cast<T*>(w.data()) = val;
  w.consume(sizeof(T));
}

template <class SerializedSizer, class T>
auto serialized_size(SerializedSizer& s, T const& val) ->
    typename std::enable_if<std::is_arithmetic<T>::value>::type
{
  s.add(sizeof(T));
}

// enum values

template <class Reader, class T>
auto read(Reader& r, T& val) ->
    typename std::enable_if<std::is_enum<T>::value>::type
{
  typename std::underlying_type<T>::type v;
  r(v);
  val = static_cast<T>(v);
}

template <class Writer, class T>
auto write(Writer& w, T const& val) ->
    typename std::enable_if<std::is_enum<T>::value>::type
{
  using utype = typename std::underlying_type<T>::type;
  w(static_cast<utype>(val));
}

template <class SerializedSizer, class T>
auto serialized_size(SerializedSizer& s, T const& val) ->
    typename std::enable_if<std::is_enum<T>::value>::type
{
  s.add(sizeof(typename std::underlying_type<T>::type));
}

FUSE_NS_END

#endif
