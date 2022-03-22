cmake_minimum_required(VERSION 3.21)
project(barnes_hut_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(barnes_hut_cpp main.cpp system.cpp headers.h structures.cpp quadtree.cpp physics.cpp)
