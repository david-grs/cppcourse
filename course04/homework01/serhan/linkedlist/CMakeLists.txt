cmake_minimum_required(VERSION 3.1)
project(linkedlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

add_subdirectory(googletest/googletest)

include_directories(googletest/googletest/include)

add_executable(linkedlist main.cc linked_list.cc tests.cc)

#add_executable(unit_tests linked_list.cc  tests.cc)
#add_test(unit_tests unit_tests)
#target_link_libraries(unit_tests gtest)
