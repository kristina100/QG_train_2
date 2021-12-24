#ifndef MGRAPH_H_INCLUDE
#define MGRAPH_H_INCLUDE
#include"Common.h"
#include"Graph.h"

typedef struct{
    VexType *vexs;   //�������飬VexType�Ƕ������ͣ����û�����
    int **arcs;      //��ϵ���飬����Ȩͼ����0��1��ʾ�Ƿ����ڣ���Ȩͼ����ΪȨֵ��INFINITY
    int n, e;        //�������ͱ�(��)��
    GraphKind kind;  //ͼ������   
    int *tags;       //��־���飬��������ͼ�ı����б�Ƕ���������
}MGraph;    //�ڽ���������

// ���Ҷ���v��ͼG�е�λ��
int LocateVex_M(MGraph G, VexType v);
Status AddArc_M(MGraph &G,int k,int m,int info);
int Degree(MGraph G,int k);
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num,int visit[]);
 // ����n�������e���ߵ�kind��ͼG��vexsΪ������Ϣ��arcsΪ����Ϣ
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DFS_M(MGraph G,int k);
Status DFSTraverse_M(MGraph G);
// ��ʼ����n���������ޱߵ�kind��ͼG
Status InitGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n);
Status ExistPathLenK(MGraph G, int s, int t,int visit[],int &nodeNum);
// ��ͼG��k����ĵ�һ���ڽӶ����λ��
int FirstAdjVex_M(MGraph G, int k);
// ��������ͼ���ڽ�����洢�ṹ
Status CreateUDG_M(MGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status isReachable_DFS(MGraph G,int s,int t,int path[],int num);
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num);
// ��������ͼ���ڽ�����洢�ṹ
Status CreateDG_M(MGraph& G, VexType* vexs, int n, ArcInfo* arcs, int e);
#endif