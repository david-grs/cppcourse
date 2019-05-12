cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall")
add_executable(main main.cc list.h list.cc)

add_executable(test test.cc list.h list.cc)
target_link_libraries(test gtest)
