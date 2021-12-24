//
// Created by HUAWEI on 2021-12-03.
//

#ifndef GRAPH_MGRAPH_H
#define GRAPH_MGRAPH_H

#include "Graph.h"
#include "Common.h"

typedef struct {
    VexType *vexs; // �������飬VexType�Ƕ������ͣ����û�����
    int **arcs;    // ��ϵ���飬����Ȩͼ����0����1��ʾ���ڷ񣬶Դ�Ȩͼ����ΪȨֵ��INFINITY
    int n,e;       // �������ͱ���
    GraphKind  kind; // ͼ������
    int *tags;     // ��־���飬��������ͼ�ı����б�Ƕ���������
}MGraph;

int LocateVex_M(MGraph G, VexType v); // ���Ҷ���v��ͼG�е�λ��
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n,ArcInfo *arcs, int e); // ����n�������e���ߵ�kind��ͼG��vexsΪ������Ϣ��arcsΪ����Ϣ
Status InitGraph(MGraph &G,GraphKind kind,VexType *vexs,int n); // ��ʼ����n���������ޱߵ�kind��ͼG
Status GetVex_M(MGraph G,int k,VexType &w); // ȡͼG��k�����ֵ��w
Status PutVex_M(MGraph G,int k, VexType w); // ȡͼG��k���㸳ֵw
int FirstAdjVex_M(MGraph G,int k); // ��ͼG��k����ĵ�һ���ڽӶ����λ��
int NextAdjVex_M(MGraph G,int k); // ��ͼG��k����������m�������һ���ڽӶ����λ��
Status AddArc_M(MGraph &G, int k,int m, int info); // ��ͼG������k���㵽m����ı߻򻡣���Ϊ��Ȩͼ��infoΪȨֵ������Ϊ1
Status RemoveArc_M(MGraph &G,int k, int m); // ��ͼG��ɾ��k���㵽m����ı߻�


Status CreateUDG_M(MGraph &G, VexType *vexs, int n,ArcInfo *arcs, int e);
#endif //GRAPH_MGRAPH_H
