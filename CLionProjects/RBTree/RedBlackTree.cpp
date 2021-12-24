//
// Created by HUAWEI on 2021-12-04.
//
#include <cstdio>
#include <cstdlib>

//#include "../HeaderFiles/BinarySearchTree.h"
//#include "../HeaderFiles/BinaryTree.h"

#include "define.h"

/**
 * 销毁二叉树
 *
 * @param[in]  tree  the node of the binary tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status destroyBinaryTree(RBTree tree)
{
    if (!tree) return FAILED;

    if (tree->left) destroyBinaryTree(tree->left);
    if (tree->right) destroyBinaryTree(tree->right);

    free(tree);

    return SUCCESS;
}

/**
 * 前序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status preorderBiTree(RBTree tree)
{
    if (!tree) return FAILED;
    else {
        printf("%d ", tree->data);
        preorderBiTree(tree->left);
        preorderBiTree(tree->right);
    }

    return SUCCESS;
}

/**
 * 中序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status inorderBiTree(RBTree tree)
{
    if (!tree) return FAILED;
    else {
        inorderBiTree(tree->left);
        printf("%d ", tree->data);
        inorderBiTree(tree->right);
    }

    return SUCCESS;
}

/**
 * 后序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status postorderBiTree(RBTree tree)
{
    if (!tree) return FAILED;
    else {
        postorderBiTree(tree->left);
        postorderBiTree(tree->right);
        printf("%d ", tree->data);
    }

    return SUCCESS;
}

/**
 * 递归查找二叉树tree中数据域为x的结点
 *
 * @param[in]  tree: the node of the binary tree
 * @param[in]  x   : the data of the node
 * @return  the target node
 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x)
{
    if (!tree || tree->data == x) return tree;
    else if (tree->data > x) return recursiveSearchNode(tree->left, x);
    else return recursiveSearchNode(tree->right, x);
}

