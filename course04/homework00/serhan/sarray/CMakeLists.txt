set(CMAKE_C_COMPILER gcc)

cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

add_library(
        sorted_array_lib
        sarray.cc)

add_executable(sorted_array main.cc sarray.cc sarray.h)

target_link_libraries (
        sorted_array
        sorted_array_lib)