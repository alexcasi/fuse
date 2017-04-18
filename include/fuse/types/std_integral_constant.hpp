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
  T val;
  read(r, val);

  if (val != v)
    detail::throw_exception(invalid_data("integral constant mismatch"));
}

template <class Writer, class T, T v>
void write(Writer& w, std::integral_constant<T, v>)
{
  write(w, v);
}

template <class SerializedSizer, class T, T v>
void serialized_size(SerializedSizer& s,
                     std::integral_constant<T, v>)
{
  serialized_size(s, v);
}

FUSE_NS_END

#endif
