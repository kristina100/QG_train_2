#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//
// Created by eke_l on 2021/4/21.
//
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
        return failed;
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
    return succeed;
}
void Menu()
{
    int inputs;//User input.
    int select;
    NodePtr T;
    BST_init(&T);
    Menu0();
    inputs = scanf("%d",&select);
    while(inputs != 1) //Prevent users from entering illegally.
    {
        printf("Please enter an integer: \n");
        getchar();
        inputs = scanf("%d",&select);
    }
    while(1)
    {
        if(select == 10)//If it is to destroy the stack, terminate the program.
        {
            system("cls");
            Quit();
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
                printf("\nTest Insert Module:\n");
                printf("\nPlease enter an integer:'-1' to quit:\n");
                while(1)
                {
                    while(InputCheck(&info) == failed)
                    {
                        printf("please re-enter:\n");
                    }
                    if(info == -1)//Enter termination conditions.
                    {
                        break;
                    }
                    BST_insert(&T, info);
                    counts++;
                }
                printf("\nGreat! Test Insert successfully.\n");
                system("pause");
                break;
            case 2:
                system("cls");
                printf("\nTest DeleteNode module\n");
                printf("\nPlease enter an integer you want to delete:'-1' to quit:\n");
                while(1)
                {
                    while(InputCheck(&info) == failed)
                    {
                        printf("Input error! Please re-enter:\n");
                    }
                    if(info == -1)//Enter termination conditions.
                    {
                        break;
                    }
                    BST_delete1(&T, info);
                    printf("Great! Delete successfully!(-1 to quit):\n");
                }
                printf("Show the current data:\n");
                BST_preorderI(T);
                printf("\nGreat! Test DeleteNode successfully.\n");
                system("pause");
                break;
            case 3:
                system("cls");
                length = 0;
                printf("\nTest PreOrderTraverse module\n");
                BST_preorderI(T);
                printf("\nGreat! Test PreOrderTraverse successfully.\n");
                system("pause");
                break;
            case 4:
                system("cls");
                info = 0;
                printf("\nTest PreOrderLoop module\n");
                BST_preorderR(T);
                printf("\nGreat! Test PreOrderLoop successfully.\n");
                system("pause");
                break;
            case 5:
                system("cls");
                printf("\nTest InOrderTraverse module\n");
                BST_inorderI(T);
                printf("\nGreat! Test InOrderTraverse successfully.\n");
                break;
            case 6:
                system("cls");
                printf("\nTest InOrderLoop module\n");
                BST_inorderR(T);
                printf("\nGreat! Test InOrderLoop successfully.\n");
                system("pause");
                break;
            case 7:
                system("cls");
                printf("\nTest PostOrderTraverse module\n");
                BST_postorderI(T);
                printf("\nGreat! Test PostOrderTraverse successfully.\n");
                system("pause");
                break;
            case 8:
                system("cls");
                printf("\nTest PostOrderLoop module\n");
                BST_postorderR(T);
                printf("\nGreat! Test PostOrderLoop successfully.\n");
                system("pause");
                break;
            case 9:
                system("cls");
                printf("\nTest LevelTraversal module\n");
                BST_levelOrder(T);
                printf("\nGreat! Test LevelTraversal successfully.\n");
                system("pause");

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
void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\tPlease enter your choice:\n");
    while(1)
    {
        getchar();
        while(scanf("%d",&temp) != 1)
        {
            getchar();
            printf("The input is illegal, please re-enter.Thanks.--:\n");
        }
        if(temp==1)
        {
            system("cls");
            printf("\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\tSafely exited the system\n");
            printf("\t\t\tThank you for using!  <_>\n");
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
    printf("\t\t\t|    1.InsertTree                |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    2.DeleteNode                |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    3.PreOrderTraverse          |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    4.PreOrderLoop              |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    5.InOrderTraverse           |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    6.InOrderLoop               |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    7.PostOrderTraverse         |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    8.PostOrderLoop             |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    9.LevelTraversal            |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    10.Quit                     |\n");
    printf("\t\t\t|                                |\n");
    printf("\n\t\t\nPlease enter your choice(1 to 10) Thanks!\n");
}

//Stack
Status init_stack(SeqStackPtr S)
{
    S->top = NULL;
    S->count = 0;
    return succeed;
}

/* Stack structure operation: push into the stack */
Status push_stack(SeqStackPtr S, NodePtr T)
{
    if (!T)
        return failed;

    NodeStackPtr node = (NodeStackPtr)malloc(sizeof(NodeStack));
    node->data = T;
    node->next = S->top;

    S->top = node;
    ++S->count;
    return succeed;
}

/* Stack structure operation: pop */
NodePtr pop_stack(SeqStackPtr S)
{
    if (S->count <= 0)
        return NULL;

    NodeStackPtr top = S->top;
    NodePtr node = top->data;

    S->top = top->next;
    free(top);

    top = NULL;
    --S->count;

    return node;
}
NodePtr top_stack(SeqStackPtr S)
{
    if (S->count <= 0)
        return NULL;
    return S->top->data;
}
Status free_stack0(NodeStackPtr node)
{
    if (!node)
        return failed;

    free_stack0(node->next);
    free(node);
    node = NULL;
    return succeed;
}
Status print_stack0(NodeStackPtr node)
{
    if (!node)
        return failed;
    print_stack0(node->next);
    printf("%d ", node->data->value);
    return succeed;
}

/* for insert */
NodePtr FindElem_insert(NodePtr T, ElemType e)
{
    if (T->value == e)
        return T;

    if (T->value < e)
    {
        if (T->right == NULL)
            return T;
        return FindElem_insert(T->right, e);
    }

    if (T->value > e)
    {
        if (T->left == NULL)
            return T;
        return FindElem_insert(T->left, e);
    }

    return NULL;
}

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(NodePtr *T)
{
    assert(T);
    if(*T == NULL)
        return failed;
    *T = NULL;
    return succeed;
}


/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */


Status BST_insert(NodePtr *T, ElemType e)
{
    /*if tree not exist, found new tree and give value to root, or insert e */
    NodePtr Tree = (NodePtr)calloc(1,sizeof (Node));
    Tree->value = e;
    if(*T == NULL)
    {
        *T = Tree;
        return failed;
    }
    NodePtr root = FindElem_insert(*T,e);
    if(root == NULL)
    {
        return succeed;
    }

    if(root->value < e)
    {
        root->right = Tree;
    }
    else if(root->value > e)
    {
        root->left = Tree;
    }
    else
    {
        printf("Node %d already exists\n",e);
        free(Tree);
        Tree = NULL;
        return succeed;
    }
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete0(NodePtr *T)
{
    NodePtr p = (*T)->left,q = (*T)->right;
    // delete node, connect left tree
    if(q == NULL)
    {
        free(*T);
        *T = q;
        return succeed;
    }
    // delete node, connect right tree
    if(p == NULL)
    {
        free(*T);
        *T = q;
        return succeed;
    }
    /* After the tree T is traversed in order,
       the next node f of node e is assigned to e,
       and f is deleted. */
    while (q->left != NULL)
    {
        p = q;
        q = q->left;
    }

    (*T)->value = q->value;
    p->value = q->value;
    free(q);
    return succeed;
}
Status BST_delete1(NodePtr *T, ElemType e)
{
    if (*T == NULL)
        return succeed;

    if ((*T)->value == e)
        BST_delete0(T);
    else if ((*T)->value > e)
        BST_delete1(&(*T)->left, e);
    else
        BST_delete1(&(*T)->right, e);

    return succeed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
//Status BST_search(NodePtr *T, ElemType e)
//No use

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T)
{
    if (!T)
        return succeed;
    SeqStack S;
    init_stack(&S);
    while (T || S.count != 0)
    {
        while (T)
        {
            printf("%d ", T->value);
            push_stack(&S, T);
            T = T->left;
        }

        T = pop_stack(&S);
        T = T->right;
    }
    printf("\n");
    return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr T)
{
    if (!T)
        return failed;
    printf("%d ", T->value);
    BST_preorderI(T->left);
    BST_preorderI(T->right);
    return succeed;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T)
{
    if (!T)
        return failed;
    SeqStack S;
    init_stack(&S);

    while (T || S.count != 0)
    {
        while (T)
        {
            push_stack(&S, T);
            T = T->left;
        }

        T = pop_stack(&S);
        printf("%d ", T->value);
        T = T->right;
    }
    printf("\n");
    return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr T)
{
    if (!T)
        return failed;
    BST_inorderI(T->left);
    printf("%d ", T->value);
    BST_inorderI(T->right);
    return succeed;
}

/**
 * BST postorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T)
{
    if (!T)
        return failed;

    SeqStack S;
    init_stack(&S);

    NodePtr p = T, r = NULL;
    while (p || S.count > 0)
    {
        /* p is not empty, put node p on the stack,
           and perform the next round of looping
           until all the left subtrees are on the stack. */
        if (p)
        {
            push_stack(&S, p);
            p = p->left;
        }

            // p null.
        else
        {
            // Assign the top of the stack to p
            p = top_stack(&S);

            /* If the right subtree of p is empty, then output p node.
               And point r to p, p is set to empty. */
            /* If the right subtree of p has been output, then output p node.
               And set r to p, p is set to empty. */
            /* Otherwise, put the right subtree into the stack, and assign the left subtree to p,
               and proceed to the next round of loop. */
            /* Where r represents the last output node. */

            if (!p->right || p->right == r)
            {
                r = pop_stack(&S);
                printf("%d ", p->value);
                r = p;
                p = NULL;
            }
            else
            {
                p = p->right;
                push_stack(&S, p);
                p = p->left;
            }
        }
    }

    printf("\n");
    return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr T)
{
    if (!T)
        return failed;
    BST_postorderI(T->left);
    BST_postorderI(T->right);
    printf("%d ", T->value);
    return succeed;
}

// for levelOrder
Status init_queue(SeqQueuePtr Q)
{
    Q->back = NULL;
    Q->front = NULL;
    Q->count = 0;
    return succeed;
}
Status push_queue(SeqQueuePtr Q, NodePtr T)
{
    if (!T)
        return failed;

    NodeStackPtr node = (NodeStackPtr)malloc(sizeof(NodeStack));
    node->data = T;
    node->next = NULL;

    if (Q->count == 0)
    {
        Q->front = node;
        Q->back = node;
    }
    else
    {
        Q->back->next = node;
        Q->back = node;
    }

    ++Q->count;
    return succeed;
}
NodePtr pop_queue(SeqQueuePtr Q)
{
    if (Q->count <= 0)
        return NULL;

    NodeStackPtr node = Q->front;
    NodePtr data = node->data;

    Q->front = node->next;
    --Q->count;

    free(node);
    node = NULL;

    return data;
}
/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr T)
{
    if (!T)
        return failed;

    SeqQueue Q;
    init_queue(&Q);

    while (1)
    {
        /* Root node output */
        if (Q.count == 0)
        {
            printf("%d ", T->value);
            if (T->left != NULL)
                push_queue(&Q, T->left);
            if (T->right != NULL)
                push_queue(&Q, T->right);
        }

        int i = 0, cnt = Q.count;
        for (; i < cnt; ++i)
        {
            NodePtr data = pop_queue(&Q);
            if (data->left != NULL)
                push_queue(&Q, data->left);
            if (data->right != NULL)
                push_queue(&Q, data->right);
            printf("%d ", data->value);
        }

        if (Q.count == 0)
            break;
    }
    printf("\n");
    return succeed;
}


int main()
{
    Menu();
    return 0;
}
