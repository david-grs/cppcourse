set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14")

add_executable(main main.cc)
target_link_libraries(main pthread)
