#include "Commn.h"

int main()
{
    Menu0();
    Menu();
    return 0;
//    int lev = 1 ,dep = 0;
//    CSTree T,T1,T2,T3,T4,T5, T0;
//
//    T5 = MakeTree('E',0);
//    T4 = MakeTree('F',0);
//    T3 = MakeTree('D',1,T4);
//    T2 = MakeTree('C',0);
//    T1 = MakeTree('B',1,T5);
//    T = MakeTree('A',3,T1,T2,T3);
//
//    printf("shape of tree:\n");
//    PrintfTree(T,3);
//    printf("The Whole Tree Count Leaves:%d\n",CountLeaves1(T));
//    PostOrderTraverse(T,lev,dep);
//    printf("depth_1:%d\n",dep);
//    PreOrderTraverse(T);
//    printf("\n");
//    LayerOrderCSTree(T);
//    printf("depth_2:%d\n",PostOrderTraverse_2(T));
//    printf("depth_3:%d\n", PostOrderTraverse_3(T));
//    T0 = MakeTree('K',0);
//
//    DeleteChild(T,'B');
//    InsertChild(T,2,T0,'D');
//    PostOrderTraverse(T,lev,dep);
//    DestroyTree(&T);
//    CSTree p = Search(T,'H');
//    DeleteChild(&T,p,1);
//    PrintfTree(T,dep);
}
