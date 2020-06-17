cmake_minimum_required(VERSION 3.1)

project(homework01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(string_tests
    string.cc
    string.h
    string_tests.cc
)

