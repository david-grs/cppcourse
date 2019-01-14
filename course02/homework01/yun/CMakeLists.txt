cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

set(sources
	main.cc
	linkedlist.h
    	linkedlist.cpp
)

add_executable(main ${sources})
