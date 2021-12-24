//
// Created by HUAWEI on 2021-12-06.
//
#include <stdio.h>
#include <stdlib.h>
//
//#ifndef REDBLACK_DEFINE_H
//#define REDBLACK_DEFINE_H
//
// Created by HUAWEI on 2021-12-05.
//

//#ifndef RBTREE_DEFINE_H
//#define RBTREE_DEFINE_H

// RedBlackTree.h

#define RED   0 /* 红色结点标志 */
#define BLACK 1 /* 黑色结点标志 */

//#define SUCCESS  0
//#define FAILED  -1
//#define FALSE  0
//#define TRUE  1

#define RBTreeColor(r) ((r)->color)
#define RBTreeParent(r) ((r)->parent)
#define RBTreeIsRed(r) ((r)->color == RED)
#define RBTreeIsBlack(r) ((r)->color == BLACK)
#define RBTreeSetColor(r, c) do {(r)->color = (c);} while(0)
#define RBTreeSetParent(r, p) do {(r)->parent = (p);} while(0)
#define RBTreeSetRed(r) do {(r)->color = RED;} while(0)
#define RBTreeSetBlack(r) do {(r)->color = BLACK;} while(0)

typedef int RBTreeElemType;

/* 红黑树的结点 */
typedef struct RBTreeNode {
    RBTreeElemType data;       /* 数据域 */
    char color;                /* 颜色 */
    struct RBTreeNode *left;   /* 左孩子结点 */
    struct RBTreeNode *right;  /* 右孩子结点 */
    struct RBTreeNode *parent; /* 父结点 */
} Node, *RBTree;

/* 红黑树的根结点 */
typedef struct RB_Root {
    Node *node;
} RBRoot;

//typedef int Status;

typedef enum {
    SUCCESS = 0,
    FAILED = -1
}Status;

///* 创建红黑树 */
//RBRoot *createRBTree();
//
///* 销毁红黑树 */
//Status destroyRBTree(RBRoot *root);
//
///* 前序遍历红黑树 */
//Status preorderRBTree(RBRoot *root);
//
///* 中序遍历红黑树 */
//Status inorderRBTree(RBRoot *root);
//
///* 后序遍历红黑树 */
//Status postorderRBTree(RBRoot *root);
//
///* 递归查找红黑树 */
//Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x);
//
///* 红黑树插入结点 */
//Status insertRBTree(RBRoot *root, RBTreeElemType x);
//
///* 红黑树删除结点 */
//Status deleteRBTree(RBRoot *root, RBTreeElemType x);
//
///* 打印红黑树信息 */
//Status printRBTree(RBRoot *root);
//
//
//// BalancedBinaryTree.h
///* 平衡二叉树结点左旋 */
//Status RBTreeLeftRotate(RBRoot *root, Node *node);
//
///* 平衡二叉树结点右旋 */
//Status RBTreeRightRotate(RBRoot *root, Node *node);
//
//
//
////  BinarySearchTree.h
///* 二叉查找树插入结点 */
//Status insertBinarySearchTree(RBRoot *root, Node *node);
//
///* 二叉查找树查找最小结点 */
//RBTree minBinarySearchTreeNode(RBTree tree);
//
///* 二叉查找树查找最大结点 */
//RBTree maxBinarySearchTreeNode(RBTree tree);
//
///* 二叉查找树查找前驱结点 */
//RBTree BSTreePrecursor(RBTree node);
//
///* 二叉查找树查找后继结点 */
//RBTree BSTreeSuccessor(RBTree node);
//
//
//// BinaryTree.h
//
///* 销毁二叉树 */
//Status destroyBinaryTree(RBTree tree);
//
///* 前序遍历二叉树 */
//Status preorderBiTree(RBTree tree);
//
///* 中序遍历二叉树 */
//Status inorderBiTree(RBTree tree);
//
///* 后序遍历二叉树 */
//Status postorderBiTree(RBTree tree);
//
///* 查找结点 */
//RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);
//
//
//// RedBlackTreeUtils.h
//
///* 创建红黑树结点 */
//RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right);
//
///* 红黑树插入结点后自平衡 */
//Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node);
//
///* 红黑树查找最小结点 */
//Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal);
//
///* 红黑树查找最大结点 */
//Status maxRBTreeNode(RBRoot *root, RBTreeElemType *maxVal);
//
///* 红黑树删除结点后自平衡 */
//Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent);
//
///* 红黑树删除结点指针 */
//__attribute__((unused)) Status deleteRBTreeNode(RBRoot *root, Node *node);
//
///* 红黑树信息的打印 */
//Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position);
//
///* 凹入法打印红黑树 */
//Status recessedPrintRBTree(RBTree tree, int depth);

//#endif //REDBLACK_DEFINE_H
