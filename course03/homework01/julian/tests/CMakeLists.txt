include(gtest.cmake)

set(sources tests.cc)

add_executable(tests ${sources})

find_package(Boost 1.58 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package (Threads)
target_link_libraries(tests
        hw2_lib
        gtest
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_LIBRARIES}
        )
add_test(tests tests)
