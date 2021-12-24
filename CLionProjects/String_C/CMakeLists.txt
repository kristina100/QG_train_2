cmake_minimum_required(VERSION 3.20)
project(String_C C)

set(CMAKE_C_STANDARD 99)

add_executable(String_C
        main.c
        string.c
        Common.h
        string.h)
