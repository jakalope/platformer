cmake_minimum_required(VERSION 3.0.0)
project(platformer CXX)

set (CMAKE_CXX_STANDARD 11)

include_directories(3dparty/sdl/include)
add_subdirectory(3rdparty/sdl EXCLUDE_FROM_ALL)

add_library(platformer
    src/graphics.cpp
    src/platformer.cpp
    src/point.cpp
)
target_link_libraries(platformer SDL2)
target_include_directories(platformer PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

enable_testing()
add_subdirectory(test)
