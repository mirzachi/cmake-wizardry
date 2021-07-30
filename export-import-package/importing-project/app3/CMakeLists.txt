cmake_minimum_required(VERSION 3.14)
project(
        app3
        VERSION 1.0.0
        DESCRIPTION "Imports and links against targets from lib3"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find lib1 library and import its CMake targets
find_package(lib3 3.0.0 EXACT REQUIRED)
message(STATUS "Found lib3: ${lib3_FOUND}")

set(TARGET "app3")

add_executable(${TARGET})

target_sources(${TARGET} PRIVATE main.cpp)

target_link_libraries(${TARGET} PRIVATE MY_ALIASED_LIB::MY_ALIASED_LIB)
