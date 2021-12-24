//
// Created by HUAWEI on 2021/9/14.
//

#ifndef STACKLINK_COMMON_H
#define STACKLINK_COMMON_H

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
    LinkStackPtr top;
    int	count;
}LinkStack;


#endif //STACKLINK_COMMON_H
