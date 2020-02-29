# 准备RPATH
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
set(_rpath "\$ORIGIN/${_rel}")
file(TO_NATIVE_PATH "${_rpath}/${INSTALL_LIBDIR}" rpath)

add_subdirectory(tool_calculator)
