/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_VISITORS_ARRAY_HPP
#define FUSE_VISITORS_ARRAY_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <type_traits>

FUSE_NS_BEGIN

template <class Reader, class T, std::size_t N>
void read(Reader& r, T (&val) [N])
{
  for (std::size_t i = 0; i != N; ++i)
    r(val[i]);
}

template <class Writer, class T, std::size_t N>
void write(Writer& w, const T (&val) [N])
{
  for (std::size_t i = 0; i != N; ++i)
    w(val[i]);
}

template <class SerializedSizer, class T, std::size_t N>
void serialized_size(SerializedSizer& s, const T (&val) [N])
{
  for (std::size_t i = 0; i != N; ++i)
    s(val[i]);
}

FUSE_NS_END

#endif
