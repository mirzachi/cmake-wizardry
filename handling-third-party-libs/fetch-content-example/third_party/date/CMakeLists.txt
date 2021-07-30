# in order to use FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)

# include FetchContent CMake module
include(FetchContent)

# enable seeing GIT clone progress
set(FETCHCONTENT_QUIET FALSE)

# date version
# we use a specific commit after this version, because it modernizes its CMake script
set(date_VERSION 3.0.0)

# configure fetch date
FetchContent_Declare(
        date
        GIT_REPOSITORY https://github.com/HowardHinnant/date.git
        GIT_TAG 77bd6b92a4f7f6a1bbbc44952e6502a3448376b0
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(date)

# add library name aliases
add_library(MyPrefix::date ALIAS date)