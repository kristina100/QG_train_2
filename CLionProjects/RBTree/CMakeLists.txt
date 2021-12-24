cmake_minimum_required(VERSION 3.20)
project(RBTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(RBTree main.cpp define.h RedBlackTree.cpp RedBlackTreeUtils.cpp BalancedBinaryTree.cpp BinarySearchTree.cpp)
