#ifndef MGRAPH_H_INCLUDE
#define MGRAPH_H_INCLUDE
#include"Common.h"
#include"Graph.h"

typedef struct{
    VexType *vexs;   //顶点数组，VexType是顶点类型，有用户定义
    int **arcs;      //关系数组，对无权图，用0或1表示是否相邻，带权图，则为权值或INFINITY
    int n, e;        //顶点数和边(弧)数
    GraphKind kind;  //图的类型   
    int *tags;       //标志数组，可用于在图的遍历中标记顶点访问与否
}MGraph;    //邻接数组类型

// 查找顶点v在图G中的位序
int LocateVex_M(MGraph G, VexType v);
Status AddArc_M(MGraph &G,int k,int m,int info);
int Degree(MGraph G,int k);
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num,int visit[]);
 // 创建n个顶点和e条边的kind类图G，vexs为顶点信息，arcs为边信息
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DFS_M(MGraph G,int k);
Status DFSTraverse_M(MGraph G);
// 初始化含n个顶点且无边的kind类图G
Status InitGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n);
Status ExistPathLenK(MGraph G, int s, int t,int visit[],int &nodeNum);
// 求图G中k顶点的第一个邻接顶点的位序
int FirstAdjVex_M(MGraph G, int k);
// 创建无向图的邻接数组存储结构
Status CreateUDG_M(MGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status isReachable_DFS(MGraph G,int s,int t,int path[],int num);
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num);
// 创建有向图的邻接数组存储结构
Status CreateDG_M(MGraph& G, VexType* vexs, int n, ArcInfo* arcs, int e);
#endif