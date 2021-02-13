cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

include_directories("unique_ptr_int")
add_subdirectory("unique_ptr_int")
add_subdirectory("tests")

add_executable(homework03-unique_ptr_int main.cc)
target_link_libraries(homework03-unique_ptr_int unique_ptr_int)
