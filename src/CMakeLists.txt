set(target_name math)

list(APPEND dir
  core
  calculator
  )

foreach(_dir ${dir})
    file(GLOB     _src_file       ${CMAKE_CURRENT_SOURCE_DIR}/${_dir}/*.cpp)
    list(APPEND   src_file        ${_src_file})
endforeach()

if(BUILD_SHARED)
    add_library(${target_name} SHARED "")
else()
    add_library(${target_name} STATIC "")
endif()

target_sources(${target_name}
  PRIVATE
    ${src_file}
  )

target_include_directories(${target_name}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${INSTALL_INCLUDEDIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${INSTALL_INCLUDEDIR}>
  )

#target_link_libraries(${target_name}
#  PUBLIC
#    <Add your libs>
#  )

set_target_properties(${target_name}
  PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    SOVERSION ${PROJECT_VERSION}
    OUTPUT_NAME ${NAMESPACE}_${target_name}
    DEBUG_POSTFIX "_d"
  )

target_compile_options(${target_name}
  PRIVATE
    -std=c++11
  )

install(
  TARGETS
    ${target_name}
  EXPORT
    ${CMAKEFILE_PREFIX}Targets
  LIBRARY
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
  )



