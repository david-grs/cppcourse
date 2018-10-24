set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14")

add_executable(smart_ptr
    shared_ptr.h shared_ptr.cc
    unique_ptr.h unique_ptr.cc
    tests.cc)
