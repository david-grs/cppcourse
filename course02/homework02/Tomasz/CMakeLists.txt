cmake_minimum_required(VERSION 2.8)

set(sources
	main.cc
	message_throttler.hpp
	message_throttler_interface.hpp
	short_circular_buffer.hpp
)

add_executable(main ${sources})

