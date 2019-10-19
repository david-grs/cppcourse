cmake_minimum_required(VERSION 3.1)

include(gtest.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -Wextra")
add_executable(main main.cc)
add_executable(raii raii.cc)

find_package(Boost 1.58 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package (Threads)
target_link_libraries(main
	gtest
	${CMAKE_THREAD_LIBS_INIT}
	${Boost_LIBRARIES}
)
add_test(main main)

