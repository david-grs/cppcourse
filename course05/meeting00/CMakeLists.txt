cmake_minimum_required(VERSION 3.1)

# Would you normally default CMAKE_EXPORT_COMPILE_COMMANDS to on? And is this the way to do it?
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Would you normally set the C++ standard in this way? I can imagine it can help CMake to know it's compiling for C++14?
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Same for Debug? And again would you normally set this in this config?
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(main main.cc)
