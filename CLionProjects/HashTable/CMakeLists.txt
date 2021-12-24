cmake_minimum_required(VERSION 3.20)
project(HashTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(HashTable main.cpp CHashTable.cpp HashTable.h CHashTable.h Common.h)

