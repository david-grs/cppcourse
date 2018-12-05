cmake_minimum_required(VERSION 2.8)

set(sources
	main.cc
	vector.h
)

add_executable(main ${sources})

target_compile_options(main PRIVATE -Wall -Wextra -pedantic -Werror)
