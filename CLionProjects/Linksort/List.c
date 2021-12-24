//
// Created by HUAWEI on 2021/9/16.
//

#include "Common.h"

Status InitList(SqList *L, int n)
{
    //构造存储空间
    L->elem = (ElemType*) malloc(MAXSIZE*sizeof (ElemType));
    if(NULL == L->elem)
        return OVERFLOW;
    L->length = 0;
    printf("%d",n);
    return OK;
}

Status ListEmpty(SqList L)
{
    if(L.length == 0)
        return TRUE;
    else
        return FALSE;
}

Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

Status ListLength(SqList L, int *e)
{
    *e = L.length;
    return OK;
}

Status GetElem(SqList L, ElemType e)
{
    int i;
    if(L.length == 0)
        return 0;

    return OK;
}


