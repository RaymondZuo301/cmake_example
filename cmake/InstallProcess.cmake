include(GNUInstallDirs)

macro(setup_output)
    # 配置本地 .so/.a 和 bin的输出目录
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
endmacro()

macro(setup_install)
    # 安装目录可配置项
    set(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR} CACHE PATH "Installation dir for libs")
    set(INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR} CACHE PATH "Installation dir for exe")
    set(INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR} CACHE PATH "Installation dir for header")
    if(WIN32 AND NOT CYGWIN)
      set(DEF_INSTALL_CMAKEDIR CMake)
    else()
      set(DEF_INSTALL_CMAKEDIR share/${PROJECT_NAME})
    endif()
    set(INSTALL_CMAKEDIR ${DEF_INSTALL_CMAKEDIR} CACHE PATH "Installation dir for .cmake")

    # 打印安装目录
    foreach(p LIB BIN INCLUDE CMAKE)
      file(TO_NATIVE_PATH ${CMAKE_INSTALL_PREFIX}/${INSTALL_${p}DIR} _path )
      message(STATUS "Installing ${p} components to ${_path}")
      unset(_path)
    endforeach()

    # 生成ConfigVersion.cmake
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
      ${CMAKE_CURRENT_BINARY_DIR}/${CMAKEFILE_PREFIX}ConfigVersion.cmake
      VERSION ${PROJECT_VERSION}
      COMPATIBILITY SameMajorVersion
      )

    # 生成Config.cmake
    configure_package_config_file(
      ${PROJECT_SOURCE_DIR}/${CMAKEFILE_PREFIX}Config.cmake.in
      ${CMAKE_CURRENT_BINARY_DIR}/${CMAKEFILE_PREFIX}Config.cmake
      INSTALL_DESTINATION ${INSTALL_CMAKEDIR}
      )

    # 安装ConfigVersion.cmake/Config.cmake
    install(
      FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKEFILE_PREFIX}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKEFILE_PREFIX}ConfigVersion.cmake
      DESTINATION
        ${INSTALL_CMAKEDIR}
      )

    # 安装Targets.cmake
    install(
      EXPORT
        ${CMAKEFILE_PREFIX}Targets
      NAMESPACE
        "${NAMESPACE}::"
      DESTINATION
        ${INSTALL_CMAKEDIR}
      COMPONENT
        dev
      )
endmacro()

macro(setup_uninstall)
    configure_file("${PROJECT_SOURCE_DIR}/cmake/uninstall.cmake.in" "${PROJECT_BINARY_DIR}/uninstall.cmake" IMMEDIATE @ONLY)
    add_custom_target(uninstall_${PROJECT_NAME} "${CMAKE_COMMAND}" -P "${PROJECT_BINARY_DIR}/uninstall.cmake")
endmacro()
