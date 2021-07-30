cmake_minimum_required(VERSION 3.14)
project(
        exporting-project
        VERSION 1.0.0
        DESCRIPTION "Example on how to export properly CMake targets so that they can be imported in other projects via find_package utility"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Change default CMAKE_INSTALL_PREFIX to CMAKE_BINARY_DIR if not specified by the user
# It allows easier testing debug/release
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "CMAKE_INSTALL_PREFIX not set, using: ${CMAKE_BINARY_DIR}/install")
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_BINARY_DIR}/install"
        CACHE PATH "CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT" FORCE)
endif()

# Import GNU common install directory variables
include(GNUInstallDirs)

# Include CMake helpers for package config files Following this model:
# https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html
include(CMakePackageConfigHelpers)

add_subdirectory(lib1)

add_subdirectory(lib2)

add_subdirectory(lib3)

add_subdirectory(lib4)
