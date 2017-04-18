/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_DETAIL_CHECKREMAINING_HPP
#define FUSE_DETAIL_CHECKREMAINING_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include "fuse/detail/throw_exception.hpp"

#include "fuse/exception.hpp"

FUSE_NS_BEGIN

namespace detail {

inline void check_size(std::size_t size, std::size_t required_size,
                       const char* what)
{
  if (size < required_size)
    detail::throw_exception(buffer_too_small(what));
}

}

FUSE_NS_END

#endif
