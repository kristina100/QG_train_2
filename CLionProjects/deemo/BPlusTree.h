//
// Created by HUAWEI on 2021-12-21.
//

#ifndef DEEMO_BPLUSTREE_H
#define DEEMO_BPLUSTREE_H
#ifndef __BPlusTree_H__
#define __BPlusTree_H__

#define MAX_CHILD_NUMBER 3200

typedef struct BPlusTreeNode {
    int isRoot, isLeaf;
    int key_num;
    int key[MAX_CHILD_NUMBER];
    int pos[MAX_CHILD_NUMBER];
    void* child[MAX_CHILD_NUMBER];
    struct BPlusTreeNode* father;
    struct BPlusTreeNode* next;
    struct BPlusTreeNode* last;
} BPlusTreeNode;
int BPlusTree_Find(int key);
extern void BPlusTree_SetMaxChildNumber(int);
extern void BPlusTree_Init();
extern void BPlusTree_Destroy();
extern int BPlusTree_Insert(int, int, void*);
extern int BPlusTree_GetTotalNodes();
extern void BPlusTree_Query_Key(int);
extern void BPlusTree_Query_Range(int, int);
extern void BPlusTree_Modify(int, void*);
extern void BPlusTree_Delete(int);


void Destroy(BPlusTreeNode* Cur);
void Delete(BPlusTreeNode* Cur, int key);
void Print(BPlusTreeNode* Cur);
#endif

#endif //DEEMO_BPLUSTREE_H
