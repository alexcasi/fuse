/// @file
/// Main header file which includes all public headers of this library.
/// Suitable for precompiling.
///
/// @copyright Copyright (c) 2015 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_FUSE_HPP
#define FUSE_FUSE_HPP

#include "fuse/detail/config.hpp"

#if ASIOEXT_HAS_PRAGMA_ONCE
#pragma once
#endif

/// @defgroup core Core functionality
/// Core components
///
/// @defgroup types Type support
/// Serialization support for common types.

/// fuse's main namespace.
namespace fuse {}

#include "fuse/reader.hpp"
#include "fuse/writer.hpp"
#include "fuse/serialized_sizer.hpp"

#endif
