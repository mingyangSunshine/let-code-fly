cmake_minimum_required(VERSION 3.7)

message("current directory: ${CMAKE_CURRENT_SOURCE_DIR}")

set(GTEST_INCLUDE_DIRS "../../lib")
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++11)

add_executable(solution_test solution_test.cpp)
