cmake_minimum_required(VERSION 3.27)
project(stos2)

set(CMAKE_CXX_STANDARD 17)

add_executable(stos2 main.cpp
        stack.h
        stack.cpp)
