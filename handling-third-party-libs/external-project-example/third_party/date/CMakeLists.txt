cmake_minimum_required(VERSION 3.14)

# make the ExternalProject commands available
include(ExternalProject)

# date version
# the tagged version has not updated version in CMakeLists.txt, thus we use a specific commit
set(date_VERSION 3.0.0)

# download, configure, build and install the dependency
# note: The install location is set to the build folder
ExternalProject_Add(
        date
        GIT_REPOSITORY https://github.com/HowardHinnant/date.git
        GIT_TAG        bf79dd5a810a1c6afd57d708f5e91597c05d584e
        GIT_PROGRESS TRUE
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install -DCMAKE_BUILD_TYPE=Debug)