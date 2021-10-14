cmake_minimum_required(VERSION 3.14)
project(
        example-1
        VERSION 1.0.0
        DESCRIPTION "Adding preprocessor definitions with CMake"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

OPTION(ENABLE_MY_FLAG "Enable preprocessor definition MY_FLAG" OFF) # Disabled by default


add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE main.cpp)

if (ENABLE_MY_FLAG)
    # Defines the flag for the specific target
    # target_compile_definitions(${PROJECT_NAME} PRIVATE MY_FLAG)

    # Defines the flag for all source files
    add_compile_definitions(MY_FLAG)
endif ()



