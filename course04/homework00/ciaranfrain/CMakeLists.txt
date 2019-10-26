cmake_minimum_required (VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra -pedantic")
project (SortedArray)
add_executable(SortedArray main.cpp sorted_array.cpp sorted_array_tests.cpp)
