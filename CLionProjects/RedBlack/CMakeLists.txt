cmake_minimum_required(VERSION 3.20)
project(RedBlack C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlack main.c
        BalancedBinaryTree.c
        BinarySearchTree.c
        RedBlackTree.c
        RedBlackTreeUtils.c
        define.h
        Function.h)
