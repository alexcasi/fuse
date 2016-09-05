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

template <class Visitor, class T>
auto read(Visitor& v, T& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  boost::fusion::for_each(val, v);
}

template <class Visitor, class T>
auto write(Visitor& v, T const& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  boost::fusion::for_each(val, v);
}

template <class Visitor, class T>
auto serialized_size(Visitor& v, T const& val) ->
    typename std::enable_if<boost::fusion::traits::is_sequence<T>::value>::type
{
  boost::fusion::for_each(val, v);
}

FUSE_NS_END

#endif

