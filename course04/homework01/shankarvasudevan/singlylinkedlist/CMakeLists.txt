cmake_minimum_required(VERSION 3.1)

ADD_SUBDIRECTORY (gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

project (shankarvasudevan)

add_executable(singly_linked_list_tests src/singly_linked_list_tests.cc src/singly_linked_list.cc src/singly_linked_list.h)
target_link_libraries(singly_linked_list_tests gtest gtest_main)
add_test(singly_linked_list_tests singly_linked_list_tests)

add_executable(main src/main.cc src/singly_linked_list.cc src/singly_linked_list.h src/singly_linked_list_node.h src/test_helper.cc)