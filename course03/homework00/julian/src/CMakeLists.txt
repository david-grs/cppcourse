set(LIBRARY_NAME hw1)

add_executable(${LIBRARY_NAME} date.h date.cc test.cc)

target_include_directories(${LIBRARY_NAME} PUBLIC .)
