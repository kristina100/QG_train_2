//
// Created by HUAWEI on 2021-12-03.
//

#include <iostream>
#include "Commn.h"
#include<cstdarg>

using namespace std;

/** 构造树 */
CSTree MakeTree(TElemType e,int n,...)
{
    int i;
    CSTree t,p,pi;
    va_list argptr;
    t=(CSTree)malloc(sizeof(CSTNode));
    if(nullptr==t)return nullptr;
    t->data = e;//根结点的值为e
    t->firstChild = t->nextSibling = nullptr;
    if(n<=0) return t;
    va_start(argptr,n);
    p=va_arg(argptr,CSTree);
    t->firstChild=p;
    pi=p;
    for(i=1;i<n;i++)
    {
        p=va_arg(argptr,CSTree);
        pi->nextSibling = p;
        pi = p;
    }
    va_end(argptr);
    return t;
}

/** 四种遍历 前序遍历 中序遍历 后序遍历 层序遍历*/
void PreOrderTraverse(CSTree T)
{
    if(T==nullptr)
        return;
    printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->firstChild);
    PreOrderTraverse(T->nextSibling); /* 最后先序遍历右子树 */
}
void InOrderTraverse(CSTree T)
{
    if(T==nullptr)
        return;
    InOrderTraverse(T->firstChild);
    printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
    InOrderTraverse(T->nextSibling); /* 最后先序遍历右子树 */
}
void postOrderTraverse(CSTree T)
{
    if(T==nullptr)
        return;
    postOrderTraverse(T->firstChild);
    postOrderTraverse(T->nextSibling); /* 最后先序遍历右子树 */
    printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}
void LayerOrderCSTree(CSTree T)
{
    int curLayerCount = 0; //当前层中的节点数
    int nextLayerCount = 0; //下一层中的节点数
    LinkQueue* queue = InitQueue();
    EnQueue(queue, T);
    curLayerCount++;
    CSTree p;
    p = DeQueue(queue);
    while (p)
    {
        curLayerCount--;
        printf("%c ", p->data);
        if (p->firstChild)
        {
            EnQueue(queue, p->firstChild);
            nextLayerCount++;
        }
        if (p->nextSibling)
        {
            EnQueue(queue, p->nextSibling);
            nextLayerCount++;
        }
        if (curLayerCount == 0)//一层已经遍历完毕
        {
            curLayerCount = nextLayerCount;
            nextLayerCount = 0;
            printf("\n");
        }
        p = DeQueue(queue);
    }
}

/** 打印树形(转化为二叉树) */
void PrintfTree(CSTree T,int H) {
    if(T==nullptr) return;

    PrintfTree(T->nextSibling,H+1);
    for (int i=0;i<H;++i) printf("    ");
    printf("%c\n",T->data);
    PrintfTree(T->firstChild,H+1);
}

/** 叶子结点数*/
int CountLeaves1(CSTree T) {
    // 返回叶子节点的数目
    int num = 0;
    CSTree root;
    // 结束：
    if (T == nullptr) return 0;
    if (T->firstChild == nullptr) num++;

    root = T->firstChild;
    // 分解：
    // 问题规模： 根、若干子树
    // 问题：子树的叶子节点的个数
    while(root != nullptr)
    {
        // 注意判断根节点是不是叶子节点
        num += CountLeaves1(root);
        root = root->nextSibling;
    }
    // 组合：
    return num;
}

/** 得到树的深度 */
// 递归
void PostOrderTraverse(CSTree t,int lev,int &dep)
{
    //lev代表当前t结点所在的层次（遍历到的层次）
    if(nullptr==t)return;
    PostOrderTraverse(t->firstChild,lev+1,dep);
    if(lev>dep)dep=lev;
    PostOrderTraverse(t->nextSibling,lev, dep);
}

// 分治法
int PostOrderTraverse_2(CSTree t)
{
    if(t==nullptr)return 0;

    int cDep,nDep;
    cDep=PostOrderTraverse_2(t->firstChild)+1;
    nDep=PostOrderTraverse_2(t->nextSibling);

    int MaxDep;
    if(cDep>nDep)MaxDep=cDep;
    else MaxDep=nDep;
    return MaxDep;
}

int PostOrderTraverse_3(CSTree t)
{
    //结束
    if(t==nullptr)return ERROR;
    //分解
    //问题规模：根+若干子树
    //问题：求子树的叶子结点数目
    int MaxDep=0;
    CSTree temp=t->firstChild;
    while(temp!=nullptr)
    {
        int tempDep;
        tempDep=PostOrderTraverse_3(temp);
        if(tempDep>MaxDep)
            MaxDep=tempDep;
        temp=temp->nextSibling;
    }
    // 组合：根节点（判断是否为叶子）
    return MaxDep+1;
}

/** 查找操作 */
CSTree Search(CSTree T,TElemType e)
{
    if(T == nullptr)
    {
        printf("Sorry, not the target node.\n");
        return nullptr;
    }
    if (T->data == e)
    {
        printf("Search Successfully ~ .\n");
        return T;
    }
    CSTree res;
    res = Search(T->firstChild,e);
    if(res!=nullptr)
    {
        printf("Search Successfully ~ .\n");
        return res;
    }
    return Search(T->nextSibling,e);
}

/** 插入操作 */
Status InsertChild(CSTree &T,int i, CSTree c,TElemType e)
{
    int j;
    CSTree p;
    if(nullptr==T)
    {
        printf("ERROR. the tree is empty ~\n");
        return ERROR;
    }
    if(i<1)
    {
        printf("ERROR. The number is out of range ~ \n");
        return ERROR;
    }
    //查找
    CSTree a = Search(T,e);
    if(a== nullptr)
    {
        printf("Sorry, the element is not exist ~ \n");
        return ERROR;
    }
    if(1==i)
    {
        c->nextSibling = a->firstChild;
        a->firstChild = c;
    }
    else
    {
        p=a->firstChild;
        for(j=2;p!=nullptr&&j<i;j++)
            p=p->nextSibling;
        if(p == nullptr)
        {
            printf("Insert i is too large ~\n");
            return ERROR;
        }
        if(j==i)
        {
            c->nextSibling=p->nextSibling;
            p->nextSibling = c;
        }
        else
        {
            printf("Insert i is too large ~\n");
            return ERROR;
        }
    }
    printf("Insert successfully.\n");
    return OK;
}

/** 删除操作 */
Status DeleteChild(CSTree *T, CSTree p, int i)
{ /* 初始条件: 树T存在,p指向T中某个结点,1≤i≤p所指结点的度 */
    /* 操作结果: 删除T中p所指结点的第i棵子树 */
    /* 因为p所指结点的地址不会改变，故p不需是引用类型 */
    CSTree b;
    int j;
    if (*T) /* T不空 */
    {
        if (i == 1) /* 删除长子 */
        {
            b = p->firstChild;
            p->firstChild = b->nextSibling; /* p的原次子现是长子 */
            b->nextSibling = nullptr;
            DestroyTree(&b);
        }
        else /* 删除非长子 */
        {
            p = p->firstChild; /* p指向长子 */
            j = 2;
            while (p&&j < i)
            {
                p = p->nextSibling;
                j++;
            }
            if (j == i && p!= nullptr) /* 找到第i棵子树 */
            {
                b = p->nextSibling;
                p->nextSibling = b->nextSibling;
                b->nextSibling = nullptr;
                DestroyTree(&b);
            }
            else /* p原有孩子数小于i */
            {
                printf("Number i is too large ~\n");
                return ERROR;
            }
        }
        printf("Delete successfully.\n");
        return OK;
    }
    else
    {
        printf("Fail to delete ~ \n");
        return ERROR;
    }
}

/** 销毁树 */
Status DestroyTree(CSTree *T)
{ /* 初始条件: 树T存在。操作结果: 销毁树T */
    if (*T)
    {
        if ((*T)->firstChild) /* T有长子 */
            DestroyTree(&(*T)->firstChild); /* 销毁T的长子为根结点的子树 */
        if ((*T)->nextSibling) /* T有下一个兄弟 */
            DestroyTree(&(*T)->nextSibling); /* 销毁T的下一个兄弟为根结点的子树 */
        free(*T); /* 释放根结点 */
        *T = nullptr;
        printf("one point free successfully ~ \n");
        return OK;
    }
    printf("Error, fail to destroy the tree.\n");
    return ERROR;
}

int InputInteger()
{
    int integer;
    int  status;
    char str[100];

    do {
        scanf("%s", str);
        status = OK;
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            /* 检查非法输入 */
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = ERROR;
            }
        }
        if (status == ERROR) {
            printf("Your input is illegal, please re-enter :");
            continue;
        } else {
            /* 将字符串转化为整型 */
            for (i = 0, integer = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        integer *= 10;
                        integer += (str[i] - 48);
                    }
                } else {
                    integer *= 10;
                    integer += (str[i] - 48);
                }
            }
            if (str[0] == '-') integer = -integer;

            /* 检查是否溢出 */
            if (i >= 10) {
                printf("Overflow, please re-enter:");
                status = ERROR;
            }
        }
    } while (status == ERROR);

    return integer;
}

CSTree T;

void Menu0()
{   printf("\n\n\n\n\t\t\t*----------------------------------------------------------*\n");
    printf("\t\t\t|             Welcome to Tomato's big work ~               |\n");
    printf("\t\t\t|                Some operations on trees ~                |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t|    1. Make Tree                    6. Insert Operation   |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t|    2. Visualization Tree           7. Delete Operation   |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t|    3. Traverse (Four methods)      8. Search Operation   |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t|    4. Get the Number of Nodes      9. Destroy the Tree   |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t|    5. Get Depth (Three methods)    10. Quit System       |\n");
    printf("\t\t\t|                                                          |\n");
    printf("\t\t\t*----------------------------------------------------------*\n");
    printf("\n\t\t\nPlease enter your choice(1 to 10) :\n");
}

void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t|      1.YES      2.NO       |\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\tPlease enter your choice:\n");
    while(true)
    {
        temp = InputInteger();
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
        else
            printf("The input is illegal, please re-enter.Thanks.--:");
    }
}

void Menu()
{
    int lev = 1 ,dep = 0;
    int info, length, counts,H,elem;
    CSTree P;
    int exist_flag = 0;  /* 标记树是否存在 */
    TElemType I,information, searchnum;
    while(true)
    {
        Menu0();
        switch (InputInteger()) {
            case 1:
                system("cls");
                printf("\nMake Tree.^_^\n");
                CSTree T1,T2,T3,T4,T5, T0;
                T5 = MakeTree('E',0);
                T4 = MakeTree('F',0);
                T3 = MakeTree('D',1,T4);
                T2 = MakeTree('C',0);
                T1 = MakeTree('B',1,T5);
                T = MakeTree('A',3,T1,T2,T3);
                exist_flag = 1;
                system("pause");
                break;
            case 2:
                system("cls");
                if(exist_flag) {
                    printf("\nVisualization Tree.^_^\n");
                    length = PostOrderTraverse_2(T);
                    PrintfTree(T, length);
                }
                printf("No  tree exists, please initialize first!\n");
                system("pause");
                break;
            case 3:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                int put2;
                printf("\nTraverse (Four methods).^_^\n");
                printf("1. PreOrderTraverse  2. InOrderTraverse  3. PostOrderTraverse  4. LayerOrderCSTree \n");
                put2 = InputInteger();
                if(put2 == 1)
                {
                    printf("PreOrderTraverse :\n");
                    PreOrderTraverse(T);
                }
                else if(put2 == 2)
                {
                    printf("InOrderTraverse:\n");
                    InOrderTraverse(T);
                    printf("\n");
                }
                else if(put2 == 3)
                {
                    printf("PostOrderTraverse:\n");
                    postOrderTraverse(T);
                }
                else if(put2 == 4)
                {
                    printf("LayerOrderTraverse:\n");
                    LayerOrderCSTree(T);
                }
                else
                {
                    printf("Not entered as required.");
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                system("cls");
                if(!exist_flag) printf("No  tree exists, please initialize first!\n");
                else
                {
                    info = 0;
                    printf("Get the Number of Nodes :\n");
                    counts = CountLeaves1(T);
                    printf("Successfully^_^! The count of leaves: %d.\n",counts);
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                int put3;
                printf("\nGet Depth (Three methods).^_^\n");
                printf("1. depth_1  2. depth_2  3. depth_3 \n");
                put3 = InputInteger();
                if(put3 == 1)
                {
                    PostOrderTraverse(T,lev,dep);
                    printf("Traverse  depth_1:%d\n",dep);

                }
                else if(put3 == 2)
                {
                    printf("Partition1 depth_2:%d\n",PostOrderTraverse_2(T));
                }
                else if(put3 == 3)
                {
                    printf("Partition2 depth_3:%d\n",PostOrderTraverse_3(T));
                }
                else
                {
                    cout << "input error ~ \n";
                }
                system("pause");
                break;
            case 6:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                CSTree c;
                cout << "Insert Operation ~ \n";
                cout << "Please insert your element:\n";
                cin >> information;
                c = MakeTree(information,0);
                cout << "Please enter the location you want to insert:\n ";
                elem = InputInteger();
                cout << "Which element do you want to insert into ? \n ";
                cin >> information;
                InsertChild(T,elem,c,information);
                PostOrderTraverse(T,lev,dep);
                PrintfTree(T,dep);
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                cout << "Before delete operation:\n";
                PostOrderTraverse(T,lev,dep);
                PrintfTree(T,dep);
                cout << "Which element do you want to delete the subtree under? Please enter:\n";
                cin >> I;
                cout << "enter the position you want to delete:\n";
                cin >> info;
                P = Search(T,I);
                if(P== nullptr)
                {
                    printf("The element is not exist ~ \n");
                    system("pause");
                    break;
                }
                DeleteChild(&T,P,info);
                PostOrderTraverse(T,lev,dep);
                PrintfTree(T,dep);
                printf("\n");
                system("pause");
                break;
            case 8:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                TElemType searchNum;
                cout << "Search Operation ~ \n";
                cout << "enter your element:\n";
                cin >> searchNum;
                P = Search(T,searchNum);
                if(P== nullptr)
                {
                    printf("The element is not exist ~ \n");
                    break;
                }
                PostOrderTraverse(T,lev,dep);
                PrintfTree(P,dep);
                printf("\n");
                system("pause");
                break;
            case 9:
                system("cls");
                if(!exist_flag)
                {
                    printf("No  tree exists, please initialize first!\n");
                    system("pause");
                    break;
                }
                printf("Destroy Operation:\n");
                cout << "Before destroy:\n";
                PostOrderTraverse(T,lev,dep);
                PrintfTree(T,dep);
                DestroyTree(&T);
                PostOrderTraverse(T,lev,dep);
                PrintfTree(T,dep);
                printf("\n");
                system("pause");
                break;
            case 10:
                system("cls");
                Quit();
                exit(0);
                break;
            default:
                cout << "Sorry, please enter a right integer:^_^ \n";
                break;
        }
    }
}