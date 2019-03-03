cmake_minimum_required(VERSION 3.0)
project(homework)

set(CMAKE_CXX_STANDARD 17)

if (NOT DEFINED CINDER_PATH)
    message(FATAL_ERROR "CINDER_PATH not set, e.g. -DCINDER_PATH=~/src/cinder")
endif()
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(cxx_compile_options "-g -Wall -Wextra")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxx_compile_options}")

file(GLOB asteroids
        "*.h"
        "*.cc"
        )

set(SOURCES ${asteroids})

ci_make_app(
        APP_NAME    "asteroids"
        SOURCES     ${SOURCES}
        INCLUDES    ${CMAKE_CURRENT_SOURCE_DIR}
        CINDER_PATH ${CINDER_PATH}
)