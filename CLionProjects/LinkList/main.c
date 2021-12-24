#include <stdio.h>
#include "LinkList.h"

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
    printf("|    8.InsertHead                |\n");
    printf("|                                |\n");
    printf("|    9.DestroyList               |\n");
    printf("|                                |\n");
    printf("|    10.DeleteWithHead           |\n");
    printf("|                                |\n");
    printf("|    11.InsertNoneHead           |\n");
    printf("|                                |\n");
    printf("|    12.DeleteNoneHead           |\n");
    printf("|                                |\n");
    printf("|    13.Quit                     |\n");
    printf("|                                |\n");
    printf("Please enter your choice(1 to 13) :");
}
void Menu()
{
    int temp,inputs,number,i,G;//User input.
    int select;
    LinkedList L,head=NULL,p1=NULL,pp = NULL;
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
                system("cls");
                printf("\nTest information insertion module\n");
                InsertListHead(L);
                system("pause");
                break;

            case 9:
                system("cls");
                printf("\nTest linked list destruction module\n");
                DestroyList(&L);
                TraverseList(L);
                system("pause");
                break;
            case 11:
                system("cls");
                printf("\nTest information insertion module\n");
                InsertListNoneHead(L);
                system("pause");
                break;
            case 10:
                Quit();
                break;
            case 12:
                printf("Delete what\n");
                while (scanf("%d", &G) == 0)
                {
                    printf("ERROR");
                    while (getchar() != '\n');
                }
                p1 = L;
                for (i = 0; i < G; i++)
                {
                    if (p1 == NULL)
                    {
                        printf_s("None\n");
                        break;
                    }
                    p1 = p1->next;
                }
                if (p1 != NULL)
                    if (p1->next == NULL)
                        pp = p1;
                DeleteListNoneHead(p1, G,&number);
                printf("%d",number);
                system("pause");
                break;
//                number = 0;
//                system("cls");
//                printf("\nTest Delete module\n");
//                InsertListNoneHead(L);
//                DeleteListNoneHead(L,&number);
//                printf("%d",number);
//                system("pause");
//                break;
            case 13:
                printf("Delete what:\n");
                while (scanf("%d", &G) == 0)
                {
                    printf("Error.");
                    while (getchar() != '\n');
                }
                p1 = L->next;
                for (i = 1; i < G; i++)
                {
                    if (p1->next == NULL)
                    {
                        printf_s("None\n");
                        break;
                    }
                    p1 = p1->next;
                }
                if (p1->next != NULL)
                    if (p1->next->next == NULL)
                        pp = p1;
                DeleteListHead(p1, G,&number);
                printf("%d",number);
                system("pause");
//                number = 0;
//                system("cls");
//                printf("\nTest Delete With Head module\n");
//                InsertListNoneHead(L);
//                DeleteListHead(L,&number);
//                printf("%d",number);
//                system("pause");
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

int main() {
    Menu();
    return 0;
}
