#include"MGraph.h"

/*
     ���Ҷ���v��ͼG�е�λ��
 */
int LocateVex_M(MGraph G, VexType v){
    int i;
    VexType temp;
    for(i = 0; i < G.n; i++){
        temp = G.vexs[i];
        if(v == temp) return i;
    }
    return -1;
} 

/*
    ����n�������e���ߵ�kind��ͼG��vexsΪ������Ϣ��arcsΪ����Ϣ
 */
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e){

    if(n < 0 || e < 0 || (n > 0 && vexs == NULL) || (e > 0 && arcs == NULL))
        return ERROR;

    G.kind = kind;
    switch (G.kind){
        case UDG: return CreateUDG_M(G, vexs, n, arcs, e);  //����ͼ
        case DG:  return CreateDG_M(G, vexs, n, arcs, e);  break;  //����ͼ
        case UDN:   break;  //�����Ȩ
        case DN:    break;  //�����Ȩ    
    }
    return ERROR;
}

/*
    ��ʼ����n���������ޱߵ�kind��ͼG
 */
Status InitGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n){

    int i, j, info;
    if(n < 0 || (n > 0 && vexs == NULL)) return ERROR;
    // �������ͼ����ȨΪ0������ͼΪ inf
    if(kind == DG || kind == UDG) info = 0;
    else if(kind == DN || kind == UDN) info = INFINITY;
    else return ERROR;

    //����ͱ���
    G.n = n;
    G.e = 0;

    //��ͼ
    if(n == 0) return SUCCESS; 
    
    if(NULL == (G.vexs = (VexType*)malloc(n*sizeof(VexType))))
        return OVERFLOW;

    // ������������
    for (i = 0; i < G.n; i++) G.vexs[i] = vexs[i];
    
    //����ָ��
    for(i = 0; i < n; i++){
        if(NULL == (G.arcs = (int**)malloc(n*sizeof(int))))
            return OVERFLOW;
    }

    //����ÿ��ָ����ָ�������
    for(i = 0; i < n; i++)  
        if(NULL == (G.arcs[i] = (int*)malloc(n*sizeof(int))))
            return OVERFLOW;
    
    if(NULL == (G.tags = (int*)malloc(n*sizeof(int)))) return OVERFLOW;

    //��ʼ����־����͹�ϵ����
    for(i = 0; i < n; i++){
        G.tags[i] = UNVISITED;
        for(j = 0; j < n; j++)  G.arcs[i][j] = info;
    }

    return SUCCESS;
}

/*
    ��ͼG��k����ĵ�һ���ڽӶ����λ��
 */
int FirstAdjVex_M(MGraph G, int k){

    int i;
    if(k < 0 || k >= G.n) return -1;    //k���㲻����

    for(i = 0; i < G.n; i++){

        if((G.kind == UDG || G.kind == DG) && G.arcs[k][i] != 0) 
            return i;
        else if((G.kind == UDN || G.kind == DN) && G.arcs[k][i] != INFINITY)
            return -2;
    }

    return -1;  //k�������ڽӶ���
}


int NextAdjVex_M(MGraph G, int k, int m)  //v�Ƕ��㣬w�ǵ�ǰ�������ӵĶ���
{
    int i;
    if(k < 0 || k >= G.n) return -1;    // k���㲻����
    if(m < 0 || m >= G.n) return -1;    // m���㲻����
    if(G.arcs[k][m] == 0) return -1;
    for(i= m + 1; i <= G.n; i++)
        if(G.arcs[k][i] != 0)
            return i;
    return -2;
}

Status AddArc_M(MGraph &G,int k,int m,int info)
{
    int i;
    if(k < 0 || k >= G.n) return -1;    // k���㲻����
    if(m < 0 || m >= G.n) return -1;    // m���㲻����
    if(G.arcs[k][m] == 0) return -1;

    G.arcs[k][m] = 1;
    G.e++;
    return SUCCESS;
}

int Degree(MGraph G,int k)// ֻ�����Ȩͼ
{
    int i,j;
    int out = 0;
    if(k < 0 || k >= G.n) return -1;    // k���㲻����
    if(G.kind == UDG)// ����ͼ
    {
        for(i = 0; i < G.n; i++)
        {
            if(G.arcs[k][i]!=0)
                out++;
        }
    }
    if(G.kind == DG)// ����ͼ
    {
        for(i = 0; i < G.n; i++)
        {
            if(G.arcs[k][i] != 0)
                out++;
        }
        for(j = 0; j < G.n; j++)
        {
            if(G.arcs[j][k] != 0)
                out++;
        }
        return out;
    }
}

Status visit1(int data)
{
    printf("%d\n",data);
    return SUCCESS;
}
/*
    ��������ͼ���ڽ�����洢�ṹ
 */
Status CreateUDG_M(MGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e){

    int i, j, k;
    VexType v, w;

    //��ʼ��
    if(InitGraph_M(G, G.kind, vexs, n) != SUCCESS) return ERROR;

    //����
    G.e = e;

    //������ϵ����
    for(k = 0; k < G.e; k++){
        //�����(v,w)
        v = arcs[k].v;
        w = arcs[k].w;

        //ȷ��v��w�ڶ��������е�λ��i��j
        i = LocateVex_M(G,v);
        j = LocateVex_M(G,w);

        if(i < 0 || j < 0)  return ERROR;

        //��Ӧ���е�Ԫ�ظ�ֵΪ1
        G.arcs[i][j] = G.arcs[j][i] = 1;
    }
    
    return SUCCESS;
}

Status CreateDG_M(MGraph& G, VexType* vexs, int n, ArcInfo* arcs, int e) {
    int i, j, k;
    VexType v, w;
    //��ʼ��
    if (InitGraph_M(G, G.kind, vexs, n) != SUCCESS) return ERROR;
    //����
    G.e = e;
    //������ϵ����
    for (k = 0; k < G.e; k++) {
        //�����(v,w)
        v = arcs[k].v;
        w = arcs[k].w;

        //ȷ��v��w�ڶ��������е�λ��i��j
        i = LocateVex_M(G, v);
        j = LocateVex_M(G, w);

        if (i < 0 || j < 0)  return ERROR;

        //��Ӧ���е�Ԫ�ظ�ֵΪ1
        G.arcs[i][j] = 1;
    }
    return SUCCESS;
}
// ��ͨͼ��������ȱ���
Status DFS_M(MGraph G,int k)
{
    int i;
    if(ERROR == visit1(k))   return ERROR;
    G.tags[k] = VISITED;
    for(i = FirstAdjVex_M(G,k);i>=0;i= NextAdjVex_M(G,k,i))
    {
        if(UNVISITED == G.tags[i])
            if(ERROR==DFS_M(G,i)) return ERROR;
    }
    return SUCCESS;
}
// ͼ��������ȱ���
Status DFSTraverse_M(MGraph G)
{
    int i;
    for (i = 0;i<G.n;i++)
    {
        G.tags[i] = UNVISITED;
    }
    for(i=0;i<G.n;i++)
    {
        if(UNVISITED == G.tags[i])
                if(ERROR== DFS_M(G,i))
                    return ERROR;
    }
    return SUCCESS;
}


// ����s���㵽t�����Ƿ����һ����·��
Status isReachable_DFS(MGraph G,int s,int t,int path[],int num)
{
    int i;
    path[num++] = s;
    Status found = FALSE;// ��ʶ�Ƿ��ҵ��յ�t
    G.tags[s] = VISITED;
    if(s==t)
    {
        for(i = 0;i<num;i++)
        {
            printf("%d%c",path[i],i==num-1?'\n':' ');
        }
        return SUCCESS;
    }//һ�������յ�t���������ֹ
    printf("%c\n", G.vexs[s]);/* ��ӡ���� */
    G.tags[s] = 1;
    for(i = FirstAdjVex_M(G,s);i>=0&&FALSE == found;i= NextAdjVex_M(G,s,i))
    {
        if(UNVISITED == G.tags[i])
            //������ҽ��
            found = isReachable_DFS(G,i,t,path,num);
    }
    G.tags[s] = 0;
    return found; // �������ز��ҽ��
}



Status ExistPathLenK(MGraph G, int s, int t,int visit[],int &nodeNum) {
    int i;
    visit[s]=++nodeNum; //�ڼ��η��ʵ�
    if (s==t) return TRUE; //�ҵ�
    else{
        //��v���ڱ߿�ʼ��
        for (i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i)) {
            if ( visit[i]==0 && ExistPathLenK(G, i, i+1,visit,nodeNum) ) return TRUE;
            visit[i+1] = 0;
            nodeNum--; //��һ����������
              if(nodeNum<-1)
                  return FALSE;
        }
    }
    return FALSE;
}


//����s���㵽t�������е�·��
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num,int visit[])
{
    int i,nodeNum;
    path[num++] = s;
    Status found = FALSE;// ��ʶ�Ƿ��ҵ��յ�t
    G.tags[s] = VISITED;
    if(s==t)
    {
        for(i = 0;i<num;i++)
        {
            printf("%d%c",path[i],i==num-1?'\n':' ');
        }
        return SUCCESS;

    }  //һ�������յ�t���������ֹ
//    printf("%c\n", G.vexs[s]);  /* ��ӡ���� */
    G.tags[s] = 1;
    for(i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i))
    {   nodeNum = 0;
        if(!ExistPathLenK(G,i,i+1,visit,nodeNum))
            //������ҽ��
            found = isReachable_DFS(G,i,t,path,num);
    }
    G.tags[s] = 0;
    return found; // �������ز��ҽ��
}



// {
//    int i;
//    path[num++] = s;
//    Status found = FALSE;// ��ʶ�Ƿ��ҵ��յ�t
//    G.tags[s] = VISITED;
//    if(s==t)
//    {
//        for(i = 0;i<num;i++)
//        {
//            printf("%d%c",path[i],i==num-1?'\n':' ');
//        }
//        nnum++;
////        return SUCCESS;
//    }//һ�������յ�t���������ֹ
//    printf("%c\n", G.vexs[s]);/* ��ӡ���� */
//    G.tags[s] = 1;
//    for(i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i))
//    {
//        if(UNVISITED == G.tags[i])
//            //������ҽ��
//            isReachable_DFS(G,i,t,path,num);
//    }
//    G.tags[s] = 0;
//}