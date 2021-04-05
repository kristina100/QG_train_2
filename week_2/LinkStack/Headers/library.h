#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

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


#endif //STACK_H_INCLUDED
