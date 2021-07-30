cmake_minimum_required(VERSION 3.14)
project(
        fetch-content-example
        VERSION 1.0.0
        DESCRIPTION "Example on how to download and build third party sources via CMake fetch_content automatically"
        LANGUAGES CXX
)

# Enable C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(third_party)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE date::date MyPrefix::outcome)