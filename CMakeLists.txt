# <CMake版本>
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# <工程配置>
project(ray_math
  LANGUAGES CXX
  VERSION 1.0.0
  )

# <构建类型>
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# <C++标准>
set(CMAKE_CXX_STANDARD 11)          # c++标准
set(CMAKE_CXX_EXTENSIONS OFF)       # 只启用ISO C++标准的编译器标志，而不使用特定编译器的扩展
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 语言标准是否必须
                                    # ON:如果此版本不可用，CMake将报错
                                    # OFF:如果此版本不可用,CMake将查找标准的下一个版本
                                    #     c++17->c++14->c++11->c++98

# <添加自定义cmake模块>
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# <构建类型>
# ON:构建动态库, OFF:构建静态库
option(BUILD_SHARED "Build shared library" ON)

# <全局变量>
set(NAMESPACE            ray)       # 命名空间
set(CMAKEFILE_PREFIX     RayMath)   # .cmake前缀，<Namesoace><Packagename>

# <打包>
  # 命令：cpack --config CPackConfig.cmake
include(CPackProcess)

# <安装>
# 安装：sudo dpkg -i xxx.deb
# 解压：dpkg -x xxx.deb <dir>

# 安装路径
#set(CMAKE_INSTALL_PREFIX /usr/local)                   # 系统目录
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)  # 构建目录

include(InstallProcess)
setup_output()
setup_install()
setup_uninstall()

# <构建>
add_subdirectory(doc)                           # 文档
add_subdirectory(3rdparty)                      # 第三方库
add_subdirectory(include)                       # 头文件
add_subdirectory(src)                           # 源文件

option(BUILD_TOOL "Build tools" ON)
if(BUILD_TOOL)
    add_subdirectory(tool)                      # 工具
endif()

option(BUILD_EXAMPLE "Build examples" ON)
if(BUILD_EXAMPLE)
    add_subdirectory(example)                   # 例程
endif()

# <测试>
    # 命令：make CTEST_OUTPUT_ON_FAILURE=1 test
    #      ctest -V
option(BUILD_TEST "Build test" ON)
if(BUILD_TEST)
    include(GtestProcess)
    setup_gtest()
    enable_testing()
    add_subdirectory(test)                      # 测试
endif()
