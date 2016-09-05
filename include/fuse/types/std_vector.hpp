/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_TYPES_STDVECTOR_HPP
#define FUSE_TYPES_STDVECTOR_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <vector>

FUSE_NS_BEGIN

template <class Reader, class T, class Allocator>
void read(Reader& r, std::vector<T, Allocator>& val)
{
  length_type size = 0;
  r(size);

  val.reserve(size);
  for (length_type i = 0; i != size; ++i) {
    T item;
    r(item);
    val.push_back(std::move(item));
  }
}

template <class Writer, class T, class Allocator>
void write(Writer& w, const std::vector<T, Allocator>& val)
{
  if (val.size() > std::numeric_limits<length_type>::max())
    detail::throw_exception(invalid_data("vector is too long"));

  length_type size = static_cast<length_type>(val.size());
  w(size);

  for (const auto& v : val)
    write(w, v);
}

template <class SerializedSizer, class T, class Allocator>
void serialized_size(SerializedSizer& s,
                     const std::vector<T, Allocator>& val)
{
  if (val.size() > std::numeric_limits<length_type>::max())
    detail::throw_exception(invalid_data("string is too long"));

  length_type size = static_cast<length_type>(val.size());
  s(size);

  for (const auto& v : val)
    s(v);
}

FUSE_NS_END

#endif
