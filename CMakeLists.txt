cmake_minimum_required(VERSION 3.10)

project("Julia Fractal" C)

add_executable(julia main.c utility.c function.c)

target_include_directories(julia PRIVATE .)