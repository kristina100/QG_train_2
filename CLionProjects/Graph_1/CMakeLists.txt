cmake_minimum_required(VERSION 3.20)
project(Graph_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph_1 main.cpp
        ALGraph.cpp
        MGraph.cpp
        MGraph.h
        Common.h
        ALGraph.h
        Graph.h)
