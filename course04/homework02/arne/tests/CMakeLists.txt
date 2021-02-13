cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(homework02-linked_list-test linked_list_test.cc)
target_link_libraries(homework02-linked_list-test ${GTEST_LIBRARIES} pthread linked_list)
