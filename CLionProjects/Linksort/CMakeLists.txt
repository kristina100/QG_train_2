cmake_minimum_required(VERSION 3.20)
project(Linksort C)

set(CMAKE_C_STANDARD 99)

add_executable(Linksort main.c List.c Common.h)
