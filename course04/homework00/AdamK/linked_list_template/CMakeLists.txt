cmake_minimum_required(VERSION 3.10)

find_package(gtest)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")

add_executable(linked_list_test linked_list_test.cc linkedlist.h)
target_link_libraries (linked_list_test
	gtest
	${GTEST_LIBRARIES}
	pthread)
add_test(linked_list_test linked_list_test)
