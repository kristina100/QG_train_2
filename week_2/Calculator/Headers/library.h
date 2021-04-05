#ifndef CALCULATOR_LIBRARY_H
#define CALCULATOR_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

void Menu();
int Menu0();

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
}Status;

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode;

typedef struct Stack
{
    StackNode *top;
    int length;
}Stack;


void Quit();
int Priority(char ch);
int initLStack(Stack *stack);
int push(Stack *s, int num);
int getTopLStack(Stack *s);
int pop(Stack *s);
int isemptyStack(Stack *s);

#endif
