cmake_minimum_required(VERSION 3.21)
project(Elements)

set(CMAKE_CXX_STANDARD 14)

add_executable(Elements main.cpp Node.cpp Node.h Vector.cpp Vector.h Body.cpp Body.h Physics.cpp Physics.h Quadtree.cpp Quadtree.h barnes-hut.cpp barnes-hut.h memory.cpp memory.h python_interface.cpp)
