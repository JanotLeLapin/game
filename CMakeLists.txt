cmake_minimum_required(VERSION 3.10)
project(game)

include_directories(${CMAKE_SOURCE_DIR})
file(GLOB_RECURSE SRCS ${CMAKE_SOURCE_DIR}/src/*.c)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(game ${SRCS})
target_link_libraries(game ${CURSES_LIBRARIES})