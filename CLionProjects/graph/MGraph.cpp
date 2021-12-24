//
// Created by HUAWEI on 2021-12-03.
//

#include "Common.h"
#include "MGraph.h"
#include "ALGraph.h"
#include "Graph.h"
#include <cstdlib>
#include <cstdio>

// 创建含n个顶点和e条边的kind类图G，vexs为顶点信息，arcs为边信息
Status CreateGraph_M(MGraph &G,GraphKind kind,VexType *vexs,int n, ArcInfo *arcs,int e)
{
    if(n<0||e<0||(n>0&& nullptr == vexs)||(e>0&& nullptr == arcs))
        return ERROR;
    G.kind = kind;
    switch(G.kind)
    {
        case UDG:return CreateUDG_M(G,vexs,n,arcs,e); // 创建无向图
//        case DG:return CreateDG_M(G,vexs,arcs,e); // 创建有向图
//        case UDN:return CreateUDN_M(G,vexs,n,arcs,e); //创建无向带权图
//        case DN:return CreateDN_M(G,vexs,n,arcs,e); // 创建有向带权图
        default:return ERROR;
    }
}






// 创建无向图的邻接数组存储结构
Status CreateUDG_M(MGraph &G, VexType *vexs, int n,ArcInfo *arcs, int e)
{
    int i,j,k;
    VexType v,w;
    if(InitGraph(G,G.kind,vexs,n)!=OK)
        return ERROR; // 初始化
    G.e = e; // 边数
    for(k=0;k<G.e;k++)
    {
        v = arcs[k].v;
        w = arcs[k].w; // 读入边(v,w)
        i = LocateVex_M(G,v);
        j = LocateVex_M(G,w);// 确定v和w在顶点数组中的位序i和j
        if(i < 0||j<0) return ERROR;
        G.arcs[i][j] = G.arcs[j][i] = 1;// 对应行列的元素赋值为1
    }
    return OK;
}

Status InitGraph_M(MGraph &G, GraphKind kind, const VexType *vexs, int n)
{
    // 初始化含n个顶点且无边的kind类的图G
    int i, j, info;
    if(n<0 || (n>0&&vexs == nullptr)) return ERROR;
    if(kind==DG||kind == UDG) info = 0;
    else if(kind == DN||kind == UDN) info = INFINITY;
    else return ERROR;
    G.n = n;
    G.e = 0; // 顶点数和边数
    G.kind = kind;
    if(n == 0) return OK; // 空图
    if((G.vexs = (VexType*)malloc(n*sizeof(int*))) == nullptr)
        return OVERFLOW;
    for (i = 0;i<G.n;i++) G.vexs[i] = vexs[i];// 建立顶点数组
    if(nullptr == (G.arcs=(int **) malloc(n*sizeof (int *))))// 分配指针数组
        return OVERFLOW;
    for(i = 0;i<n;i++) //分配每个指针所指向的数组
        if(nullptr == (G.arcs[i] = (int*) malloc(n*sizeof (int))))
            return OVERFLOW;
    if(nullptr == (G.tags = (int*) malloc(n*sizeof(int)))) return OVERFLOW;
    for(i = 0;i<n;i++){
        // 初始化标志数组和关系数组
        G.tags[i] = UNVISITED;
        for(j = 0;j<n;j++) G.arcs[i][j] = info;
    }
    return OK;
}

