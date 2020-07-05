cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(string_tests string.h string.cc string_tests.cc)

