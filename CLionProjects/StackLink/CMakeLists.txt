cmake_minimum_required(VERSION 3.20)
project(StackLink C)

set(CMAKE_C_STANDARD 99)

add_executable(StackLink main.c Common.h StackLink.h LinkStack.c)
