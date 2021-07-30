# in order to use FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)

# outcome version
set(OUTCOME_VERSION 2.1.4)
set(OUTCOME_INCLUDE_DIR "${CMAKE_BINARY_DIR}/${CMAKE_FOLDER}/_deps/outcome/include")

project(
        outcome
        VERSION ${OUTCOME_VERSION}
        DESCRIPTION "Header only outcome library"
        LANGUAGES CXX
)

# include FetchContent CMake module
include(FetchContent)

# enable seeing GIT clone progress
set(FETCHCONTENT_QUIET FALSE)

## Do NOT load the full project (because of further not needed dependencies that have to be
## installed manually), but only the final single-header-lib
FetchContent_Declare(
        outcome
        URL "https://raw.githubusercontent.com/ned14/outcome/v${OUTCOME_VERSION}/single-header/outcome-basic.hpp"
        DOWNLOAD_DIR
        "${OUTCOME_INCLUDE_DIR}/outcome"
        DOWNLOAD_NO_EXTRACT 1
)

# fetch and configure outcome
FetchContent_MakeAvailable(outcome)

add_library(outcome INTERFACE)

# add library name aliases
add_library(MyPrefix::outcome ALIAS outcome)

include(GNUInstallDirs)

target_include_directories(
        ${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${OUTCOME_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
        TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY ${OUTCOME_INCLUDE_DIR}/outcome DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${LIB_VERSION}
        COMPATIBILITY ExactVersion
)

configure_file(
        cmake/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake COPYONLY
)

set(ConfigPackageLocation lib/cmake/${PROJECT_NAME})

install(
        EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${ConfigPackageLocation}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${ConfigPackageLocation}
        )
