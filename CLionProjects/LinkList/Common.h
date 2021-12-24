//
// Created by HUAWEI on 2021/9/17.
//

#ifndef LINKLIST_COMMON_H
#define LINKLIST_COMMON_H

#include<stdlib.h>
#include<stdio.h>




// define element type
typedef int ElemType ;

// define struct of linked list
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status
{
    ERROR,
    SUCCESS
} Status;


typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

#endif //LINKLIST_COMMON_H
