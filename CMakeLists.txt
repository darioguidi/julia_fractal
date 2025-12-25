cmake_minimum_required(VERSION 3.10)

project("Julia Fractal" C)

add_executable(julia main.c utility.c function.c)

find_package(SDL2 REQUIRED)

target_link_libraries(julia SDL2::SDL2)
target_link_libraries(julia m)

target_include_directories(julia PRIVATE .)