#include "library.h"

#include <stdio.h>
#include <stdlib.h>



void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t\t\t-----------------------------\n");
    printf("\t\t\t\t\tPlease enter your choice:\n");
    while(1)
    {
        getchar();
        while(scanf("%d",&temp) != 1)
        {
            getchar();
            printf("The input is illegal, please re-enter.Thanks.--:");
        }
        if(temp==1)
        {
            system("cls");
            printf("\t\t\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\t\t\tSafely exited the system\n");
            printf("\t\t\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program
        }
        else if(temp==2)
        {
            Menu();
            return;
        }
    }
}

void Menu0()
{
    printf("\n\n\n\n\t\t\t|  Welcome to QG Training Camp!  |\n");
    printf("\t\t\t|  Something interesting.        |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    1.pushLStack                |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    2.popLStack                 |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    3.LStackLength              |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    4.getTopLStack              |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    5.clearLStack               |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    6.destroyLStack             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    7.isEmptyLStack             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    8.initLStack                |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    9.Quit                      |\n");
    printf("\t\t\t|                                |\n");
    printf("\n\t\t\nPlease enter your choice(1 to 6) :\n");
}

int main()
{
    Menu();
    return 0;
}

Status InputCheck(ElemType *info)
{
    char arr[10] = {0};
    int flag = 0;
    scanf("%s", arr);//User input.
    getchar();
    for (int j = 0; arr[j] != '\0'; j++)
    {
        //Detect input.
        if(j == 0 && (arr[j] == '-'||arr[j] == '+'))
        {
            continue;
        }
        if (arr[j] < '0' || arr[j] > '9')
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        //User input error
        return ERROR;
    }
    int temp = 0,simple = 1;
    for(int i = 0;arr[i] != '\0';i++)
    {
        if(arr[i] == '-')
        {
            //simple was used to determine whether the user has entered a negative number.
            simple = -1;
            continue;
        }
        else if (arr[i]=='+')
        {
            continue;
        }
        temp = temp*10 + (arr[i] - 48);//Print numbers (automatically filter symbols).
    }
    *info = temp * simple;
    return SUCCESS;
}


Status Menu() {
    int inputs;//User input.
    int select,sizes;
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));
    if(s == NULL)
    {
        printf("Create fail\n");
        return ERROR;
    }
    printf("Please enter the length of the stack you want:\n ");
    while(InputCheck(&sizes) == ERROR)
    {
        printf("please re-enter:\n");
    }
    initStack(s, sizes);
    Menu0();
    inputs = scanf("%d",&select);
    while(inputs != 1) //Prevent users from entering illegally.
    {
        printf("Please enter an integer(But don't over 50 digits) : \n");
        getchar();
        inputs = scanf("%d",&select);
    }
    while(1)
    {
        if(select == 6)//If it is to destroy the stack, terminate the program.
        {
            printf("\nTest destroyLStack module\n");
            destroyStack(s);
            printf("\nYou have destroyed the stack,system will exit(0),Thank you for your using.\n");
            break;
        }
        switch (select)
        {
            int info,length,temp;
            case 1:
                info = 0;
                printf("\nTest pushLStack module\n");
                printf("The current data:\n");
                StackTraverse(s,visit);
                printf("Please enter an integer:'-1' to quit:\n");
                while(1)
                {
                    while(InputCheck(&info) == ERROR)
                    {
                        printf("please re-enter:\n");
                    }
                    if(info == -1)//Enter termination conditions.
                    {
                        break;
                    }
                    pushStack(s, info);
                }
                printf("The changed data:\n");
                StackTraverse(s,visit);
                system("pause");
                break;
            case 2:
                printf("\nTest popLStack module\n");
                printf("The current data:\n");
                StackTraverse(s,visit);
                popStack(s, &info);
                printf("The pop number is %d.\n",info);
                printf("The changed data:\n");
                StackTraverse(s,visit);
                system("pause");
                break;
            case 3:
                length = 0;
                printf("\nTest LStackLength module\n");
                StackTraverse(s,visit);
                stackLength(s, &length);
                printf("The Stack's is %d length.",length);
                system("pause");
                break;
            case 4:
                info = 0;
                printf("Test getTopLStack module\n");
                getTopStack(s, &info);
                printf("The element of top_stack is %d.\n",info);
                system("pause");
                break;
            case 5:
                printf("\nTest clearLStack module\n");
                StackTraverse(s,visit);
                clearStack(s);
                printf("You have cleared the stack.\n");
                StackTraverse(s,visit);
                system("pause");
                break;
            case 7:
                printf("The current data:\n");
                StackTraverse(s,visit);
                printf("\nTest isEmptyLStack module\n");
                isEmptyStack(s);
                StackTraverse(s,visit);
                system("pause");
                break;
            case 8:
                temp = 0;
                printf("\nTest initLStack module\n");
                initStack(s, temp);
                printf("initLStack successfully.\n");
                system("pause");
                break;
            case 9:
                system("cls");
                Quit();
                break;
            default:break;
        }
        Menu0();
        inputs = scanf("%d",&select);
        while(inputs != 1)//Prevent users from entering illegally.
        {
            printf("Please enter an integer:\n");
            getchar();
            inputs = scanf("%d",&select);
        }
    }
    return SUCCESS;
}

Status visit(ElemType e)
{
    printf("%d->",e);
    return SUCCESS;
}

Status StackTraverse(SqStack *s,Status(*visit)(ElemType))
{
    if(isEmptyStack(s))
    {
        return ERROR;
    }
    for(int i = s->top-1;i>=-1;i--)
    {
        visit((*s).elem[i]);
    }
    return SUCCESS;
}

Status initStack(SqStack *s,int sizes)//Initialize the stack.
{
    s->top = -1;//Set the top of the stack to -1, because the stack is currently empty.
    s->size = sizes;//Stack length
    s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));//Allocate storage space.
    if(s->elem == NULL)
    {
        return ERROR;
    }
    return SUCCESS;
}

Status isEmptyStack(SqStack *s)//Determine whether the stack is empty.
{
    return (s->top == -1 ? SUCCESS : ERROR);
}

Status getTopStack(SqStack *s,ElemType *e) //Get the top element of the stack.
{
    if(s->top == -1)
    {
        return ERROR;
    }
    *e = s->elem[s->top-1];
    return SUCCESS;
}

Status clearStack(SqStack *s)//Empty the stack.
{
    int i = 0;
    ElemType e = 0;
    if(s->top == -1)
    {
        return ERROR;
    }
    for (i = s->top-1;i>=-1;i--)
    {
        s->elem[s->top--] = -1;
    }
    printf("clear success.\n");
    return SUCCESS;
}

Status destroyStack(SqStack *s)//Destroy stack.
{
    clearStack(s);
    free((void *) s->top);
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//Check stack length.
{
    if(s->top == -1)
    {
        *length = 0;
    }
    *length = s->size;
    return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//Push into the stack.
{
    ElemType *new;
    if(s->top >= s->size)//If the stack is full, open up new space.
    {
        new = (ElemType*)realloc(s->elem,(s->size)*sizeof(ElemType));
        //Use reallocate to try to re-adjust the previously called space.
        if(new == NULL)
        {
            return ERROR;
        }
        s->elem = new;
    }
    s->elem[s->top++] = data;
    return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//Unstack.
{
    if(s->top == -1)
    {
        return ERROR;
    }
    s->top--;
    *data = s->elem[s->top];
    return SUCCESS;
}