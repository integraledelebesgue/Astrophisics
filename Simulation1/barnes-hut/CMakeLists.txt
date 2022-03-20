cmake_minimum_required(VERSION 3.21)
project(barnes_hut C)

set(CMAKE_C_STANDARD 99)

add_executable(barnes_hut system.c headers.h stack.c q-tree.c physics.c main.c)
