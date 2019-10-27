cmake_minimum_required(VERSION 3.10)

find_package(gtest)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")

include_directories("sortedarray")
add_subdirectory("sortedarray")

add_executable(array_test array_test.cc)
target_link_libraries (array_test
	gtest
	sortedarray
	${GTEST_LIBRARIES}
	pthread)
add_test(array_test array_test)
