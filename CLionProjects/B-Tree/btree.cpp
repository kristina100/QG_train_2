//
// Created by HUAWEI on 2021-11-29.
//

#include <cstdio>
#include "btree.h"

static int searchKeyRange(BTree tree, int key);

static bool borrow(BTree tree);

static bool find(BTree tree, BTree *p, int *ans, Key k);

static void renewParent(BTree tree);

static int whichSon(BTree tree);

static void split(BTree tree);

/**
 * 初始化B树
 * @param tree
 */
void initBTree(BTree *tree) {
    (*tree) = nullptr;
}

bool isEmpty(const BTree tree) {
    return 0 == tree->keyNum;
}

bool isFull(const BTree tree) {
    return (M == tree->keyNum);
}


/**
 * 获取一个节点的元素数量
 * @param tree
 * @return
 */
int getkeyNumber(const BTree tree) {
    return tree->keyNum;
}


/**
 * 找到含有最大元素的B树节点
 * @param tree
 * @return
 */
BTree findMax(const BTree tree) {
    if (tree == nullptr)
        return nullptr;
    BTree p = tree;
    while (p->child[p->keyNum] != nullptr) {
        p = p->child[p->keyNum];
    }
    return p;
}

/**
 * 找到含有最大元素的B树节点的元素数量
 * @param tree
 * @return
 */
int findMaxNum(BTree tree) {
    if (tree == nullptr)
        return -1;
    BTree p = tree;
    while (p->child[p->keyNum] != nullptr) {
        p = p->child[p->keyNum];
    }
    return p->keyNum;
}

/**
 * 找到含有最小元素的B树节点
 * @param tree
 * @return
 */
BTree findMin(BTree tree) {
    if (tree == nullptr)
        return nullptr;
    BTree p = tree;
    while (p->child[0] != nullptr) {
        p = p->child[0];
    }
    return p;
}

/**
 * 插入B树节点
 */
bool insertBTree(BTree *tree, Record record) {
    BTree p = nullptr;
    int index, temp;
    bool flag;

    if (nullptr == (*tree)) {      //如果是空树
        (*tree) = (BTree) malloc(BTLEN);
        if (nullptr == (*tree)) return false;
        (*tree)->keyNum = 1;
        (*tree)->parent = nullptr;
        for (index = 0; index <= M; ++index) {
            (*tree)->child[index] = nullptr;
            (*tree)->keys[index] = 0;
        }
        (*tree)->keys[1] = record.key;
        return true;
    }
    flag = find(*tree, &p, &temp, record.key); //寻找插入节点
    if (flag)
        return false;
    else {  //直接插入
        p->keyNum++;
        for (index = p->keyNum; index > temp; --index) {
            p->keys[index] = p->keys[index - 1];
            p->child[index] = p->child[index - 1];
        }
        p->child[temp] = nullptr;
        p->keys[temp] = record.key;
        if (p->keyNum == M)
            split(p);
        renewParent(*tree);
        return true;
    }
    return false;
}

static void split(BTree tree) {
    BTree t1, t2;
    int index;

    t1 = (BTree) malloc(BTLEN);
    if (nullptr == t1) return;
    t2 = (BTree) malloc(BTLEN);
    if (nullptr == t2) return;

    t1->keyNum = M / 2;
    t2->keyNum = M - (M / 2) - 1;
    t1->parent = tree;
    t2->parent = tree;
    for (index = 0; index <= M; ++index) {  //全部初始化
        t1->child[index] = nullptr;
        t1->keys[index] = 0;
        t2->child[index] = nullptr;
        t2->keys[index] = 0;
    }
    for (index = 0; index <= M / 2; ++index) {  //初始化t1
        t1->child[index] = tree->child[index];
        t1->keys[index] = tree->keys[index];
    }
    t2->child[0] = tree->child[(M / 2) + 1];
    for (index = (M / 2) + 2; index <= M; ++index) {        //初始化t2
        t2->child[index - ((M / 2) + 1)] = tree->child[index];
        t2->keys[index - ((M / 2) + 1)] = tree->keys[index];
    }
    tree->keyNum = 1;
    tree->child[0] = t1;
    tree->child[1] = t2;
    tree->keys[1] = tree->keys[M / 2 + 1];
    for (index = 2; index <= M; ++index) {
        tree->child[index] = nullptr;
        tree->keys[index] = 0;
    }
}

/**
 * 寻找节点，结果封装在result中
 * @param tree
 * @param key
 * @return
 */
ResultVo searchNode(const BTree tree, int key) {
    int i = 0;
    bool found = false;
    BTree cur = tree;
    BTree parent = nullptr;
    ResultVo result;

    while (cur && 0 == found) {
        i = searchKeyRange(cur, key);

        if (i <= cur->keyNum && cur->keys[i] == key)
            found = true;
        else {
            parent = cur;
            cur = cur->child[i - 1];
        }
    }

    if (found) {
        result.pt = cur;
        result.i = i;
        result.tag = true;
    } else {
        result.pt = parent;
        result.i = i;
        result.tag = false;
    }

    return result;
}

static int searchKeyRange(BTree tree, int key) {
    int i = 1;
    while (i <= tree->keyNum && key > tree->keys[i])
        ++i;
    return i;
}

/**
 * 删除节点
 */
bool deleteNode(BTree *tree, Key key) {
    BTree p, maxNode;
    int num, temp, index;
    if ((*tree) == nullptr)
        return false;
    if (!find((*tree), &p, &temp, key))
        return false;
    if (p->child[temp] == nullptr) {
        for (index = temp; index <= p->keyNum; ++index) {
            p->keys[index] = p->keys[index + 1];
            p->child[index] = p->child[index + 1];
        }
        p->keyNum--;
        if (p->keyNum == (M + 1) / 2 - 2) {
            //调用借兄弟的函数
            if (!borrow(p)) (*tree) = nullptr;
            else renewParent(*tree);
        }
        return true;
    } else {
        //遍历
        maxNode = findMax(p->child[temp]);
        num = findMaxNum(p->child[temp]);
        p->keys[temp] = maxNode->keys[num];
        maxNode->keys[num] = 0;
        maxNode->keyNum--;
        if (maxNode->keyNum == (M + 1) / 2 - 2) {
            //调用借兄弟的函数
            if (!borrow(maxNode)) (*tree) = nullptr;
            else renewParent(*tree);
        }
        return true;
    }
}

/**
 * 寻找父节点
 * @param tree
 */
static void renewParent(BTree tree) {
    int index;
    if (tree == nullptr) return;
    for (index = 0; index <= tree->keyNum; ++index) {
        if (tree->child[index] != nullptr) {
            tree->child[index]->parent = tree;
            renewParent(tree->child[index]);
        }
    }
}

/**
 * 借节点
 * @param tree
 * @return
 */
static bool borrow(BTree tree) {
    int mynum, bronum, index;
    BTree b = nullptr, f = nullptr;
    if (tree == nullptr) return false;
    f = tree->parent;
    if (f == nullptr)//考虑父亲结点不存在的情况
    {
        if (tree->keyNum == 0) {
            f = tree->child[0];
            if (f == nullptr) {
                free(tree);
                return false;
            }
            for (index = 0; index <= f->keyNum; index++) {
                tree->keys[index] = f->keys[index];
                tree->child[index] = f->child[index];
            }
            tree->keyNum = f->keyNum;
            free(f);
            renewParent(tree);
        }
        return true;
    }
    mynum = whichSon(tree);
    if (mynum == 0)
        bronum = 1;
    else
        bronum = mynum - 1;
    b = f->child[bronum];

    if (!b)
        for (auto & i : f->child)
            if (i)
                b = i;

    if (b->keyNum == (M + 1) / 2 - 1) {
        //如果兄弟帮不了你了那么就和这个兄弟合体
        if (bronum < mynum) {  //如果我不是第一个
            b->keyNum++;
            b->keys[b->keyNum] = f->keys[mynum];
            b->child[b->keyNum] = tree->child[0];
            for (index = 1; index <= tree->keyNum; index++) {
                b->keys[index + b->keyNum] = tree->keys[index];
                b->child[index + b->keyNum] = tree->child[index];
                b->keyNum++;
            }
            free(tree);
            for (index = mynum; index <= f->keyNum; index++) {
                f->keys[index] = f->keys[index + 1];
                f->child[index] = f->child[index + 1];
            }
            f->keyNum--;
        } else {
            tree->keyNum++;
            tree->keys[tree->keyNum] = f->keys[bronum];
            tree->child[tree->keyNum] = b->child[0];
            for (index = 1; index <= b->keyNum; index++) {
                tree->keys[index + tree->keyNum] = b->keys[index];
                tree->child[index + tree->keyNum] = b->child[index];
                tree->keyNum++;
            }
            free(b);
            for (index = bronum; index <= f->keyNum; index++) {
                f->keys[index] = f->keys[index + 1];
                f->child[index] = f->child[index + 1];
            }
            f->keyNum--;
        }
        renewParent(f);
        if (f->keyNum == (M + 1) / 2 - 2) {
            //调用借兄弟的函数
            return borrow(f);
        }
    } else {  //如果兄弟能够帮你
        if (bronum < mynum) {  //如果我不是第一个
            for (index = 1; index <= tree->keyNum; index++) {
                tree->keys[index + 1] = tree->keys[index];
                tree->child[index + 1] = tree->child[index];
            }
            tree->child[1] = tree->child[0];
            tree->keys[1] = f->keys[mynum];
            tree->child[0] = b->child[b->keyNum];
            tree->keyNum++;
            f->keys[mynum] = b->keys[b->keyNum];
            b->keys[b->keyNum] = 0;
            b->child[b->keyNum] = nullptr;
            b->keyNum--;

        } else { //如果我是第一个
            tree->keyNum++;
            tree->keys[tree->keyNum] = f->keys[1];
            tree->child[tree->keyNum] = b->child[0];
            f->keys[1] = b->keys[1];
            b->child[0] = b->child[1];
            for (index = 1; index <= b->keyNum; index++) {
                b->keys[index] = b->keys[index + 1];
                b->child[index] = b->child[index + 1];
            }
            b->keyNum--;
        }
    }
    return true;
}

static int whichSon(BTree tree) {
    int index = -1;
    for (index = 0; index <= tree->parent->keyNum; ++index) //找出是父亲的第几个孩子
    {
        if (tree->parent->child[index] == tree) return index;
    }
    return -1;
}

/**
 * 寻找一个节点用于插入或者删除。
 * @param tree
 * @param p
 * @param ans
 * @param k
 * @return
 */
static bool find(BTree tree, BTree *p, int *ans, Key k) {
    BTree q;
    int index = 1;
    Key keynow;
    if (tree == nullptr)
        return false;
    q = tree;
    keynow = tree->keys[1];
    while (q != nullptr) {   //深度的遍历
        index = 1;
        keynow = q->keys[index];
        while (index <= q->keyNum) {   //节点内对各真值进行遍历
            if (k == keynow) {   //找到元素
                *p = q;
                *ans = index;
                return true;
            }
            if (k > keynow) {
                if (index == q->keyNum) {
                    if (q->child[index] == nullptr) {
                        *p = q;
                        *ans = q->keyNum + 1;
                        return false;
                    }
                    q = q->child[index];
                    break;
                }
                ++index;
                keynow = q->keys[index];
                continue;
            }
            if (k < keynow) {
                if (q->child[index - 1] == nullptr) {
                    *p = q;
                    *ans = index;
                    return false;
                }
                q = q->child[index - 1];
                break;
            }
        }
    }
    return false;
}