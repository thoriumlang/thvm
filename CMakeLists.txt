cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(This thvm)

project(${This} CXX)

enable_testing()

add_subdirectory(extern/googletest)

add_subdirectory(src/main)
add_subdirectory(src/test)