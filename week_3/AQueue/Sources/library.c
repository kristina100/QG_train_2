#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corporation        :   Chan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/


/**************************************************************
 *    Struct Define Section
 **************************************************************/
//非法输入检查函数
Status InputCheck(int *info)
{
    char arr[50] = {0};
    int flag = 0,flag2=0;
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
            flag = 1;
        }
    }
    if (flag == 1)
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

//菜单0
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
//菜单
void Menu()
{
    int inputs;//User input.
    int select;
    AQueue Q;
    InitAQueue(&Q);
    Menu0();
    printf("After initializing the queue, is the queue empty? %d (1. Empty 0. No)\n",IsEmptyAQueue(&Q));
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
            DestroyAQueue(&Q);
            printf("\nOh, you have destroyed the stack, system will exit(0), thank you for your using.^_^\n");
            system("pause");
            break;
        }

        switch (select) {
            int info, length, counts;
            case 1:
                //system("cls");
                info = 0;
                int i = 0;
                printf("\nI am going to test EnAQueue module.\n");
                printf("The current data:\n");
                TraverseAQueue(&Q);
                printf("Please enter an integer:'-1' to quit:\n");
                do
                    {
                    while (InputCheck(&info) == FALSE)
                    {
                        printf("Sorry, please re-enter:\n");
                    }
                    if (info == -1)//Enter termination conditions.
                    {
                        break;
                    }
                    EnAQueue(&Q, info);
                    i++;
                }while(i<MAXQUEUE-1);
                printf("The changed data are as follows:\n");
                TraverseAQueue(&Q);
                printf("\n");
                system("pause");
                break;
            case 2:
                //system("cls");
                printf("\nI am going to test DeAQueue module.^_^\n");
                printf("The current data:\n");
                TraverseAQueue(&Q);
                DeAQueue(&Q);
                printf("The changed data:\n");
                TraverseAQueue(&Q);
                system("pause");
                break;
            case 3:
                //system("cls");
                length = 0;
                printf("\nI am going to test LengthAQueue module.^_^\n");
                TraverseAQueue(&Q);
                length = LengthAQueue(&Q);
                printf("\nSuccessfully^_^! The Stack's is %d length.\n\n",length);
                system("pause");
                break;
            case 4:
                //system("cls");
                info = 0;
                printf("I am going to test GetHeadAQueue module.^_^\n");
                GetHeadAQueue(&Q,&info);
                printf("Successfully^_^! The element of top_stack is %d.\n",info);
                system("pause");
                break;
            case 5:
                //system("cls");
                printf("\nI am going to test ClearAQueue module.^_^\n");
                ClearAQueue(&Q);
                printf("Great! You have cleared the stack.\n");
                system("pause");
                break;
            case 7:
                //system("cls");
                printf("The current data:\n");
                TraverseAQueue(&Q);
                printf("\nI am going to test IsEmptyAQueue module\n");
                printf("Empty the queue or not? My answer:%d (1. Empty 0. No)\n",IsEmptyAQueue(&Q));
                system("pause");
                break;
            case 8:
                //system("cls");
                printf("\nI am going to test InitAQueue module\n");
                InitAQueue(&Q);
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
//退出系统

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


int main()
{
    Menu();
    return 0;
}

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Q->front = 0;//Just initialize the tail and head index.
    Q->rear = 0;
    Q->length =(Q->front - Q->rear + MAXQUEUE) % MAXQUEUE;
}


/**
 *  @name        : void Destroy AQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestroyAQueue(AQueue *Q)
{
    Q->front = Q->rear = 0;//Based on the array, no need to allocate memory.
    //Just reset the head and tail index.
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if(Q->length == MAXQUEUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->front == Q->rear)//The queue is empty.
        return TRUE;
    return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, int *e)
{
    if(IsEmptyAQueue(Q))
    {
        return FALSE;
    }
    else
    {
        *e = Q->data[Q->front];
        return TRUE;
    }
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    Q->length = (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
    return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q,int data)
{
    if((Q->rear+1)%MAXQUEUE == Q->front)
    {
        printf("Error, the Queue is full.\n");
        return FALSE;
    }
    Q->data[Q->rear] = data;//Insert value.
    Q->rear = (Q->rear+1) % MAXQUEUE;//Tail shift.
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q))
    {
        return FALSE;
    }
    Q->front = Q->front + 1;
    Q->rear = Q->rear;
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(char *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q)
{
    int i;
    i = Q->front;
    while((i+Q->front) != Q->rear)
    {
        APrint(Q->data[i]);
        i = (i+1) % MAXQUEUE;
    }
    printf("\n");
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(int q)
{
    printf("%d->",q);
}




