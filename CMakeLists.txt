cmake_minimum_required(VERSION 3.7)
project(tests LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_executable(converter src/CONVERTER.c src/libs/bmp.c src/libs/qdbmp.c -lm)
add_executable(comparer src/COMPARER.c src/libs/bmp.c)

