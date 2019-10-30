cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

include_directories("linked_list")
add_subdirectory("linked_list")
add_subdirectory("tests")

add_executable(homework02-linked_list main.cc)
target_link_libraries(homework02-linked_list linked_list)
