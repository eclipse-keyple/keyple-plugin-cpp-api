# Keyple Plugin C++ API

## Overview

The **Keyple Plugin** C++ API is dedicated to the development of specific **Keyple plugins**.

This library **should not be imported explicitly** by the main application.

## User Guide & Download Information

The full documentation, including download information is available in the **Documentation** section of the official Keyple website [keyple.org](https://keyple.org)

## Doxygen

The doxygen is available online: [docs.keyple.org/keyple-plugin-cpp-api/](https://docs.keyple.org/keyple-plugin-cpp-api/)

## Build the Code

The code is built with **CLang / GCC / MSVC** in order to be able to be used by a very large number of applications.

### Building with Conan

This repository is packaged as a [Conan](https://conan.io/) recipe (`conanfile.py`), providing the `Keyple::Plugin`
CMake target as `keyple-plugin-cpp-api`. It requires `keyple-util-cpp-lib/2.4.1` (declared with
`transitive_headers=True`, since this API's public headers include Keyple Util headers directly), resolved via Conan
instead of `FetchContent`. Downstream keyple recipes should consume this package the same way, with
`self.requires("keyple-plugin-cpp-api/2.3.2")`.

The unit test suite is opt-in via the `with_tests` option (default `False`), so consumers of the package don't pay
for compiling GoogleTest.

#### Local development

Use `conan build` to configure/compile in-tree, in a regular `build/` folder you can inspect, rerun and debug
against (and which generates a `CMakeUserPresets.json` for IDE integration). The build type defaults to `Release`;
pass `-s build_type=Debug` for a debug build, which lands in its own `build/Debug` subfolder alongside `build/Release`:

```bash
# Release build, with the unit test suite, under ./build/Release
conan build . -o with_tests=True --build=missing

# Debug build, under ./build/Debug
conan build . -o with_tests=True -s build_type=Debug --build=missing

# Re-run the tests directly afterwards
./build/Release/bin/keypleplugincppapi_ut
./build/Debug/bin/keypleplugincppapi_ut
```

#### Packaging to the local cache

Use `conan create` to export the recipe and package to your local Conan cache, for consumption by other
recipes/repos (no remote upload involved):

```bash
# Build and export the package to the local cache
conan create . --build=missing

# Same, but also build and run the unit test suite as part of the recipe build
conan create . -o with_tests=True --build=missing

# Package a Debug build instead (build_type defaults to Release)
conan create . -o with_tests=True -s build_type=Debug --build=missing
```

### Conan profile

Builds use your default Conan profile. If you don't have one yet, create it with:

```bash
conan profile detect
```

## Code Contributions

We welcome code contributions through merge requests.
