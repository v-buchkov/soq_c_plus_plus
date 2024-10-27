cmake_minimum_required(VERSION 3.28)
project(school_of_quants_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(school_of_quants_project main.cpp
        LinearInterpolation.cpp
        LinearInterpolation.h)
