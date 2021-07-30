set(TARGET "lib4")
set(TARGET_PACKAGE_NAME "${TARGET}")
set(TARGET_VERSION "4.0.0")

# Import targets from lib1
find_package(lib1 1.0.0 EXACT REQUIRED CONFIG)

add_library(${TARGET} STATIC)

target_sources(${TARGET} PUBLIC
               PRIVATE src/lib4/lib4.cpp)

target_include_directories(${TARGET}
                           PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           PUBLIC "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
                           )

target_link_libraries(${TARGET} PUBLIC lib1::lib1)

install(
        TARGETS ${TARGET}
        EXPORT ${TARGET_PACKAGE_NAME}Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/lib4" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# Create a basic config version file. TARGET_VERSION is encoded within this file. find_package from an outside project
# checks this file for a package version. The created file has to be located in the same folder as the config file
# in the install or build tree. One config version file is sufficient for the entire project. Always match the
# entire requested version
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}/${TARGET_PACKAGE_NAME}ConfigVersion.cmake"
        VERSION ${TARGET_VERSION}
        COMPATIBILITY ExactVersion)

# Copy configurable manually written config file to the same directory as version and targets files
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/${TARGET_PACKAGE_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}/${TARGET_PACKAGE_NAME}Config.cmake"
                              INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${TARGET_PACKAGE_NAME}
                              )

# INSTALL TREE VERSION EXPORT TARGETS!!!
# Installs a CMake target files containing code to import targets from the
# install tree into another project. Target installations are associated with the export using the EXPORT
# option of the install(TARGETS).
install(
        EXPORT ${TARGET_PACKAGE_NAME}Targets
        FILE ${TARGET_PACKAGE_NAME}Targets.cmake
        NAMESPACE ${TARGET_PACKAGE_NAME}::
        DESTINATION lib/cmake/${TARGET_PACKAGE_NAME})

# Install config and version files in the install tree
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}/${TARGET_PACKAGE_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_PACKAGE_NAME}/${TARGET_PACKAGE_NAME}ConfigVersion.cmake DESTINATION lib/cmake/${TARGET_PACKAGE_NAME})
