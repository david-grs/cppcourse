cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++17)

set(sources
	main.cpp
	sliding_window.h
	sliding_window.cpp
	throttler.h
	throttler.cpp
)

add_executable(main ${sources})

