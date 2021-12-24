#include <iostream>


#include "CHashTable.h"

int hash(KeyType key, int size)
{
    return (3*key)%size;
}

void collision(int &hashValue, int hashSize)
{//线性探测法
    hashValue = (hashValue +1)% hashSize;
}

void TraverseCHashTable(CHashTable H)
{
    Node* np;
    int i;
    for(i = 0; i<H.size; i++)
    {
        printf("\n%d :", i);
        for(np = H.rcd[i]; np!=nullptr; np = np->next)
            printf(" %d ", np->r.key);
    }
}

int main()
{
    int a,b;
    char c;
    scanf("%c",&c);
    scanf("%d%c%d",&a,&c,&b);
    if(c)
//    /********链地址哈希表*********/
//    CHashTable H;
//    int (*h)(KeyType, int);
//    h = hash;
//    InitHash(H, 11, h);
//
//    RcdType data[] = {22, 41, 53, 46, 30, 13, 12, 67};
//    int i;
//    for(i = 0; i<8; i++)
//        InsertHash(H, data[i]);
//    TraverseCHashTable(H);
//
//    system("pause");
    return 0;
}