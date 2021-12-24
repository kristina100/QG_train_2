//
// Created by HUAWEI on 2021-12-03.
//

#ifndef GRAPH_MGRAPH_H
#define GRAPH_MGRAPH_H

#include "Graph.h"
#include "Common.h"

typedef struct {
    VexType *vexs; // 顶点数组，VexType是顶点类型，由用户定义
    int **arcs;    // 关系数组，对无权图，用0或者1表示相邻否，对带权图，则为权值或INFINITY
    int n,e;       // 顶点数和边数
    GraphKind  kind; // 图的类型
    int *tags;     // 标志数组，可用于在图的遍历中标记顶点访问与否
}MGraph;

int LocateVex_M(MGraph G, VexType v); // 查找顶点v在图G中的位序
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n,ArcInfo *arcs, int e); // 创建n个顶点和e条边的kind类图G，vexs为顶点信息，arcs为边信息
Status InitGraph(MGraph &G,GraphKind kind,VexType *vexs,int n); // 初始化含n个顶点且无边的kind类图G
Status GetVex_M(MGraph G,int k,VexType &w); // 取图G的k顶点的值到w
Status PutVex_M(MGraph G,int k, VexType w); // 取图G中k顶点赋值w
int FirstAdjVex_M(MGraph G,int k); // 求图G中k顶点的第一个邻接顶点的位序
int NextAdjVex_M(MGraph G,int k); // 求图G中k顶点的相对于m顶点的下一个邻接顶点的位序
Status AddArc_M(MGraph &G, int k,int m, int info); // 在图G中增加k顶点到m顶点的边或弧，若为带权图，info为权值，否则为1
Status RemoveArc_M(MGraph &G,int k, int m); // 在图G中删除k顶点到m顶点的边或弧


Status CreateUDG_M(MGraph &G, VexType *vexs, int n,ArcInfo *arcs, int e);
#endif //GRAPH_MGRAPH_H
