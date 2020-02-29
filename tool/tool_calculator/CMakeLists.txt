set(target_name tool_calculator)

file(GLOB src_file ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${target_name} "")

target_sources(${target_name}
  PRIVATE
    ${src_file}
  )

target_link_libraries(${target_name}
  PUBLIC
    math
  )

set_target_properties(${target_name}
  PROPERTIES
    SKIP_BUILD_RPATH OFF                # OFF：在构建时为可执行文件生成适当的RPATH（ON则不生成）
    INSTALL_RPATH "${rpath}"            # 设置RPATH为预设变量
    INSTALL_RPATH_USE_LINK_PATH ON      # ON：将链接器搜索路径添加到可执行文件的RPATH中
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
  RUNTIME
    DESTINATION ${INSTALL_BINDIR}
    COMPONENT bin
  )



