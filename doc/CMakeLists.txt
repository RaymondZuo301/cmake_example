include(DoxygenProcess)

add_doxygen_doc(
  BUILD_DIR
    ${PROJECT_BINARY_DIR}/doc_gen
  DOXY_FILE
    Doxyfile.in
  TARGET_NAME
    doc
  )
