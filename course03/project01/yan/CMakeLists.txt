cmake_minimum_required(VERSION 3.1)

project(go)

set(CMAKE_CXX_STANDARD 14)

if (NOT DEFINED CINDER_PATH)
	message(FATAL_ERROR "CINDER_PATH not set, e.g. -DCINDER_PATH=~/src/cinder")
endif()
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set(cxx_compile_options "-g -Wall -Wextra")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxx_compile_options}")

set(SOURCES
        go_basic.h
        go_basic.cc
        scoring.h
        scoring.cc
	application.h
	application.cc
)

ci_make_app(
        APP_NAME    "go"
	SOURCES     ${SOURCES}
	INCLUDES    ${CMAKE_CURRENT_SOURCE_DIR}
	CINDER_PATH ${CINDER_PATH}
)


