#include "LinkList.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    Menu();
    return 0;
}

void Quit()
{
    system("cls");
    int t;
    printf("------------------------------\n");
    printf("|    Are you sure to quit    |\n");
    printf("|    1.YES      2.NO         |\n");
    printf("-----------------------------\n");
    printf("Please enter your choice:\n");
    while(1)
    {
        t = getchar();
        scanf("%d",&t);
        if(t==1)
        {
            system("cls");
            printf("Exiting safely....\n");
            system("cls");
            printf("Safely exited the system\n");
            printf("Thank you for using!  <_>\n");
            exit(0);//Terminate the program
        }
        else if(t==2)
        {
            Menu();
            return;
        }
        else
        {
            printf("ERROR");
        }
    }
}
void Menu0()
{
    printf("|  Welcome to QG Training Camp!  |\n");
    printf("|  Something interesting.        |\n");
    printf("|                                |\n");
    printf("|    1.Data Entry                |\n");
    printf("|                                |\n");
    printf("|    2.InsertList                |\n");
    printf("|                                |\n");
    printf("|    3.ReverseEvenList           |\n");
    printf("|                                |\n");
    printf("|    4.FindMidNode               |\n");
    printf("|                                |\n");
    printf("|    5.IsLoopList                |\n");
    printf("|                                |\n");
    printf("|    6.Reverse_1                 |\n");
    printf("|                                |\n");
    printf("|    7.Search                    |\n");
    printf("|                                |\n");
    printf("|    8.DeleteList                |\n");
    printf("|                                |\n");
    printf("|    9.DestroyList               |\n");
    printf("|                                |\n");
    printf("|    10.Quit                     |\n");
    printf("Please enter your choice(1 to 6) :");
}

_Noreturn void Menu()
{
    int temp,inputs;//User input.
    int select;
    LinkedList L;
    InitList(&L);
    Menu0();
    fflush(stdin);
    inputs = scanf("%d",&select);
    while(inputs != 1)//Prevent users from entering illegally. 
    {
        printf("Please enter an integer:\n");
        fflush(stdin);
        inputs = scanf("%d",&select);
    }
    while(1)
    {
        switch (select)
        {
            case 1:
                system("cls");
                printf("\nTest information input module\n");
                InputInf(&L);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("\nTest information insertion module\n");
                TestInput(L);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("\nTest parity switch module\n");
                ReverseEvenList(&L);
                TraverseList(L);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Test to find intermediate node module");
                FindMidNode(&L);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("\nTest for looping module\n");
                TraverseList(L);
                IsLoopList(L);
                system("pause");
                break;
            case 6:
                system("cls");
                printf("\nTest reversal module\n");
                ReverseList(&L);
                system("pause");
                break;
            case 7:
                system("cls");
                printf("\nTest find element module\n");
                temp = 0;
                printf("Please input the number you want to search:\n");
                fflush(stdin);
                while(scanf("%d",&temp)!=1)
                {
                    printf("input ERROR!");
                }
                SearchList(L, temp);
                system("pause");
                break;
            case 8:
                break;
            case 9:
                system("cls");
                printf("\nTest linked list destruction module\n");
                DestroyList(&L);
                TraverseList(L);
                system("pause");
                break;
            case 10:
                Quit();
                break;
            default:break;
        }
        Menu0();
        fflush(stdin);
        inputs = scanf("%d",&select);
        while(inputs != 1)//Prevent users from entering illegally.
        {
            printf("Please enter an integer:\n");
            fflush(stdin);
            inputs = scanf("%d",&select);
        }
    }
}

Status TestInput(LinkedList L)
{
    if (L->next == NULL)
    {
        printf("\nSorry, there is no data. Please choice 1. Thanks.");
        return ERROR;
    }
    else{
        LinkedList p = L->next;
        TraverseList(L); //Show existing list
        while (p->next)  //Move to end of list
        {
            p = p->next;
        }
        while (1)
        {
            LNode *q = (LinkedList)malloc(sizeof(LNode));//Insert node
            if (!q)
            {
                system("cls");
                printf("Failed to apply for memory!");/*If you have not applied for it,
                                               *print the prompt message*/
                system("pause");
                return ERROR;
            }
            printf("\nPlease input the data('0' to quit):");
            fflush(stdin);
            scanf("%d",&(q->data));//Enter the value of the previous node you want to insert
            if (q->data == 0)
            {
                break;//End of data entry
            }
            InsertList(p,q);
        }
        printf("\n");
        TraverseList(L);
        return SUCCESS;
    }
}

void visit(ElemType c)
{
    printf("%d->",c);
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L)
{
    *L=(LinkedList)malloc(sizeof(LNode)); /* Generate a head node, and make L point to this head node */
    if (!(*L))                            /* Storage allocation failed */
        {
        printf("\n allocate memory failure \n");/*If you have not applied for it, print the prompt message*/
        return ERROR; /*Exit system*/
        }
    (*L)->next=NULL; /* The pointer field is empty */
    return SUCCESS;
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */

Status DestroyList(LinkedList *L)
{
    if((*L)->next==NULL)
    {
        return ERROR;
    }
    LinkedList p,q;
    p = (*L) -> next;//p points to the first node
    while(p)//Exit at the end of the list
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;//Head node points to empty
    return SUCCESS;
}

Status InputInf(LinkedList *L)
{
    if((*L)==NULL)
    {
        return ERROR;
    }
    int select;
    LNode* p;         /*Define record pointer variable*/
    LinkedList r;
    r = (*L);
    while (r->next)    /*Not free continue*/
    {
        r = r->next;   /*Move the pointer to the end of the linked list, ready to add records*/
    }
    printf("Please input the data('0' to quit):\n");
    while(1)
    {
        p = (LNode *) malloc(sizeof(LNode));/*Request memory space.*/
        if (!p)
        {
            system("cls");
            printf("\n allocate memory failure \n");/*If you have not applied for it, print the prompt message.*/
            system("pause");
            exit(0);//End the program.
        }
        select = getchar();
        scanf("%d", &select);

        if(select==0)
        {
            break;
        }
        p->data = select;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    printf("\nThe current data :\n");
    TraverseList(*L);
    return SUCCESS;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */

Status InsertList(LNode *p, LNode *q)
{
    if(p==NULL&&q==NULL)
    {
        return ERROR;
    }
    q->next = NULL;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */

Status DeleteList(LNode *p, ElemType *e)
{
    LinkedList L;
    InitList(&L);
    LNode *r;//Traverse
    r = L->next;
    while(r)//End when r reaches the end node
    {
        if(r != p)
        {
            r = r->next;
        }
        else
        {
            break;
        }
    }
    if(r)//If it is empty, it means that it was not found, so do not execute; otherwise execute
    {
        *e = r->next->data;
    }
    return SUCCESS;
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the function visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */

void TraverseList(LinkedList L)
{
        LinkedList p=L->next;
        while(p)
        {
            visit(p->data);
            p = p->next;
        }
        printf("\n");
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
    if(L->next==NULL)
    {
        return ERROR;
    }
    LinkedList r;//For traversal
    r = L->next;
    while(r->next)//r is not empty
    {
        if(r->data != e)
        {
            r = r->next;
        }
        break;
    }
    if(r)//Return successfully if found
    {
        printf("SUCCESS.");
    }
    return ERROR;

}
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)
{
        if (*L == NULL&&(*L)->next==NULL)
        {
            return ERROR;
        }
        if((*L)->next->next==NULL)
        {
            return SUCCESS;//When there is only one element, the inversion is still one element
        }
        LinkedList newHead = NULL;
        LinkedList front = NULL;
        LinkedList rear = (*L)->next;
        while (rear)
        {
            front = rear->next;
            rear->next = newHead;
            newHead = rear;
            rear = front;
        }
        *L = (newHead);
        TraverseList(*L);
        return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
    if(L->next==NULL&&L->next->next==NULL)
    {
        return ERROR;//At least three nodes can form a ring
    }
    LinkedList rear = L->next;
    LinkedList front = L->next->next;
    int flag = 0;
    while(front)//It ends if it doesn't form a ring
    {
        if(rear == front)
        {
            flag = 1;
            break;
        }
        rear = rear->next;
        front = front->next->next;
    }
    printf(flag == 1 ? "\nSingly linked list into ring\n" : "\nSingle-linked list does not form a ring\n");
    return SUCCESS;
}
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)
{
        if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL)
        {
            return NULL;
        }
        LinkedList front = (*L)->next->next;
        LinkedList rear = *L;
        while (front != NULL)
        {
            if (front->data % 2 == 0)//Even numbers are exchanged
            {
                rear->next->next = front->next;
                front->next = rear->next;
                rear->next = front;
                front = front->next;
            }
            front = front->next;
            rear = rear->next;
        }
        return (*L);
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L)
{
    if((*L)==NULL&&(*L)->next==NULL&&(*L)->next->next==NULL)
    {
        return NULL;//At least three nodes can form a ring
    }
    LinkedList front = (*L)->next->next;
    LinkedList rear = (*L)->next;
    printf("\nThe current data:\n");
    TraverseList(*L);
    while(front)//The ones that increase faster hit the end first
    {
        rear = rear->next;
        front = front->next->next;
    }
    printf("\nThe value of the middle node is %d\n",rear->data);
    return rear;
}
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/



