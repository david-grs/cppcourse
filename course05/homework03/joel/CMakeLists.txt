cmake_minimum_required(VERSION 3.1)
find_package(Boost REQUIRED)

# set up tests
add_subdirectory("${PROJECT_SOURCE_DIR}/googletest" "googletest")
enable_testing()
include(GoogleTest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
add_executable(main main.cpp)
add_executable(tests tests.cpp)

target_link_libraries(tests gtest gtest_main)

add_test(tests tests)
