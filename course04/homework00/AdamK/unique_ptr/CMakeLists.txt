cmake_minimum_required(VERSION 3.10)

find_package(gtest)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")

include_directories("uniqueptr")
add_subdirectory("uniqueptr")

add_executable(unique_ptr_test unique_ptr_test.cc)
target_link_libraries (unique_ptr_test
	gtest
	uniqueptr
	${GTEST_LIBRARIES}
	pthread)
add_test(unique_ptr_test unique_ptr_test)
