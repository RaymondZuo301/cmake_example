cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(example
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 11)

find_package(RayMath CONFIG REQUIRED)

add_executable(example "")

target_sources(example
  PRIVATE
    main.cpp
  )

target_link_libraries(example
  PRIVATE
    ray::math
  )

