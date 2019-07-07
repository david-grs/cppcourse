set(LIBRARY_NAME hw2_lib)

add_library(${LIBRARY_NAME} tuple.h linked_list.cc)

find_package(Boost 1.58 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES})

target_compile_options(${LIBRARY_NAME} PRIVATE ${cxx_compile_options})
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
