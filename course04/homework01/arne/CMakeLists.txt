cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

include_directories("sarray")
add_subdirectory("sarray")
add_subdirectory("tests")

add_executable(homework01-array main.cc)
target_link_libraries(homework01-array sarray)
