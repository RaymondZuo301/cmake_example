set(test_name test_math)

list(APPEND all_dir
  core
  calculator
  )

foreach(_dir ${all_dir})
    file(GLOB _inc ${CMAKE_CURRENT_SOURCE_DIR}/${_dir}/*.h)
    list(APPEND include_file ${_inc})
endforeach()

add_executable(${test_name} "")

target_sources(${test_name}
  PRIVATE
    ${test_name}.cpp
    ${include_file}
  )

target_include_directories(${test_name}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
  )

target_link_libraries(${test_name}
  PRIVATE
    math
    gtest
    gtest_main
    pthread
  )

add_test(
  NAME ${test_name}
  COMMAND ${test_name}
)

