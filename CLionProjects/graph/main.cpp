#include <cstdio>
#include <string.h>
#define MaxVertexNum  100   //顶点数目最大值
typedef char VertexType;   //顶点的数据类型
typedef int EdgeType;     //带权图中边上权值的数据类型
#include <iostream>
#include<cstdarg>

using namespace std;
typedef struct
{
    VertexType Vex[MaxVertexNum];   //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
    int vexnum, edgenum;    //图的顶点数和弧数
}MGraph;

/**********创建无向图**********/
void create_Graph(MGraph *G)
{
    int i, j;
    int start, end;  //边的起点序号、终点序号
    int numV, numE;
    int w;   //边上的权值
    printf("Please enter the number of vertices and edges of the created undirected graph (separated by spaces):");
//    printf("请输入所创建无向图的顶点数和边数(用空格隔开):");
    cin >> numV >> numE;
    G->vexnum=numV;
    G->edgenum=numE;

    printf("\n");
    //图的初始化
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            if (i == j)
                G->Edge[i][j] = 0;
            else
                G->Edge[i][j] = 32767;
        }
    }

    //顶点信息存入顶点表
    for (i = 0; i < G->vexnum; i++)
    {
//        printf("请输入第%d个顶点的信息:",i+1);
        printf("Please enter the information of the %dth vertex:\n",i+1);
        cin>> G->Vex[i];
    }
    printf("\n");
    //输入无向图边的信息
    for (i = 0; i < G->edgenum; i++)
    {
        printf("Please enter the starting serial number, ending serial number, and weight of the edge (separated by spaces).");
//        printf("请输入边的起点序号，终点序号，权值(用空格隔开)：");
        cin >> start >> end >> w;
        G->Edge[start -1][end -1] = w;
        G->Edge[end - 1][start - 1] = w;   //无向图具有对称性
    }
}

/***********打印出邻接矩阵*********/
void print_Matrix(MGraph G)
{
    int i, j;
//    printf("\n图的顶点为:");
    printf("The vertices of the graph are :\n");
    for (i = 0; i < G.vexnum; i++)
        printf("%d ", G.Vex[i]);
    printf("\nOutput adjacency matrix:\n");
//    printf("\n输出邻接矩阵:\n");
    printf("\t");
    for (i = 0; i < G.vexnum; i++)
        printf("\t%8d", G.Vex[i]);

    for (i = 0; i < G.vexnum; i++)
    {
        printf("\n\n%8d", G.Vex[i]);
        for (j = 0; j < G.vexnum; j++)
        {
            if (G.Edge[i][j] == 32767)
                printf("\t%8s", "∞");
            else
                printf("\t%8d", G.Edge[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph G;
    create_Graph(&G);
    print_Matrix(G);
    system("pause");
    return 0;
}