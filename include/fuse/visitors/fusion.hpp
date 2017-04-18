/// @file
/// Defines fusion visitors for read(), write(), ...
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_VISITOR_FUSION_HPP
#define FUSE_VISITOR_FUSION_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <boost/fusion/include/is_sequence.hpp>
#include <boost/fusion/include/for_each.hpp>

FUSE_NS_BEGIN

template <class Reader>
class fuse_reader
{
  fuse_reader(Reader& r)
    : r_(r)
  {
    // ctor
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    read(const_cast<Reader&>(r_), val);
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

  Reader& r_;
};

template <class Writer>
class fuse_writer
{
  fuse_writer(Writer& w)
    : w_(w)
  {
    // ctor
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    write(const_cast<Writer&>(w_), val);
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

  Writer& w_;
};

template <class SerializedSizer>
class fuse_sizer
{
  fuse_sizer(SerializedSizer& s)
    : s_(s)
  {
    // ctor
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<!std::is_empty<T>::value>::type
  {
    serialized_size(const_cast<SerializedSizer&>(s_), val);
  }

  template <class T>
  auto operator()(T& val) const ->
      typename std::enable_if<std::is_empty<T>::value>::type
  {
    // do nothing
  }

  SerializedSizer& s_;
};

template <class Reader, class T>
auto read(Reader& r, T& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  fuse_reader<Reader> v(r);
  boost::fusion::for_each(val, v);
}

template <class Writer, class T>
auto write(Writer& w, T const& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  fuse_writer<Writer> v(w);
  boost::fusion::for_each(val, v);
}

template <class SerializedSizer, class T>
auto serialized_size(SerializedSizer& s, T const& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  fuse_sizer<SerializedSizer> v(s);
  boost::fusion::for_each(val, v);
}

FUSE_NS_END

#endif

