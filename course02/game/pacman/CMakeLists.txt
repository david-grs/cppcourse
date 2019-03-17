cmake_minimum_required(VERSION 2.8)
project(pacman)

set(CMAKE_CXX_STANDARD 14)

if (NOT DEFINED CINDER_PATH)
	message(FATAR_ERROR "CINDER_PATH not set, e.g. -DCINDER_PATH=~/Cinder")
endif()

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set(cxx_compile_options "-g -Wall -Wextra")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxx_compile_options}")

file(GLOB pacman
	"basic_field.cpp"
	"coin_field.cpp"
	"game_controller.cpp"
	"game_curtain_controller.cpp"
	"ghost_controller.cpp"
	"ghost.cpp"
	"pacman_controller.cpp"
	"pacman.cpp"
	"temporary_wall.cpp"
	"wall_field.cpp"
	"pacman_app.cpp")

set(SOURCES ${pacman})

ci_make_app(
	APP_NAME	"pacman"
	SOURCES		${SOURCES}
	INCLUDES	${CMAKE_CURRENT_SOURCE_DIR}
	CINDER_PATH	${CINDER_PATH})
