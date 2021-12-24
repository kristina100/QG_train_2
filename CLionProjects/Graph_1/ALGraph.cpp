#include"ALGraph.h"

/**
    ������n�������e����������ͼG
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
    //���붨�����ͻ���
    G.n = n; G.e = e;
    G.kind = UDG;
    G.vexs = (VexNode*)malloc(n*sizeof(VexNode));
    G.tags = (int*)malloc(n*sizeof(int));
    //��ʼ����־����ͽ�����������
    for(i = 0; i < G.n; i++){
        G.tags[i] = UNVISITED;
        // ����ֵ
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;}
    //�����ڽ�����
    for(k = 0; k < G.e; k++){
        // �����ڽ�������ǽ����߱�
        v = arcs[k].v; w = arcs[k].w;
        //ȷ��v��w��λ��i��j
        i = LocateVex_AL(G, v);
        j = LocateVex_AL(G, w);
        //����v��w������
        if(i < 0 || j < 0) return ERROR;
        //Ϊ����w����p���
        p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
        if(p == NULL) return OVERFLOW;
        p->adjvex = j;
        //��i������ڽ������ͷ����p���
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
    
    //���붨�����ͻ���
    G.n = n; G.e = e;
    G.kind = DG;
    G.vexs = (VexNode*)malloc(n*sizeof(VexNode));
    G.tags = (int*)malloc(n*sizeof(int));

    //��ʼ����־����ͽ�����������
    for(i = 0; i < G.n; i++)
    {
        G.tags[i] = UNVISITED;
        // ����ֵ
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;
    }
    //�����ڽ�����
    for(k = 0; k < G.e; k++)
    {
        // �����ڽ�������ǽ����߱�
        v = arcs[k].v; w = arcs[k].w;
        //ȷ��v��w��λ��i��j
        i = LocateVex_AL(G, v);
        j = LocateVex_AL(G, w);

        //����v��w������
        if(i < 0 || j < 0) return ERROR;
        //Ϊ����w����p���
        p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
        if(p == NULL) return OVERFLOW;
        p->adjvex = j;
        //��i������ڽ������ͷ����p���
        p->nextArc = G.vexs[i].firstArc;
        G.vexs[i].firstArc = p;
    }
    return SUCCESS;
}

/**
     ���Ҷ���v��ͼG�е�λ��
 */
int LocateVex_AL(ALGraph G, VexType v){

    int i;
    for(i = 0; i < G.n; i++)
        if(v == G.vexs[i].data) return i;
    
    return -1;
}

/**
    ����ͼG��k�����Ӧ�ڽ������еĵ�һ���ڵ㣬�����ڣ�������λ��
    ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 */
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p){

    //k���㲻����
    if(k < 0 || k >= G.n) return -1;

    p = G.vexs[k].firstArc;

    //���ص�һ�����洢�Ķ���λ��
    if(p != NULL) return p->adjvex;
    else return -1;
}

VexType FirstAdjVex_AL_NEW(ALGraph G,VexType v)
{
//    int k;
    AdjVexNodePtr p;
//    //k���㲻����
//    for(k = 0;k<G.n;k++)
//        if(k < 0 || k >= G.n) return -1;
//        else if(G.vexs[k].data == v)
//            p = G.vexs[k].firstArc;
//
//    //���ص�һ�����洢�Ķ���λ��
//    if(p != NULL) return p->adjvex;
//    else return -1;
    int k = LocateVex_AL(G,v);
    if(k == -1) return '#';
    p = G.vexs[k].firstArc;
    if(p!=NULL) return G.vexs[p->adjvex].data;
    else return'#';
}

// ���
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

// ����
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
    ����ͼG��k�����Ӧ�ڽ������е���һ���ڵ㣬�����ڣ�������λ��
    ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p){

    //k���㲻����
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

