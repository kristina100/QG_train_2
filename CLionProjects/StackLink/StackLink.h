//
// Created by HUAWEI on 2021/9/14.
//

#ifndef STACKLINK_STACKLINK_H
#define STACKLINK_STACKLINK_H

#include "Common.h"
//Custom function

void Quit();
void Menu0();
void Menu();

Status InputCheck(ElemType *info);
Status StackTraverse(LinkStack *s);
Status visit(ElemType c);

//Chain stack
Status initLStack(LinkStack **s);//Initialize the stack.
Status isEmptyLStack(LinkStack *s);//Determine whether the stack is empty.
Status getTopLStack(LinkStack *s,ElemType *e);//Get the top element of the stack.
Status clearLStack(LinkStack *s);//Empty the stack.
Status destroyLStack(LinkStack *s);//Destroy stack.
Status LStackLength(LinkStack *s,int *e);//Check stack length.
Status pushLStack(LinkStack *s,ElemType e);//Push into the stack.
Status popLStack(LinkStack *s,ElemType *e);//Unstack

#endif //STACKLINK_STACKLINK_H
