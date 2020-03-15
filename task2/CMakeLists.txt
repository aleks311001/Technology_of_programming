cmake_minimum_required(VERSION 3.1)
project(dich)

set(CMAKE_CXX_STANDARD 17)

set(DIRECT ${PROJECT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DIRECT}/bin)
set(LIBRARY_OUTPUT_PATH ${DIRECT}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DIRECT}/lib)

add_custom_command(
	OUTPUT  ${DIRECT}/A/index.h
	COMMAND python3 ${DIRECT}/A/preparing.py
	DEPENDS ${DIRECT}/A/preparing.py
)

set(MAIN_SOURCE ${DIRECT}/C/main.cpp ${DIRECT}/A/index.h)
set(MAIN_SOURCE_TEST ${DIRECT}/C/main_test.cpp ${DIRECT}/A/index.h)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${DIRECT})

add_executable(Cmain ${MAIN_SOURCE})
add_subdirectory(${DIRECT}/B)
target_link_libraries(Cmain mylib)

add_executable(CTest ${MAIN_SOURCE_TEST})
target_link_libraries(CTest ${GTEST_LIBRARIES})
target_link_libraries(CTest pthread)
target_link_libraries(CTest mylib)

enable_testing()

add_test(Index CTest)
add_test(My_abs CTest)
