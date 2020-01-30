cmake_minimum_required(VERSION 3.7)

message("current directory: ${CMAKE_CURRENT_SOURCE_DIR}")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++11)

add_executable(solution_test solution_test.cpp)

target_link_libraries(solution_test ${GTEST_BOTH_LIBRARIES} pthread)