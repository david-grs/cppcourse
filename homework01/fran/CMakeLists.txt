set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14")

add_executable(vector vector.h vector.cc vector_tests.cc)
