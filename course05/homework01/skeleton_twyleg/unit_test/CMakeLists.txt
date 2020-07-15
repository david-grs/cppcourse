cmake_minimum_required(VERSION 3.1)


add_executable(test_string
	main.cc
	test_string.cc
)

target_link_libraries(test_string
	lib_string
	gtest
)

