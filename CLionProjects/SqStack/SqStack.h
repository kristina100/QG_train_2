//
// Created by HUAWEI on 2021/9/14.
//

#ifndef UNTITLED1_SQSTACK_H
#define UNTITLED1_SQSTACK_H

#include "Common.h"
void Quit();
void Menu0();

Status Menu();
Status InputCheck(ElemType *info);
Status visit(ElemType e);
Status StackTraverse(SqStack *s,Status(* visit)(ElemType));
//Array-based sequential stack.
Status initStack(SqStack *s,int sizes);//Initialize the stack.
Status isEmptyStack(SqStack *s);//Determine whether the stack is empty.
Status getTopStack(SqStack *s,ElemType *e); //Get the top element of the stack.
Status clearStack(SqStack *s);//Empty the stack-return to the initial state.
Status destroyStack(SqStack *s);//Destroy the stack-free up space.
Status stackLength(SqStack *s,int *length);//Check stack length.
Status pushStack(SqStack *s,ElemType data);//Push into the stack.
Status popStack(SqStack *s,ElemType *data);//Pop stack.


#endif //UNTITLED1_SQSTACK_H
