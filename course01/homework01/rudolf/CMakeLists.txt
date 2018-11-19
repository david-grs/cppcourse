set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

add_executable(vector vector.h vector.cpp vector_tests.cc)
