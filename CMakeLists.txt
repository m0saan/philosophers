cmake_minimum_required(VERSION 3.19)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(Philosophers philosophers.c philosophers.h main.c)