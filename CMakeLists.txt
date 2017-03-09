cmake_minimum_required(VERSION 3.6)
project(IR_DROP)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Net.h Net.cpp SolvingOneRow.cpp)
add_executable(IR_DROP ${SOURCE_FILES})