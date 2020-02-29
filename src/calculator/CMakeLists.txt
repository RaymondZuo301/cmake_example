file(GLOB _src_file     ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(_target_name calculator)

# <<< build shared library >>>
if(BUILD_SHARED)
    add_library(${_target_name} SHARED "")
else()
    add_library(${_target_name} STATIC "")
endif()

    target_sources(${_target_name}
      PRIVATE
        ${_src_file}
      )

    target_include_directories(${_target_name}
      PUBLIC
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
      )

    #target_link_libraries(${_target_name}
    #  PUBLIC
    #    <Add your libs>
    #  )

    set_target_properties(${_target_name}
      PROPERTIES
        POSITION_INDEPENDENT_CODE 1
        SOVERSION ${PROJECT_VERSION}
        OUTPUT_NAME ${_target_name}
        DEBUG_POSTFIX "_d"
      )

    target_compile_options(${_target_name}
      PRIVATE
        -std=c++11
      )

    install(
      TARGETS
        ${_target_name}
      EXPORT
        ${CMAKEFILE_PREFIX}Targets
      LIBRARY
        DESTINATION ${INSTALL_LIBDIR}
        COMPONENT lib
      )



