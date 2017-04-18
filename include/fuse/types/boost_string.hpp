/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_TYPES_BOOSTSTRING_HPP
#define FUSE_TYPES_BOOSTSTRING_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "fuse/detail/check_size.hpp"
#include "fuse/detail/throw_exception.hpp"

#include "fuse/exception.hpp"
#include "fuse/operations.hpp"

#include <boost/container/string.hpp>

#include <limits>
#include <cstring>

FUSE_NS_BEGIN

template <class Reader, class T, class Traits, class Allocator>
void read(
    Reader& r,
    boost::container::basic_string<T, Traits, Allocator>& val)
{
  length_type size = 0;
  read(r, size);

  detail::check_size(r.size(), size * sizeof(T),
                     "not enough data for string");

  val.assign(static_cast<const T*>(r.data()), size);
  r.consume(size * sizeof(T));
}

template <class Writer, class T, class Traits, class Allocator>
void write(
    Writer& w,
    const boost::container::basic_string<T, Traits, Allocator>& val)
{
  if (val.size() > std::numeric_limits<length_type>::max())
    detail::throw_exception(invalid_data("string is too long"));

  length_type size = static_cast<length_type>(val.size());
  write(w, size);

  detail::check_size(w.capacity(), size * sizeof(T),
                     "not enough data for string");

  std::memcpy(w.peek(), val.data(), size * sizeof(T));
  w.commit(size * sizeof(T));
}

template <class SerializedSizer, class T, class Traits, class Allocator>
void serialized_size(
    SerializedSizer& s,
    const boost::container::basic_string<T, Traits, Allocator>& val)
{
  if (val.size() > std::numeric_limits<length_type>::max())
    detail::throw_exception(invalid_data("string is too long"));

  length_type size = static_cast<length_type>(val.size());
  serialized_size(s, size);
  s.commit(size * sizeof(T));
}

FUSE_NS_END

#endif
