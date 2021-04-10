#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */

int main()
{
    Menu();
    return 0;
}

void Menu0()
{
    printf("\n\n\n\n\t\t\t|  Welcome to QG Training Camp!  |\n");
    printf("\t\t\t|  Something interesting.        |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    1.EnAQueue                  |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    2.DeAQueue                  |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    3.LengthAQueue              |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    4.GetHeadAQueue             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    5.ClearAQueue               |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    6.DestroyAQueue             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    7.IsEmptyAQueue             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    8.InitAQueue                |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    9.Quit                      |\n");
    printf("\t\t\t|                                |\n");
    printf("\n\t\t\nPlease enter your choice(1 to 9) :\n");
}


void Menu()
{
    int inputs;//User input.
    int select;
    LQueue Q;
    InitLQueue(&Q);
    Menu0();
    printf("After initializing the queue, is the queue empty? %d (1. Empty 0. No)\n",IsEmptyLQueue(&Q));
    inputs = scanf("%d",&select);
    while(inputs != 1)//Prevent users from entering illegally.
    {
        printf("Hello, please enter an integer ^_^: \n");
        getchar();
        inputs = scanf("%d",&select);
    }
    while(1)
    {
        if(select == 6)//If it is to destroy the stack, terminate the program.
        {
            system("cls");
            printf("\nTest destroyLStack module\n");
            DestroyLQueue(&Q);
            printf("\nOh, you have destroyed the stack, system will exit(0), thank you for your using.^_^\n");
            system("pause");
            break;
        }

        switch (select) {
            int info, length, counts;
            case 1:
                //system("cls");
                info = 0;
                printf("\nI am going to test EnAQueue module.\n");
                printf("The current data:\n");
                TraverseLQueue(Q);
                printf("Please enter an integer:'-1' to quit:\n");
                while(1)
                {
                    while (InputCheck(&info) == FALSE) {
                        printf("Sorry, please re-enter:\n");
                    }
                    if (info == -1)//Enter termination conditions.
                    {
                        break;
                    }
                    EnLQueue(&Q, info);
                }

                printf("The changed data are as follows:\n");
                TraverseLQueue(Q);
                printf("\n");
                system("pause");
                break;
            case 2:
                //system("cls");
                printf("\nI am going to test DeAQueue module.^_^\n");
                printf("The current data:\n");
                TraverseLQueue(Q);
                DeLQueue(&Q);
                printf("The changed data:\n");
                TraverseLQueue(Q);
                system("pause");
                break;
            case 3:
                //system("cls");
                printf("\nI am going to test LengthAQueue module.^_^\n");
                printf("The current data:\n");
                TraverseLQueue(Q);
                length = LengthLQueue(&Q);
                printf("\nSuccessfully^_^! The Stack's is %d length.\n\n",length);
                system("pause");
                break;
            case 4:
                //system("cls");
                info = 0;
                printf("The current data:\n");
                TraverseLQueue(Q);
                printf("I am going to test GetHeadAQueue module.^_^\n");
                GetHeadLQueue(&Q,&info);
                printf("Successfully^_^! The element of top_stack is %d.\n",info);
                system("pause");
                break;
            case 5:
                //system("cls");
                printf("\nI am going to test ClearAQueue module.^_^\n");
                ClearLQueue(&Q);
                printf("Great! You have cleared the stack.\n");
                system("pause");
                break;
            case 7:
                //system("cls");
                printf("The current data:\n");
                TraverseLQueue(Q);
                printf("\nI am going to test IsEmptyAQueue module\n");
                printf("Empty the queue or not? My answer:%d (1. Empty 0. No)\n",IsEmptyLQueue(&Q));
                system("pause");
                break;
            case 8:
                //system("cls");
                printf("\nI am going to test InitAQueue module\n");
                InitLQueue(&Q);
                printf("Great! InitAQueue successfully.\n");
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
            printf("Sorry, please enter an integer:^_^\n");
            getchar();
            inputs = scanf("%d",&select);
        }
    }
}


Status InputCheck(int *info)
{
    char arr[50] = {0};
    int flag1=0,flag2 = 0;
    scanf("%s", arr);//User input.
    getchar();
    while(1)
    {
        for (int i = 0;i<50;i++)
        {
            if(arr[i]=='\0')
            {
                flag2 = 1;
                break;
            }
        }
        if(flag2 == 1)
        {
            break;
        }
        printf("The data you entered is too big.*_* And because I am limited .\n"
               "I can only let the system violently exit.\n"
               "I am very sorry and hope I will have time to solve this problem in the future.\n");
        memset(arr,'\0',sizeof(arr)-1);
        puts(arr);
    }
    for (int j = 0; arr[j] != '\0'; j++)
    {
        //Detect input.
        if(j == 0 && (arr[j] == '-'||arr[j] == '+'))
        {
            continue;
        }
        if (arr[j] < '0' || arr[j] > '9')
        {
            flag1 = 1;
        }
    }
    if (flag1 == 1)
    {
        //User input error
        return FALSE;
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
    return TRUE;
}

void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t\t------------------------------\n");
    printf("\t\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t\t-----------------------------\n");
    printf("\t\t\t\tPlease enter your choice:\n");
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
            printf("\t\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\t\tSafely exited the system\n");
            printf("\t\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program
        }
        else if(temp==2)
        {
            Menu();
            return;
        }
    }
}



Status InitLQueue(LQueue *Q)
{
    Q->front=Q->rear=(Node*)malloc(sizeof(Node));
    if(!Q->front)
        exit(0);
    Q->front->next=NULL;
    return TRUE;
}

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestroyLQueue(LQueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front==Q->rear)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, ElemType *e)
{
    Node* p;
    if(Q->front==Q->rear)
        return FALSE;
    p=Q->front->next;
    *e= (ElemType) p->data;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    int i=0;
    Node* p;
    p=Q->front;
    while(Q->rear!=p)
    {
        i++;
        p=p->next;
    }
    return i;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, ElemType data)
{
    Node* s=(Node*)malloc(sizeof(Node));
    if(!s) /* 存储分配失败 */
        exit(0);
    s->data = data;
    s->next=NULL;
    Q->rear->next=s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
    Q->rear=s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    Node* p;
    if(Q->front==Q->rear)
        return FALSE;
    p=Q->front->next;		/* 将欲删除的队头结点暂存给p，见图中① */
    Q->front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
    if(Q->rear==p)		/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
        Q->rear=Q->front;
    free(p);
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */

Status ClearLQueue(LQueue *Q)
{
    Node *p,*q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue Q)
{
    Node* p;
    p=Q.front->next;
    while(p)
    {
        LPrint(p->data);
        p=p->next;
    }
    printf("\n");
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(ElemType q)
{
    printf("%d->",q);
}


