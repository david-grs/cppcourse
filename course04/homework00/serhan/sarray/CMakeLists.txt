cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

set(headers sarray.h)

set(code sarray.cc)

set(unit_test sarray_test.cc)

add_library(
        sorted_array_lib
        sarray.cc)

add_executable(sorted_array main.cc)

target_link_libraries (
        sorted_array
        sorted_array_lib)

add_subdirectory(gtest)
add_subdirectory(gmock)

add_executable(tests ${unit_test})

target_link_libraries(tests
        gtest_main
        gtest
        gmock
        )

add_test(tests tests . --gtest_output=xml:${CMAKE_BINARY_DIR}/unit_tests_results/)