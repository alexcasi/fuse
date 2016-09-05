/// @copyright Copyright (c) 2015 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef FUSE_DETAIL_CONFIG_HPP
#define FUSE_DETAIL_CONFIG_HPP

#if FUSE_IS_DOCUMENTATION
# define FUSE_SEPARATE_COMPILATION 1
// When generating the API documentation, we simply assume that all C++
// features are usable.
// Note: Don't define platform-identification macros here!
// TODO
#endif

#define FUSE_NS_BEGIN namespace fuse {
#define FUSE_NS_END }

// Default to a header-only implementation. The user must specifically request
// separate compilation by defining either FUSE_SEPARATE_COMPILATION or
// FUSE_DYN_LINK (as a DLL/shared library implies separate compilation).
#if !defined(FUSE_HEADER_ONLY)
# if !defined(FUSE_SEPARATE_COMPILATION)
#  if !defined(FUSE_DYN_LINK)
#   define FUSE_HEADER_ONLY 1
#  endif
# endif
#endif

#if defined(FUSE_HEADER_ONLY)
// Define as |inline| so multiple copies of our functions are discarded.
# define FUSE_DECL inline
#else
# if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__CODEGEARC__)
#  if defined(FUSE_DYN_LINK)
#   if defined(FUSE_SOURCE)
#    define FUSE_DECL __declspec(dllexport)
#   else
#    define FUSE_DECL __declspec(dllimport)
#   endif
#  endif
# endif
#endif

#if !defined(FUSE_DECL)
# define FUSE_DECL
#endif

// Support for '#pragma once'
#if !defined(FUSE_HAS_PRAGMA_ONCE)
# if !defined(FUSE_DISABLE_PRAGMA_ONCE)
#  if defined(__clang__)
#   define FUSE_HAS_PRAGMA_ONCE 1
#  endif
#  if defined(__GNUC__)
#   if ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 4)) || (__GNUC__ > 3)
// GCC supports it, but recent versions(?) seem to have performance
// penalties associated with this: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=58770
//#    define FUSE_HAS_PRAGMA_ONCE 1
#   endif
#  endif
#  if defined(FUSE_MSVC) && (_MSC_VER >= 1020)
#   define FUSE_HAS_PRAGMA_ONCE 1
#  endif
# endif
#endif

FUSE_NS_BEGIN

typedef uint16_t length_type;

FUSE_NS_END

#endif
