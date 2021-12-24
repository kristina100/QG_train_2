#include <stdio.h>
#include "Common.h"
int main() {
    SqList L;
    int e = 0;
    printf("%d\n",InitList(&L,10));
    printf("%d\n", ClearList(&L));
    printf("%d\n", ListEmpty(L));
    printf("%d\n", ListLength(L,&e));
    return 0;
}
