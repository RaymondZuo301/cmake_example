add_test(
  NAME example_config
  COMMAND
    ${CMAKE_COMMAND} -H${CMAKE_CURRENT_LIST_DIR}/test_external_build
                     -B${CMAKE_CURRENT_BINARY_DIR}/test_external_build_dir
                     -G${CMAKE_GENERATOR}
                     -DRayMath_DIR=${CMAKE_INSTALL_PREFIX}/${INSTALL_CMAKEDIR}
                     -DCMAKE_BUILD_TYPE=$<CONFIGURATION>
  )

add_test(
  NAME example_build
  COMMAND
    ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/test_external_build_dir
                     --config $<CONFIGURATION>
  )

add_test(
  NAME example_cleanup
  COMMAND
    ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/test_external_build_dir
  )
