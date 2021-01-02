cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/googletest
                 ${CMAKE_BINARY_DIR}/3rdparty/googletest)

enable_testing()
add_executable(platformer_test platformer_test.cpp)
target_link_libraries(platformer_test gtest_main platformer)
add_test(platformer_test platformer_test --gtest_color=yes)
