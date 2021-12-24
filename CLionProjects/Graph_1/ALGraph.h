#ifndef ALGRAPH_H_INCLUDE
#define ALGRAPH_H_INCLUDE
#include"Common.h"
#include"Graph.h"

typedef struct AdjVexNode{
    int adjvex; //邻接顶点在顶点数组中的位序     
    struct AdjVexNode *nextArc; //指向下一个邻接顶点(下一条边或弧)
    int info;   //存储边(弧)相关信息，对于非带权图可不用
}AdjVexNode, *AdjVexNodePtr;

typedef struct VexNode{
    VexType data;   //顶点值，VexType是顶点类型，由用户定义
    struct AdjVexNode *firstArc;    //邻接链表的头指针
}VexNode;   //顶点数组的元素类型

typedef struct{
    VexNode *vexs;
    int n, e;
    GraphKind kind;
    int *tags;
}ALGraph;
Status DFS(ALGraph G,int k);

// 创建含n个顶点和e条弧的有向图G
Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status createUDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DFSTraverse(ALGraph G);
// 查找顶点v在图G中的位序
int LocateVex_AL(ALGraph G, VexType v);
int inDegree(ALGraph G, int k);
int outDegree(ALGraph G, int k);
/*
    查找图G中k顶点对应邻接链表中的第一个节点，若存在，返回其位序，
    并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

/*
    查找图G中k顶点对应邻接链表中的下一个节点，若存在，返回其位序，
    并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

#endif