cmake_minimum_required(VERSION 3.0.0)
project(SDL2 CXX)

add_subdirectory(3rdparty/sdl)
add_subdirectory(test)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_library(platformer ${SOURCES})
target_include_directories(platformer PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
