# Handling third party libraries

Complex software projects typically depend on multiple third party libraries.
Not having to reinvent the wheel increases the productivity, and thus speeds up the delivery cycles.

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
  library completely or partially by writing an own CMake script for the parts of the library of interest. *FetchContent*
  downloads during the configure phase of the main project.

## Import third party library installed from the system

If a third party library has been already installed on the system with CMake.
One can use *find_package* utility to import its targets in the current project.

## Import third party library installed in the local folder

If it is not desired to install a certain third party library system-wide since it is required only for the
current project. One can download, build and install the library in a local folder.
Then, *CMAKE_PREFIX_PATH* CMake variable can be set to point to the install tree in the local folder.
Afterwards, *find_package* utility can be used as usual.

Download, build and install can be done manually, or using *ExternalProject* CMake utility. 

* [**external-project-example**](./external-project-example) - demonstrates how to use *ExternalProject* to download,
  build and install a third party library in a local folder. *ExternalProject* downloads during the build phase of the
  third party lib project.
