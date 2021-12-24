//
// Created by HUAWEI on 2021-11-22.
//

#ifndef FOREST_COMMN_H
#define FOREST_COMMN_H
#include <cstdio>
#include <cstdlib>

#define ERROR 0
#define OK 1

typedef char TElemType;
typedef int Status;

typedef struct CSTNode{
    TElemType data{};
    struct CSTNode *firstChild{}, *nextSibling{};
}CSTNode,*CSTree,*CSForest;/** 孩子兄弟链表 */

/** 层序遍历用队列实现 */
/** 链队列的节点定义，包含一个数据域和下一个节点的指针 */
typedef struct QueueNode {
    CSTNode* data;
    struct QueueNode* next;
}QueueNode;

/**  链队列的定义，包含队头和队尾指针*/
typedef struct {
    QueueNode* front;
    QueueNode* rear;
}LinkQueue;


/** 函数申明 */

LinkQueue* InitQueue();/** 链队列的初始化 */
void DestoryQueue(LinkQueue*);/** 销毁队列 */
void EnQueue(LinkQueue*, CSTNode*);/** 入队 */
CSTNode* DeQueue(LinkQueue*);/** 出队 */



void Menu();
void Quit();
void Menu0();


Status DeleteChild(CSTree *T, CSTree p, int i);
Status InsertChild(CSTree &T,int i, CSTree c,TElemType e);
CSTree Search(CSTree T,TElemType e);


int PostOrderTraverse_3(CSTree t);
int PostOrderTraverse_2(CSTree t);
void PostOrderTraverse(CSTree t,int lev,int &dep);



Status DestroyTree(CSTree *T);

int CountLeaves1(CSTree T);
void PrintfTree(CSTree T,int H);

void LayerOrderCSTree(CSTree root);
void postOrderTraverse(CSTree T);
void InOrderTraverse(CSTree T);
void PreOrderTraverse(CSTree T);

CSTree MakeTree(TElemType e,int n,...);

#endif //FOREST_COMMN_H
