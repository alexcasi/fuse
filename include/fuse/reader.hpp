/// @file
/// Defines the reader class.
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_READER_HPP
#define FUSE_READER_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <type_traits>

FUSE_NS_BEGIN

class reader
{
public:
  explicit reader(const void* data, std::size_t size)
    : data_(data)
    , size_(size)
  {
    // ctor
  }

  std::size_t size() const { return size_; }
  const void* data() const { return data_; }

  void consume(std::size_t size)
  {
    size_ -= size;
    data_ = static_cast<const char*>(data_) + size;
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    read(*const_cast<reader*>(this), val);
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

protected:
  const void* data_;
  std::size_t size_;
};

FUSE_NS_END

#endif
