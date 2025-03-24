cmake_minimum_required(VERSION 3.25)
project(boj_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/include")

add_definitions(-DYEAHx4)

add_executable(boj_cpp main.cpp)
