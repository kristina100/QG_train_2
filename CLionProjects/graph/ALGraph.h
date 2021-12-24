//
// Created by HUAWEI on 2021-12-03.
//

#ifndef GRAPH_ALGRAPH_H
#define GRAPH_ALGRAPH_H

#include "Graph.h"
#include "Common.h"

typedef struct AdjVexNode{
    int adjvex;    // �ڽӶ����ڶ��������е�λ��
    struct AdjVexNode *nextArc;  // ָ����һ���ڽӶ��㣨��һ���߻򻡣�
    int info;  // �洢�ߣ����������Ϣ�����ڷǴ�Ȩͼ�ɲ���
}AdjVexNode, AdjVexNodeP; // �ڽ�����Ľ������

typedef struct VexNode{
    VexType data;   // ����ֵ��VexType�Ƕ������ͣ����û�����
    struct AdjVexNode *firstArc; // �ڽ������ͷָ��
}VexNode; // ���������Ԫ������

typedef struct {
    VexNode *vexs;
    int n,e;
    GraphKind kind;
    int *tags;
}ALGraph; // �ڽӱ�����

Status createDG(ALGraph &G,VexType *vexs, int n, ArcInfo *arcs, int e); // ������n�������e����������ͼG
int LocateVex_AL(ALGraph G, int k, VexType v);      // ���Ҷ���v��ͼG�е�λ��
Status GetVex_AL(ALGraph G,int k, VexType &w);      // ȡͼG��k�����ֵ��w
Status PutVex_M(ALGraph G,int k, VexType w);        // ȡͼG��k���㸳ֵw
int FirstAdjVex_AL(ALGraph G,int k,AdjVexNodeP &p); // ����ͼG��k�����Ӧ�ڽ������еĵ�һ����㣬�����ڣ�������λ��
                                                    // ����ָ��pָ��ý�㣬���򣬷���-1������ָ��pΪNULL
int NextAdjVex_AL(ALGraph G,int k,AdjVexNodeP &p);  // ��ͼG��k����������m�������һ���ڽӶ����λ��
Status AddArc(ALGraph &G, int k,int m, int info);   // ��ͼG������k���㵽m����ı߻򻡣���Ϊ��Ȩͼ��infoΪȨֵ������Ϊ1
Status RemoveArc(ALGraph &G,int k, int m);          // ��ͼG��ɾ��k���㵽m����ı߻�

#endif //GRAPH_ALGRAPH_H
