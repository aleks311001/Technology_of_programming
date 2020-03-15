cmake_minimum_required(VERSION 3.1)
project(libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../lib)

add_library(mylib SHARED lib.h lib.cpp)
