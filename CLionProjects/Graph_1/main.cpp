#include <iostream>
#include"ALGraph.h"
#include"MGraph.h"
#include <stdlib.h>
#define N 100

void PrintUG(MGraph G) {

    for (int i = 0; i < G.n; i++) {
        printf("%c ", G.vexs[i]);
    }
    printf("\n");

    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++)
            printf("%d ", G.arcs[i][j]);
        printf("\n");
    }
}

void PrintG(MGraph G) {
    for (int i = 0; i < G.n; i++)
    {
        printf("%c->", G.vexs[i]);
        for (int j = 0; j < G.n; j++)
        {
            for (int k = 0; k < G.n; k++)
            {
                if (G.arcs[j][k] == 1 && i == j)
                {
                    printf(" %d", k);
                }
            }
        }
        printf("\n");
    }
}

//void PrintG_AL(ALGraph G) {
//    for (int i = 0; i < G.n; i++)
//    {
//        printf("%c->", G.vexs[i].data);
//        for (int j = 0; j < G.n; j++)
//        {
//            for (int k = 0; k < G.n; k++)
//            {
//                if (G.arcs[j][k] == 1 && i == j)
//                {
//                    printf(" %d", k);
//                }
//            }
//        }
//        printf("\n");
//    }
//}

int path[N];
int visits[N];
int main()
{
    system("color 07");
    MGraph G2;
    // G2 无向
    VexType vexs[4] = {'A', 'B', 'C', 'D'};
    ArcInfo arcs[6] = {{'A', 'B', 0}, {'A', 'D', 0}, {'A', 'C', 0}, {'C', 'D', 0},{'B', 'D', 0},{'B', 'C', 0}};
    CreateGraph_M(G2, UDG, vexs, 4, arcs, 6);
    // G1 有向
    VexType vexs1[5] = {'A', 'B', 'C', 'D','E'};
    MGraph G1;
    ArcInfo arcsG1[6] = { {'A','C',0},{'A','D',0} ,{'B','A',0} ,{'B','D',0},{'C','D',0},{'B','E',0} };
    CreateGraph_M(G1, DG, vexs1, 5, arcsG1, 6);
    printf("G2:\n");
    PrintUG(G2);
    printf("DFS_Traverse1:\n");
    DFS_M(G2,1);
    printf("DFS_Traverse2:\n");
    DFSTraverse_M(G2);
    printf("\n\nG1:\n");
    PrintUG(G1);
    int count = 0;
    int num = 0;
//    printf("isReachable = %d\n",isReachable_DFS(G2,1,3,path,count));
    AllReachable_DFS(G2,0,2,path,count,visits);












//    FirstAdjVex_M(G2,1);
//    printf("UDG:%d\n",Degree(G2,1));
//    printf("DG:%d\n",Degree(G1,1));
//    VexType vexs2[4] = { 'A', 'B', 'C', 'D' };
//    ArcInfo arcsG3[12] = { {'A', 'C', 1},{'C', 'A', 1},
//                           {'A', 'D', 1},{'D', 'A', 1},
//                           {'C', 'D', 1}, {'D', 'C', 1},
//                           {'B', 'A', 1}, {'A', 'B', 1},
//                           {'B', 'D', 1}, {'D', 'B', 1},
//                           {'B', 'C', 1}, {'C', 'B', 1}};
//    ALGraph G3;
//
//    createDG_AL(G3,vexs2,4,arcsG3,12);
//    DFS(G3,2);
//    DFSTraverse(G3);
//    printf("List  degree DG:%d\n",inDegree(G3,0));
//    printf("List  degree UDG:%d\n",inDegree(G4,0));
    return 0;
}

