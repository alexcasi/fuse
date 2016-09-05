/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_TYPES_STDINTEGRALCONSTANT_HPP
#define FUSE_TYPES_STDINTEGRALCONSTANT_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "fuse/detail/throw_exception.hpp"

#include "fuse/exception.hpp"

FUSE_NS_BEGIN

template <class Reader, class T, T v>
void read(Reader& r, std::integral_constant<T, v>)
{
  typedef std::integral_constant<T, v> type;

  typename type::value_type val;
  r(val);

  if (val != type::value)
    detail::throw_exception(invalid_data("integral constant mismatch"));
}

template <class Writer, class T, T v>
void write(Writer& w, std::integral_constant<T, v>)
{
  typedef std::integral_constant<T, v> type;
  w(type::value);
}

template <class SerializedSizer, class T, T v>
void serialized_size(SerializedSizer& s,
                     std::integral_constant<T, v>)
{
  typedef std::integral_constant<T, v> type;
  w(type::value);
}

FUSE_NS_END

#endif
