#include <cstdio>
#include <cstdlib>
#include "io.h"
#include <cmath>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 用于构造二叉树********************************** */
int index=1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

Status StrAssign(String T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSIZE)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
            T[i]=*(chars+i-1);
        return OK;
    }
}
/* ************************************************ */

typedef int TElemType;

Status visit(TElemType e)
{
    printf("%c ",e);
    return OK;
}

typedef struct BSTNode  /* 结点结构 */
{
    TElemType data;		/* 结点数据 */
    struct BSTNode *lchild,*rchild; /* 左右孩子指针 */
}BSTNode,*BSTree;


/* 构造空二叉树T */
Status InitBiTree(BSTree *T)
{
    *T=NULL;
    return OK;
}

/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BSTree *T)
{
    if(*T)
    {
        if((*T)->lchild) /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
        if((*T)->rchild) /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
        free(*T); /* 释放根结点 */
        *T=nullptr; /* 空指针赋0 */
    }
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
Status CreateBSTree(BSTree &s,TElemType e)
{
    s = (BSTNode* )malloc(sizeof(BSTNode));
    if(nullptr==s) return OVERFLOW;
    s->data = e;
    s->lchild= nullptr;
    s->rchild = nullptr;
    return TRUE;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BSTreeEmpty(BSTree T)
{
    if(T)
        return FALSE;
    else
        return TRUE;
}

#define ClearBiTree DestroyBiTree

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BSTreeDepth(BSTree T)
{
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=BSTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=BSTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
TElemType Root(BSTree T)
{
    if(BSTreeEmpty(T))
        return 0;
    else
        return T->data;
}

/* 初始条件: 二叉树T存在，p指向T中某个结点 */
/* 操作结果: 返回p所指结点的值 */
TElemType Value(BSTree p)
{
    return p->data;
}

/* 给p所指结点赋值为value */
void Assign(BSTree p,TElemType value)
{
    p->data=value;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BSTree T)
{
    if(T==nullptr)
        return;
    printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}


// 查询值为 key 的节点，有则放回该节点指针，无则 NULL
BSTree SearchBST(BSTree T, TElemType key) {
    if (T == nullptr) return nullptr;

    if (key == T->data) return T;
    if (key < T->data) return SearchBST(T->lchild, key);
    return SearchBST(T->rchild, key);
}

// 插入一个记录到查询二叉树中
Status InsertBST(BSTree &T, TElemType key) {
    // 空树的话，则该节点作为根节点
    if (T == nullptr)
    {
        auto root = (BSTree)malloc(sizeof(BSTNode));
        if(root == nullptr) return OVERFLOW;
        root->data = key;
        root->lchild = nullptr;
        root->rchild = nullptr;
        T = root;
        return OK;
    }

    // 非空的话，判断大小递归插入
    if (key < T->data) return InsertBST(T->lchild, key);
    return InsertBST(T->rchild, key);
}

// 删除查找二叉树指定节点
void DeleteNode(BSTree& p) {
    BSTree q, s;
    q = p;
    if (p->lchild == nullptr) {
        // 左子树为空，将右子树置为双亲
        p = p->rchild;
        free(q);
    }
    else if (p->rchild == nullptr) {
        // 右子树为空，将左子树置为双亲
        p = p->lchild;
        free(q);
    }
    else {
        // 左右子树都不为空，寻找该节点的直接前驱
        s = p->lchild;
        // 一直找到最右的子树
        while (s->rchild != nullptr) {
            q = s;
            s = s->rchild;
        }

        // 将直接前驱的值赋给当前节点
        p->data = s->data;
        // 如果 s 节点是要删除节点的左孩子
        if (q == p) q->lchild = s->lchild;
        else q->rchild = s->lchild;
        free(s);
    }
}

// 删除值为 key 的节点
Status DeleteBST(BSTree T, TElemType key) {
    // 找到该节点
    BSTree result = SearchBST(T, key);

    // 找不到则返回错误
    if (result == nullptr) return FALSE;

    // 否则删除
    DeleteNode(result);
    return TRUE;
}

// 二叉树的递归查找
BSTree SearchBST_1(BSTree T,TElemType key, BSTree &par)
{
    // 二叉查找树递归查找 查找+插入+删除
    // 查找 （找到结点指针）+ 插入或者删除（找到结点双亲）
    // 能够返回两个值
    if (T == nullptr) return nullptr;

    if (key == T->data) return T;
    par = T;
    if (key < T->data) return SearchBST_1(T->lchild, key,par);
    return SearchBST_1(T->rchild, key,par);
}



int main()
{
    int i;
    BSTree T;
    TElemType e1;
    InitBiTree(&T);

//
//    StrAssign(str,"1234#K###5##678###9#J##");

    CreateBSTree(T,88);
    CreateBSTree(T,47);
    CreateBSTree(T,98);
    CreateBSTree(T,19);
    CreateBSTree(T,55);

    printf("\nTraverse:\n");
    PreOrderTraverse(T);

//    ClearBiTree(&T);

    i=Root(T);
    if(!i)
        printf("No Root\n");

    return 0;
}

