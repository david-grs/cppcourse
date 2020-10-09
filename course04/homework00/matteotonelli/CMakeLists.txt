cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests.cc ordered_array.h ordered_array.cc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(main
    main.cc
    ordered_array.h
    ordered_array.cc
    single_linked_list.cc
    single_linked_list.h
    unique_ptr_int.h
    unique_ptr_int.cc
)
