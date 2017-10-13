cmake_minimum_required(VERSION 3.8)
project(Sample_Project_Matrix)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h)
add_executable(Sample_Project_Matrix ${SOURCE_FILES})