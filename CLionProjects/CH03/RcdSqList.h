//
// Created by HUAWEI on 2021-10-18.
//

#ifndef CH03_RCDSQLIST_H
#define CH03_RCDSQLIST_H

#include "Common.h"

typedef long KeyType;

typedef struct{
    KeyType key;
}RcdType;

typedef struct {
    RcdType  *rcd;  // 存储空间的基址
    long length;// 表长
    long size;// 存储容量
    long increment;  // 存储增量
} RcdSqList;

Status InitList_Sq(RcdSqList &L, long size, long increment);
Status DestroyList_Sq(RcdSqList &L);
Status Append_Sq(RcdSqList &L, RcdType e);
Status DeleteLast_Sq(RcdSqList &L, RcdType &e);


#endif //CH03_RCDSQLIST_H
