cmake_minimum_required(VERSION 3.28)
project(cpp_validator)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_validator main.cpp
        testlib.h
        checker.cpp)
