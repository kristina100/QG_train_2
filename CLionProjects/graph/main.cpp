#include <cstdio>
#include <string.h>
#define MaxVertexNum  100   //������Ŀ���ֵ
typedef char VertexType;   //�������������
typedef int EdgeType;     //��Ȩͼ�б���Ȩֵ����������
#include <iostream>
#include<cstdarg>

using namespace std;
typedef struct
{
    VertexType Vex[MaxVertexNum];   //�����
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //�ڽӾ��󣬱߱�
    int vexnum, edgenum;    //ͼ�Ķ������ͻ���
}MGraph;

/**********��������ͼ**********/
void create_Graph(MGraph *G)
{
    int i, j;
    int start, end;  //�ߵ������š��յ����
    int numV, numE;
    int w;   //���ϵ�Ȩֵ
    printf("Please enter the number of vertices and edges of the created undirected graph (separated by spaces):");
//    printf("����������������ͼ�Ķ������ͱ���(�ÿո����):");
    cin >> numV >> numE;
    G->vexnum=numV;
    G->edgenum=numE;

    printf("\n");
    //ͼ�ĳ�ʼ��
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

    //������Ϣ���붥���
    for (i = 0; i < G->vexnum; i++)
    {
//        printf("�������%d���������Ϣ:",i+1);
        printf("Please enter the information of the %dth vertex:\n",i+1);
        cin>> G->Vex[i];
    }
    printf("\n");
    //��������ͼ�ߵ���Ϣ
    for (i = 0; i < G->edgenum; i++)
    {
        printf("Please enter the starting serial number, ending serial number, and weight of the edge (separated by spaces).");
//        printf("������ߵ������ţ��յ���ţ�Ȩֵ(�ÿո����)��");
        cin >> start >> end >> w;
        G->Edge[start -1][end -1] = w;
        G->Edge[end - 1][start - 1] = w;   //����ͼ���жԳ���
    }
}

/***********��ӡ���ڽӾ���*********/
void print_Matrix(MGraph G)
{
    int i, j;
//    printf("\nͼ�Ķ���Ϊ:");
    printf("The vertices of the graph are :\n");
    for (i = 0; i < G.vexnum; i++)
        printf("%d ", G.Vex[i]);
    printf("\nOutput adjacency matrix:\n");
//    printf("\n����ڽӾ���:\n");
    printf("\t");
    for (i = 0; i < G.vexnum; i++)
        printf("\t%8d", G.Vex[i]);

    for (i = 0; i < G.vexnum; i++)
    {
        printf("\n\n%8d", G.Vex[i]);
        for (j = 0; j < G.vexnum; j++)
        {
            if (G.Edge[i][j] == 32767)
                printf("\t%8s", "��");
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