cmake_minimum_required(VERSION 3.1)

project(skeleton_ivo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(string_tests 
	string_tests.cc 
	string.cc
	string.h)

