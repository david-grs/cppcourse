cmake_minimum_required (VERSION 2.6)
project (SortedArray)
file(GLOB SortedArraySources "*.h" "*.cpp")
add_executable(SortedArray ${SortedArraySources})
