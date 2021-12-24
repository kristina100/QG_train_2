//
// Created by HUAWEI on 2021-12-03.
//

#ifndef GRAPH_ALGRAPH_H
#define GRAPH_ALGRAPH_H

#include "Graph.h"
#include "Common.h"

typedef struct AdjVexNode{
    int adjvex;    // 邻接顶点在顶点数组中的位序
    struct AdjVexNode *nextArc;  // 指向下一个邻接顶点（下一条边或弧）
    int info;  // 存储边（弧）相关信息，对于非带权图可不用
}AdjVexNode, AdjVexNodeP; // 邻接链表的结点类型

typedef struct VexNode{
    VexType data;   // 顶点值，VexType是顶点类型，由用户定义
    struct AdjVexNode *firstArc; // 邻接链表的头指针
}VexNode; // 顶点数组的元素类型

typedef struct {
    VexNode *vexs;
    int n,e;
    GraphKind kind;
    int *tags;
}ALGraph; // 邻接表类型

Status createDG(ALGraph &G,VexType *vexs, int n, ArcInfo *arcs, int e); // 创建含n个顶点和e条弧的有向图G
int LocateVex_AL(ALGraph G, int k, VexType v);      // 查找顶点v在图G中的位序
Status GetVex_AL(ALGraph G,int k, VexType &w);      // 取图G的k顶点的值到w
Status PutVex_M(ALGraph G,int k, VexType w);        // 取图G中k顶点赋值w
int FirstAdjVex_AL(ALGraph G,int k,AdjVexNodeP &p); // 查找图G中k顶点对应邻接链表中的第一个结点，若存在，返回其位序，
                                                    // 并令指针p指向该结点，否则，返回-1，并令指针p为NULL
int NextAdjVex_AL(ALGraph G,int k,AdjVexNodeP &p);  // 求图G中k顶点的相对于m顶点的下一个邻接顶点的位序
Status AddArc(ALGraph &G, int k,int m, int info);   // 在图G中增加k顶点到m顶点的边或弧，若为带权图，info为权值，否则为1
Status RemoveArc(ALGraph &G,int k, int m);          // 在图G中删除k顶点到m顶点的边或弧

#endif //GRAPH_ALGRAPH_H
