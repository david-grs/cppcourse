cmake_minimum_required(VERSION 2.6)
project(list)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++14)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(unit_tests unit_tests.cc list.cc)

add_subdirectory(./googletest)

enable_testing()
# 
# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(./googletest/include)

# Link test executable against gtest & gtest_main
target_link_libraries(unit_tests gtest gtest_main pthread)
add_test(unit_tests unit_tests)
