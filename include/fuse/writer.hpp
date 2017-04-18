/// @file
/// Defines the writer class.
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_WRITER_HPP
#define FUSE_WRITER_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <type_traits>

FUSE_NS_BEGIN

class writer
{
public:
  explicit writer(void* data, std::size_t capacity)
    : data_(static_cast<char*>(data))
    , size_(0)
    , capacity_(capacity)
  {
    // ctor
  }

  const void* data() const { return data_; }
  std::size_t size() const { return size_; }
  std::size_t capacity() const { return capacity_; }

  void* peek()
  {
    return data_ + size_;
  }

  void commit(std::size_t size)
  {
    size_ += size;
  }

protected:
  char* data_;
  std::size_t size_;
  std::size_t capacity_;
};

FUSE_NS_END

#endif
