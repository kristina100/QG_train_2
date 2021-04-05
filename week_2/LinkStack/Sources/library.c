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
    printf("\n\t\t\nPlease enter your choice(1 to 9) :\n");
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

Status visit(ElemType c)
{
    printf("%d->",c);
    return SUCCESS;
}

Status StackTraverse(LinkStack *s)
{
    LinkStackPtr temp;
    if(s->top == NULL)
    {
        printf("There is no data:\n");
        return ERROR;
    }
    temp=s->top;
    while(temp)
    {
        visit(temp->data);
        temp=temp->next;
    }
    printf("\n");
    return SUCCESS;
}

void Menu()
{
    int inputs;//User input.
    int select;
    LinkStack *s;
    initLStack(&s);
    initLStack(&s);
    Menu0();
    inputs = scanf("%d",&select);
    while(inputs != 1)//Prevent users from entering illegally.
    {
        printf("Please enter an integer(But don't over 50 digits) : \n");
        getchar();
        inputs = scanf("%d",&select);
    }
    while(1)
    {
        if(select == 6)//If it is to destroy the stack, terminate the program.
        {
            system("cls");
            printf("\nTest destroyLStack module\n");
            destroyLStack((LinkStack *) &s);
            printf("\nYou have destroyed the stack,system will exit(0),Thank you for your using.\n");
            system("pause");
            break;
        }

        switch (select)
        {
            int info,length,counts;
            case 1:
                system("cls");
                info = 0;
                counts = 0;
                printf("\nTest pushLStack module\n");
                printf("The current data:\n");
                StackTraverse((LinkStack *) &s);
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
                    pushLStack((LinkStack *) &s, info);
                    counts++;
                }
                printf("The changed data:\n");
                StackTraverse((LinkStack *) &s);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("\nTest popLStack module\n");
                printf("The current data:\n");
                StackTraverse((LinkStack *) &s);
                popLStack((LinkStack *) &s, &info);
                counts--;
                printf("The pop number is %d.\n",info);
                printf("The changed data:\n");
                StackTraverse((LinkStack *) &s);
                system("pause");
                break;
            case 3:
                system("cls");
                length = 0;
                printf("\nTest LStackLength module\n");
                StackTraverse((LinkStack *) &s);
                //LStackLength((LinkStack *) &s, &length);
                printf("The Stack's is %d length.\n",counts);
                system("pause");
                break;
            case 4:
                system("cls");
                info = 0;
                printf("Test getTopLStack module\n");
                getTopLStack((LinkStack *) &s, &info);
                printf("The element of top_stack is %d.\n",info);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("\nTest clearLStack module\n");
                clearLStack((LinkStack *) &s);
                printf("You have cleared the stack.\n");
                StackTraverse((LinkStack *) &s);
                break;
            case 7:
                system("cls");
                printf("The current data:\n");
                StackTraverse((LinkStack *) &s);
                printf("\nTest isEmptyLStack module\n");
                isEmptyLStack((LinkStack *) &s);
                StackTraverse((LinkStack *) &s);
                system("pause");
                break;
            case 8:
                system("cls");
                printf("\nTest initLStack module\n");
                initLStack(&s);
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
}

Status initLStack(LinkStack **s)
{
    *s = (LinkStack*)malloc(sizeof(LinkStack));
    if(!(*s)->top)
        return ERROR;
    (*s)->top=NULL;
    (*s)->count=0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
    if(s->top==NULL)//Determine whether the top of the stack is empty.
    {
        return ERROR;
    }
    if (s->count==0)
        return SUCCESS;
    else
        return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (s->top==NULL)
        return ERROR;
    else
        *e=s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
    LinkStackPtr front,rear;
    if(s->top==NULL)
        return ERROR;
    front=s->top;
    while(front)
    {
        rear=front;
        front=front->next;
        rear->data = 0;//Clearing is to set the data to 0.
    }
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{
    if(s->top==NULL)
    {
        return ERROR;
    }
    StackNode *front,*rear;
    front = s->top;
    while(front)
    {
        rear = front->next;
        free(front);
        front = rear;
    }
    s->top->next = NULL;
    printf("SUCCESS");
    return SUCCESS;
}

Status LStackLength(LinkStack *s, int *length)
{
    if(s->top == NULL)
    {
        *length = 0;
        return SUCCESS;
    }
    *length = s->count;
    printf("length:%d",*length);
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType e)
{
    if(s->top==NULL)
    {
        return ERROR;
    }
    LinkStackPtr temp=(LinkStackPtr)malloc(sizeof(StackNode));
    temp->data=e;
    temp->next=s->top;//The top element of the current stack is directly assigned to the successor
    s->top=temp;//The new node is assigned to the top pointer of the stack
    s->count = s->count + 1;
    printf("\n-----%d\n",s->count);
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *e)
{
    LinkStackPtr p;
    if(s->top==NULL)
        return ERROR;
    *e=s->top->data;
    p=s->top;//The top node of the stack is assigned to p
    s->top=s->top->next;//Move back the top pointer of the stack
    free(p);//Release node
    s->count--;
    return SUCCESS;
}
