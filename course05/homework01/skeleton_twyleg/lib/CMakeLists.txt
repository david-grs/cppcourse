cmake_minimum_required(VERSION 3.1)

set(CMAKE_INCLUDE_CURRENT_DIR·ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

add_library(lib_string
	cpp_course_string.cc
	cpp_course_string.h
)

target_include_directories(lib_string
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)


