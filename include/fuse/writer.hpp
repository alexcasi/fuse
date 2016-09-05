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
  explicit writer(void* data, std::size_t size)
    : data_(data)
    , size_(size)
  {
    // ctor
  }

  std::size_t size() const { return size_; }
  void* data() const { return data_; }

  void consume(std::size_t size)
  {
    size_ -= size;
    data_ = static_cast<char*>(data_) + size;
  }

  template <class T>
  auto operator()(const T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    write(*const_cast<writer*>(this), val);
  }

  template <class T>
  auto operator()(const T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

protected:
  void* data_;
  std::size_t size_;
};

FUSE_NS_END

#endif
