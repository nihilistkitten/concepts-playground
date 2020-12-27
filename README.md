## Introduction

A library of toy examples using C++20 concepts (written for my own education/exploration), including:

 * **animal** - A simple template which demonstrates the basic concept syntax.

## Building

Building depends on `cmake`. To build, run:

```sh
mkdir build && cd build
cmake ../
cmake --build .
```

To build an individual library, run:
```sh
cmake --build <library>
```

To run tests, run:
```sh
ctest
```

Note that C++20 concepts currently are not supported by Apple Clang (see https://en.cppreference.com/w/cpp/compiler_support), and so this code does not compile on Mac.

## License

Licensed under either of

 * Apache License, Version 2.0
   ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
 * MIT license
   ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.

## Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, as defined in the Apache-2.0 license, shall be dual licensed as above, without any additional terms or conditions.
