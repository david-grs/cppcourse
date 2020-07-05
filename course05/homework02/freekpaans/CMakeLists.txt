cmake_minimum_required(VERSION 3.1)

project(LinkedListHomework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic)

add_executable(linked_list_tests linked_list_tests.cc linked_list.cc linked_list.h)

add_subdirectory(gtest)
target_link_libraries(linked_list_tests gtest_main)

include(CTest)
include(GoogleTest)

gtest_discover_tests(linked_list_tests)
