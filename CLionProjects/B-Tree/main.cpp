#include <iostream>

#include <cstdio>
#include <ctime>
#include "btree.h"

static void test();

static void putMessages();

int main() {
    putMessages();
    test();
    return 0;
}

static void test() {
    int treeLength;
    int keyArray[BTREELENGTH];
    BTree tree = nullptr;
    Record record;
    srand((unsigned) time(nullptr));
    treeLength = rand() % BTREELENGTH;
    //�Լ���������
    //scanf("%d", &n);
    printf("The max tree account :%d, tree length:%d\n", M, treeLength);
    for (int i = 0; i < treeLength; i++) {
        record.key = rand() % MAXINT;
        //�Լ�����
        //scanf("%d", &d.key);
        keyArray[i] = record.key;
        if (insertBTree(&tree, record))
            printf("\nfirst: %d record key: %d:\n", i + 1, record.key);
        else
            printf("\nfirst: %d record key%d: \n", i + 1, record.key);
        printTree(tree);
    }

    puts("\n");
    while(scanf("%d", &record.key)) {
        ResultVo result = searchNode(tree, record.key);
        if(result.tag) {
            printf("%d\n", result.i);
        } else {
            printf("û�иýڵ㡣\n");

        }
        puts(" ");
    }

    for (int i = 0; i < treeLength; i++) {
        record.key = keyArray[i];
        if (deleteNode(&tree, record.key))
            printf("\n %d %d:\n", i + 1, record.key);
        else
            printf("\n%d %d:\n", i + 1, record.key);
        printTree(tree);
    }
}

static void putMessages() {
    puts("---------------------------------------------------");
    puts("|    ID:3115004974    Class: FuXi |");
    puts("---------------------------------------------------\n");

    puts("---------------------------------------------------");
}