cmake_minimum_required(VERSION 4.3)
project(Inverted_sort_functions)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Inverted_sort_functions
        sort_functions.cxx
        sort_functions.h
        test_sort_inverse.cxx)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")