cmake_minimum_required(VERSION 3.1)

ADD_SUBDIRECTORY (gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

project (shankarvasudevan)

add_executable(sorted_array_tests src/sorted_array_tests.cc src/sorted_array.cc src/sorted_array.h)
target_link_libraries(sorted_array_tests gtest gtest_main)
add_test(sorted_array_tests sorted_array_tests)

add_executable(main src/main.cc src/sorted_array.cc src/sorted_array.h)
