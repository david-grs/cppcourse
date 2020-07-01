cmake_minimum_required(VERSION 3.1)
find_package(Boost REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(main main.cpp)

