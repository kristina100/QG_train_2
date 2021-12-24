#include "LinkList.h"

#include <stdio.h>
#include <stdlib.h>





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

Status InsertListH(LNode *p, LNode *q)
{
    if(p==NULL&&q==NULL)
    {
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}


Status InsertListHead(LinkedList L)
{
    if (L->next == NULL)
    {
        printf("\nSorry, there is no data. Please choice 1. Thanks.");
        return ERROR;
    }
    else{
        LinkedList p = L;

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
            InsertListH(p,q);
        }
        printf("\n");
        TraverseList(L);
        return SUCCESS;
    }
}


Status InsertListNoneHead(LinkedList L)
{
    LinkedList s;
    L->next = NULL;
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
        InsertListH(L,q);
    }
    printf("\n");
    TraverseList(L);
    return SUCCESS;
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


/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */

Status DeleteListHead(LNode *p, int i, ElemType *e)
{
    if (p == NULL)
    {
        printf("None");
        return ERROR;
    }
    if (p->next == NULL)
    {
        printf("None");
        return ERROR;
    }
    LinkedList q;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    printf("the number you have deleted:%d\n",*e);
    return SUCCESS;
}

Status DeleteListNoneHead(LNode *p, int i, ElemType *e)
{
    if (p == NULL)
    {
        printf("None");
        return ERROR;
    }
    LinkedList q;
    q = p->next;
    *e = p->data;
    p->next = q->next;
    printf("the number delete:%d\n",*e);
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
    return SUCCESS;

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



