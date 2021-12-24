cmake_minimum_required(VERSION 3.20)
project(forest)

set(CMAKE_CXX_STANDARD 14)

add_executable(forest main.cpp Commn.h CSTree.cpp Queue.cpp)
