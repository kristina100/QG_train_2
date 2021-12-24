//
// Created by HUAWEI on 2021/9/16.
//

#ifndef LINKSORT_COMMON_H
#define LINKSORT_COMMON_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define OK 1
#define OVERFLOW -1
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
}SqList;

Status InitList(SqList *L, int n);
Status ListEmpty(SqList L);
Status ClearList(SqList *L);
Status ListLength(SqList L, int *e);
#endif //LINKSORT_COMMON_H
