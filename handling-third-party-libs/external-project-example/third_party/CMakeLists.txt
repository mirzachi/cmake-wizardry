cmake_minimum_required(VERSION 3.14)
project(
        third-party-libraries
        VERSION 1.0.0
        DESCRIPTION "Download, build and install third party libraries locally"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(date)
