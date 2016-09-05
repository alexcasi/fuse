/// @file
/// Defines the serialized_sizer class.
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_SERIALIZEDSIZER_HPP
#define FUSE_SERIALIZEDSIZER_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <type_traits>

FUSE_NS_BEGIN

class serialized_sizer
{
public:
  serialized_sizer()
    : size_(0)
  {
    // ctor
  }

  std::size_t size() const { return size_; }
  void add(std::size_t size) { size_ += size; }

  template <class T>
  auto operator()(const T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    serialized_size(*const_cast<serialized_sizer*>(this), val);
  }

  template <class T>
  auto operator()(const T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

protected:
  std::size_t size_;
};

template <class T>
std::size_t serialized_size(const T& val)
{
  serialized_sizer s;
  s(val);
  return s.size();
}

FUSE_NS_END

#endif
