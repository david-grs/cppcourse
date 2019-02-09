cmake_minimum_required(VERSION 2.8)

set(sources
	main.cc
	SlidingWindow.h
        Buffer.h
)

add_executable(main ${sources})
