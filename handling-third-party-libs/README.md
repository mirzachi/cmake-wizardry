# Handling third party libraries

Complex software projects typically depend on multiple third party libraries.
Do not having to reinvent the wheel increases the productivity, and thus speeds up the delivery cycles.

This folder explains different approaches how one can use CMake to handle third party library dependencies and
link against them.

## Include third-party sources directly in your project

One can download the source code of a third party dependencies and integrate it via CMake directly in the project.
This might be the easiest approach if the third party library is not large and its build system is not CMake
compatible.

If the third party library supports CMake as a meta build system, and it already incorporates modern CMake techniques,
then the sources can be downloaded and build via CMake *FetchContent* utility.

Downloading and configuring of the third party library happens during the configuration phase of the main project.

* [**fetch-content-example**](./fetch-content-example) - demonstrates how to use *FetchContent* to import a third party 
  library completely or partially by writing an own CMake script for the parts of the library of interest
