cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/googletest
                 ${CMAKE_BINARY_DIR}/3rdparty/googletest)

macro(declare_test)
    add_executable(${ARGV0}_test ${ARGV0}_test.cpp)
    include_directories(${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${ARGV0}_test gtest_main platformer)
    add_test(${ARGV0}_test
        COMMAND ${CMAKE_BINARY_DIR}/test/${ARGV0}_test --gtest_color=yes)
endmacro()

declare_test(platformer)
declare_test(point)
