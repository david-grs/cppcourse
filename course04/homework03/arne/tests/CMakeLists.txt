cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(homework03-unique_ptr_int-test unique_ptr_int_test.cc)
target_link_libraries(homework03-unique_ptr_int-test ${GTEST_LIBRARIES} pthread unique_ptr_int)
