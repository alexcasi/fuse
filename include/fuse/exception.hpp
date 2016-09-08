/// @file
/// Defines exception types used by this library.
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_EXCEPTION_HPP
#define FUSE_EXCEPTION_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <stdexcept>
#include <string>

FUSE_NS_BEGIN

class fuse_error : public std::runtime_error
{
public:
  fuse_error(const std::string& what)
    : runtime_error(what)
  {
    // ctor
  }
};

class invalid_data : public fuse_error
{
public:
  invalid_data()
    : fuse_error("data is invalid")
  {
    // ctor
  }

  invalid_data(const std::string& what)
    : fuse_error(what)
  {
    // ctor
  }
};

class buffer_too_small : public fuse_error
{
public:
  buffer_too_small()
    : fuse_error("buffer too small")
  {
    // ctor
  }

  buffer_too_small(const std::string& what)
    : fuse_error(what)
  {
    // ctor
  }
};

FUSE_NS_END

#endif
