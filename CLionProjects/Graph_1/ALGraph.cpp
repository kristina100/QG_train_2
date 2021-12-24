#include"ALGraph.h"

/**
    创建含n个顶点和e条弧的有向图G
 */

Status visit(int data)
{
    printf("%d\n",data);
    return SUCCESS;
}
Status createUDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e){
    int i, j, k;
    VexType v, w;
    AdjVexNodePtr p;
    //读入定点数和弧数
    G.n = n; G.e = e;
    G.kind = UDG;
    G.vexs = (VexNode*)malloc(n*sizeof(VexNode));
    G.tags = (int*)malloc(n*sizeof(int));
    //初始化标志数组和建立顶点数组
    for(i = 0; i < G.n; i++){
        G.tags[i] = UNVISITED;
        // 填顶点的值
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;}
    //建立邻接链表
    for(k = 0; k < G.e; k++){
        // 建立邻接链表就是建立边表
        v = arcs[k].v; w = arcs[k].w;
        //确定v和w的位序i和j
        i = LocateVex_AL(G, v);
        j = LocateVex_AL(G, w);
        //顶点v或w不存在
        if(i < 0 || j < 0) return ERROR;
        //为顶点w分配p结点
        p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
        if(p == NULL) return OVERFLOW;
        p->adjvex = j;
        //在i顶点的邻接链表表头插入p结点
        p->nextArc = G.vexs[i].firstArc;
        G.vexs[i].firstArc = p;
        p= (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
        p->adjvex = i;
        p->nextArc = G.vexs[j].firstArc;
        G.vexs[j].firstArc = p;}
    return SUCCESS;
}

Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e){

    int i, j, k;
    VexType v, w;
    AdjVexNodePtr p;
    
    //读入定点数和弧数
    G.n = n; G.e = e;
    G.kind = DG;
    G.vexs = (VexNode*)malloc(n*sizeof(VexNode));
    G.tags = (int*)malloc(n*sizeof(int));

    //初始化标志数组和建立顶点数组
    for(i = 0; i < G.n; i++)
    {
        G.tags[i] = UNVISITED;
        // 填顶点的值
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;
    }
    //建立邻接链表
    for(k = 0; k < G.e; k++)
    {
        // 建立邻接链表就是建立边表
        v = arcs[k].v; w = arcs[k].w;
        //确定v和w的位序i和j
        i = LocateVex_AL(G, v);
        j = LocateVex_AL(G, w);

        //顶点v或w不存在
        if(i < 0 || j < 0) return ERROR;
        //为顶点w分配p结点
        p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
        if(p == NULL) return OVERFLOW;
        p->adjvex = j;
        //在i顶点的邻接链表表头插入p结点
        p->nextArc = G.vexs[i].firstArc;
        G.vexs[i].firstArc = p;
    }
    return SUCCESS;
}

/**
     查找顶点v在图G中的位序
 */
int LocateVex_AL(ALGraph G, VexType v){

    int i;
    for(i = 0; i < G.n; i++)
        if(v == G.vexs[i].data) return i;
    
    return -1;
}

/**
    查找图G中k顶点对应邻接链表中的第一个节点，若存在，返回其位序，
    并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p){

    //k顶点不存在
    if(k < 0 || k >= G.n) return -1;

    p = G.vexs[k].firstArc;

    //返回第一个结点存储的顶点位序
    if(p != NULL) return p->adjvex;
    else return -1;
}

VexType FirstAdjVex_AL_NEW(ALGraph G,VexType v)
{
//    int k;
    AdjVexNodePtr p;
//    //k顶点不存在
//    for(k = 0;k<G.n;k++)
//        if(k < 0 || k >= G.n) return -1;
//        else if(G.vexs[k].data == v)
//            p = G.vexs[k].firstArc;
//
//    //返回第一个结点存储的顶点位序
//    if(p != NULL) return p->adjvex;
//    else return -1;
    int k = LocateVex_AL(G,v);
    if(k == -1) return '#';
    p = G.vexs[k].firstArc;
    if(p!=NULL) return G.vexs[p->adjvex].data;
    else return'#';
}

// 入度
int inDegree(ALGraph G, int k)
{   // Add your code here
    if(!G.n||!G.e||k>G.n) return -1;

    int i,in_degree = 0,out_degree = 0,sum = 0;
    AdjVexNodePtr p,s;

    if(G.kind == DG)
    {
        s = G.vexs[k].firstArc;

        for (i = 0; i < G.n; i++)
        {
            if (i == k) continue;
            p = G.vexs[i].firstArc;
            while (p) {
                if (p->adjvex == k) in_degree++;
                p = p->nextArc;
            }
        }
        while (s)
        {
            out_degree++;
            s = s->nextArc;
        }
        sum = out_degree + in_degree;
    }
    if(G.kind == UDG)
    {
        p = G.vexs[k].firstArc;
        while (p != nullptr) {
            sum++;
            p = p->nextArc;
        }
    }
    return sum;
}

// 出度
int outDegree(ALGraph G, int k)
{  // Add your code here
    if(!G.n || !G.e) return -1;

    int out_degree = 0;
    AdjVexNodePtr p = G.vexs[k].firstArc;

    while(p)
    {
        out_degree++;
        p=p->nextArc;
    }
    return out_degree;
}

/**
    查找图G中k顶点对应邻接链表中的下一个节点，若存在，返回其位序，
    并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p){

    //k顶点不存在
    if(k < 0 || k >= G.n) return -1;
    if(p == NULL) return -1;

    p = p->nextArc;

    if(p != NULL) return p->adjvex;
    else return -1;
}

Status DFS(ALGraph G,int k)
{
    int NextNum = -1;
    AdjVexNodePtr p;
    G.tags[k] = 1;
    visit(G.vexs[k].data);
    p = G.vexs[k].firstArc;
    while(p)
    {
        if(!p->adjvex)
        {
            DFS(G,p->adjvex);
        }
        p=p->nextArc;
    }
    return SUCCESS;
}

Status DFSTraverse(ALGraph G)
{
    int i;
    for(i = 0;i<G.n;i++)
    {
        G.tags[i] = 0;
    }
    for(i = 0;i<G.n;i++)
    {
        if(!G.tags[i])
            DFS(G,i);
    }
    return SUCCESS;
}

