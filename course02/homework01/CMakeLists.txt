cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g")
set(sources
	main.cc
	linked_list.h
	linked_list.cc
)

add_executable(main ${sources})

