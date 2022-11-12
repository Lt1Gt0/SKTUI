include(GNUInstallDirs)
install (TARGETS terminal
    EXPORT sktui-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(sktui-config.cmake.in 
    ${CMAKE_CURRENT_BINARY_DIR}/sktui-config.cmake 
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/sktui/cmake 
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

write_basic_package_version_file(
    sktui-config-version.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/sktui-config.cmake 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sktui
)

install(EXPORT sktui-export
    FILE sktui-config-version.cmake
    NAMESPACE sktui::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sktui
)
