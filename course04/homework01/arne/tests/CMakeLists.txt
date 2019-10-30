cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(homework01-array-test gtest.cc)
target_link_libraries(homework01-array-test ${GTEST_LIBRARIES} pthread sarray)
