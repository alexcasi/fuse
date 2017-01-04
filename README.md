# fuse - serialization primitives

fuse is a modular and customizable serialization library.

fuse has built-in support for serializing
Boost.Fusion [forward sequences](http://www.boost.org/doc/libs/release/libs/fusion/doc/html/fusion/sequence/concepts/forward_sequence.html),
as well as a bunch of custom types.

## Features

* Adapters for Boost.Fusion sequences
* No headers or other bookkeeping information gets serialized.

## Building

fuse is header-only by default.
However, it can also be built as a separate compilation unit.

## Library dependencies:

* Boost 1.46.0+

## Acknowledgements

fuse is inspired by Thomas Rodgers' presentation
[Implementing wire protocols with Boost Fusion](https://github.com/CppCon/CppCon2014/tree/master/Presentations/Implementing%20wire%20protocols%20with%20Boost%20Fusion).
and his subsequent [blog post](http://rodgert.github.io/2014/09/09/type-driven-wire-protocols-with-boost-fusion-pt1)

## License

Please see [LICENSE_1_0.txt](LICENSE_1_0.txt).
