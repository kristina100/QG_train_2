cmake_minimum_required(VERSION 3.20)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(SqSack main.c Common.h SqStack.c SqStack.h)
