# CMake Settings
cmake_minimum_required (VERSION 3.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra -pedantic")

# GTest Settings
add_subdirectory(x_gtest)
enable_testing()
include_directories(x_gtest/googletest/include)

# Project Settings
project (LinkedList)
add_executable(LinkedList src/main.cpp src/linked_list.cpp)

add_executable(LinkedListTest src/linked_list.cpp tests/tests.cpp)
add_test(LinkedListTest LinkedListTest)
target_link_libraries(LinkedListTest gtest)
