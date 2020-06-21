cmake_minimum_required(VERSION 3.5)

project(StackString)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")
add_executable(stack_string_tests stack_string_tests.cc stack_string.h stack_string.cc)

