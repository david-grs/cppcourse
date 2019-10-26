# CMake Settings
cmake_minimum_required (VERSION 3.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra -pedantic")

# GTest Settings
add_subdirectory(x_gtest)
enable_testing()
include_directories(x_gtest/googletest/include)

# Project Settings
project (SortedArray)
add_executable(SortedArray src/main.cpp src/sorted_array.cpp)

add_executable(SortedArrayTests src/sorted_array.cpp tests/tests.cpp)
add_test(SortedArrayTests SortedArrayTests)
target_link_libraries(SortedArrayTests gtest)
