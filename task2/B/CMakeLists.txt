cmake_minimum_required(VERSION 3.1)
project(libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib)

add_library(mylib SHARED lib.h lib.cpp)
