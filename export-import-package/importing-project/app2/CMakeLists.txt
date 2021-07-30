cmake_minimum_required(VERSION 3.14)
project(
        app2
        VERSION 1.0.0
        DESCRIPTION "Imports and links against targets from lib2"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find lib1 library and import its CMake targets
find_package(lib2 2.0.0 EXACT REQUIRED)
message(STATUS "Found lib2: ${lib2_FOUND}")

set(TARGET "app2")

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE main.cpp)

target_link_libraries(${TARGET} PRIVATE lib2::lib2_sublib1)
