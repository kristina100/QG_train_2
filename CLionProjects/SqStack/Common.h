//
// Created by HUAWEI on 2021/9/14.
//

#ifndef UNTITLED1_COMMON_H
#define UNTITLED1_COMMON_H
typedef enum Status
{
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
    ElemType *elem;//Dynamically allocate memory space.
    int top;//Top of stack.
    int size;//capacity
} SqStack;


#endif //UNTITLED1_COMMON_H
