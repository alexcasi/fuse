/// @file
///
///
/// @copyright Copyright (c) 2016 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at
/// http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_DETAIL_THROWEXCEPTION_HPP
#define FUSE_DETAIL_THROWEXCEPTION_HPP

#include "fuse/detail/config.hpp"

#if FUSE_HAS_PRAGMA_ONCE
#pragma once
#endif

#if defined(FUSE_HAS_BOOST_THROW_EXCEPTION)
# include <boost/throw_exception.hpp>
#endif

FUSE_NS_BEGIN

namespace detail {

#if defined(FUSE_HAS_BOOST_THROW_EXCEPTION)
using boost::throw_exception;
#else
// Declare the throw_exception function for all targets.
template <typename Exception>
void throw_exception(const Exception& e);

// Only define the throw_exception function when exceptions are enabled.
// Otherwise, it is up to the application to provide a definition of this
// function.
# if !defined(FUSE_NO_EXCEPTIONS)
template <typename Exception>
void throw_exception(const Exception& e)
{
  throw e;
}
# endif
#endif

}

FUSE_NS_END

#endif
