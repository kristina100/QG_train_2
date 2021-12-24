#ifndef ALGRAPH_H_INCLUDE
#define ALGRAPH_H_INCLUDE
#include"Common.h"
#include"Graph.h"

typedef struct AdjVexNode{
    int adjvex; //�ڽӶ����ڶ��������е�λ��     
    struct AdjVexNode *nextArc; //ָ����һ���ڽӶ���(��һ���߻�)
    int info;   //�洢��(��)�����Ϣ�����ڷǴ�Ȩͼ�ɲ���
}AdjVexNode, *AdjVexNodePtr;

typedef struct VexNode{
    VexType data;   //����ֵ��VexType�Ƕ������ͣ����û�����
    struct AdjVexNode *firstArc;    //�ڽ������ͷָ��
}VexNode;   //���������Ԫ������

typedef struct{
    VexNode *vexs;
    int n, e;
    GraphKind kind;
    int *tags;
}ALGraph;
Status DFS(ALGraph G,int k);

// ������n�������e����������ͼG
Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status createUDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DFSTraverse(ALGraph G);
// ���Ҷ���v��ͼG�е�λ��
int LocateVex_AL(ALGraph G, VexType v);
int inDegree(ALGraph G, int k);
int outDegree(ALGraph G, int k);
/*
    ����ͼG��k�����Ӧ�ڽ������еĵ�һ���ڵ㣬�����ڣ�������λ��
    ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

/*
    ����ͼG��k�����Ӧ�ڽ������е���һ���ڵ㣬�����ڣ�������λ��
    ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

#endif