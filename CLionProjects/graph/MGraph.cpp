//
// Created by HUAWEI on 2021-12-03.
//

#include "Common.h"
#include "MGraph.h"
#include "ALGraph.h"
#include "Graph.h"
#include <cstdlib>
#include <cstdio>

// ������n�������e���ߵ�kind��ͼG��vexsΪ������Ϣ��arcsΪ����Ϣ
Status CreateGraph_M(MGraph &G,GraphKind kind,VexType *vexs,int n, ArcInfo *arcs,int e)
{
    if(n<0||e<0||(n>0&& nullptr == vexs)||(e>0&& nullptr == arcs))
        return ERROR;
    G.kind = kind;
    switch(G.kind)
    {
        case UDG:return CreateUDG_M(G,vexs,n,arcs,e); // ��������ͼ
//        case DG:return CreateDG_M(G,vexs,arcs,e); // ��������ͼ
//        case UDN:return CreateUDN_M(G,vexs,n,arcs,e); //���������Ȩͼ
//        case DN:return CreateDN_M(G,vexs,n,arcs,e); // ���������Ȩͼ
        default:return ERROR;
    }
}






// ��������ͼ���ڽ�����洢�ṹ
Status CreateUDG_M(MGraph &G, VexType *vexs, int n,ArcInfo *arcs, int e)
{
    int i,j,k;
    VexType v,w;
    if(InitGraph(G,G.kind,vexs,n)!=OK)
        return ERROR; // ��ʼ��
    G.e = e; // ����
    for(k=0;k<G.e;k++)
    {
        v = arcs[k].v;
        w = arcs[k].w; // �����(v,w)
        i = LocateVex_M(G,v);
        j = LocateVex_M(G,w);// ȷ��v��w�ڶ��������е�λ��i��j
        if(i < 0||j<0) return ERROR;
        G.arcs[i][j] = G.arcs[j][i] = 1;// ��Ӧ���е�Ԫ�ظ�ֵΪ1
    }
    return OK;
}

Status InitGraph_M(MGraph &G, GraphKind kind, const VexType *vexs, int n)
{
    // ��ʼ����n���������ޱߵ�kind���ͼG
    int i, j, info;
    if(n<0 || (n>0&&vexs == nullptr)) return ERROR;
    if(kind==DG||kind == UDG) info = 0;
    else if(kind == DN||kind == UDN) info = INFINITY;
    else return ERROR;
    G.n = n;
    G.e = 0; // �������ͱ���
    G.kind = kind;
    if(n == 0) return OK; // ��ͼ
    if((G.vexs = (VexType*)malloc(n*sizeof(int*))) == nullptr)
        return OVERFLOW;
    for (i = 0;i<G.n;i++) G.vexs[i] = vexs[i];// ������������
    if(nullptr == (G.arcs=(int **) malloc(n*sizeof (int *))))// ����ָ������
        return OVERFLOW;
    for(i = 0;i<n;i++) //����ÿ��ָ����ָ�������
        if(nullptr == (G.arcs[i] = (int*) malloc(n*sizeof (int))))
            return OVERFLOW;
    if(nullptr == (G.tags = (int*) malloc(n*sizeof(int)))) return OVERFLOW;
    for(i = 0;i<n;i++){
        // ��ʼ����־����͹�ϵ����
        G.tags[i] = UNVISITED;
        for(j = 0;j<n;j++) G.arcs[i][j] = info;
    }
    return OK;
}

