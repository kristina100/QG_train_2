//
// Created by HUAWEI on 2021-11-29.
//

#ifndef B_TREE_LINKLIST_H
#define B_TREE_LINKLIST_H
/**
 * Created by gblau on 2016-12-11.
 * Copyright (c) Chung Tsing(gblau) 2016. All rights reserved.
 */

#include <cstdlib>


//最大子树数
#define M 4
#define MAXINT 100

#endif //B_TREE_LINKLIST_H


//自定义key类型
typedef int Key;

/**
 * BTree：B树的基本节点
 */
typedef struct node {
    int keyNum;
    Key keys[M+1];
    struct node *parent;
    struct node *child[M+1];

}Node, *BTree;

/**
 * ResultVo：封装查找返回的信息
 */
typedef struct result {
    BTree pt;
    int i;
    bool tag;
}ResultVo;

typedef struct {
    Key key;
    char data;
} Record;

/**
 * LinkList：队列节点定义
 */
typedef struct LNode {
    BTree data;     // 数据域
    struct LNode *next;     // 指针域
} LNode, *LinkList;


/**
 * @description 初始化队列
 */
bool initQueue(LinkList *list);

bool insertQueueNode(LNode *node, BTree tree);

bool deleteQueueNode(LNode *node, BTree *tree);

bool destroyQueue(LinkList list);

bool ifEmpty(LinkList list);

bool printTree(BTree tree);

