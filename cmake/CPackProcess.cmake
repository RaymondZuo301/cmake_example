include (InstallRequiredSystemLibraries)
# 打包格式包括 STGZ,TGZ,DEB,TBZ2
set(CPACK_GENERATOR "DEB")                                                           # 二进制打包格式
SET(CPACK_SOURCE_GENERATOR "TBZ2")                                                   # 源码打包格式
set(CPACK_PACKAGE_NAME                 "${PROJECT_NAME}")                            # 工程名
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY  "${PROJECT_NAME}")                            # 简介
set(CPACK_PACKAGE_CONTACT              "Raymond")                                    # 联系人
set(CPACK_PACKAGE_VENDOR               "Raymond")                                    # 源
set(CPACK_PACKAGE_VERSION_MAJOR        "${PROJECT_VERSION_MAJOR}")                   # 版本MAJOR
set(CPACK_PACKAGE_VERSION_MINOR        "${PROJECT_VERSION_MINOR}")                   # 版本MINOR
set(CPACK_PACKAGE_VERSION_PATCH        "${PROJECT_VERSION_PATCH}")                   # 版本PATCH
set(CPACK_PACKAGING_INSTALL_PREFIX     "${CMAKE_INSTALL_PREFIX}")                    # 安装目录
set(CPACK_PACKAGE_DESCRIPTION_FILE     "${CMAKE_CURRENT_SOURCE_DIR}/README.md")      # 描述文件路径
set(CPACK_RESOURCE_FILE_LICENSE        "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")     # 许可文件路径
SET(CPACK_SOURCE_IGNORE_FILES          "/.git/;.user;.gitignore;/build/;~")          # 源码打包忽略规则
include(CPack)
