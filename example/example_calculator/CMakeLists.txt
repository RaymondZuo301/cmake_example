set(target_name example_calculator)

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

target_compile_options(${target_name}
  PRIVATE
    -std=c++11
  )
