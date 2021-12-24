#include"MGraph.h"

/*
     查找顶点v在图G中的位序
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
    创建n个顶点和e条边的kind类图G，vexs为顶点信息，arcs为边信息
 */
Status CreateGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e){

    if(n < 0 || e < 0 || (n > 0 && vexs == NULL) || (e > 0 && arcs == NULL))
        return ERROR;

    G.kind = kind;
    switch (G.kind){
        case UDG: return CreateUDG_M(G, vexs, n, arcs, e);  //无向图
        case DG:  return CreateDG_M(G, vexs, n, arcs, e);  break;  //有向图
        case UDN:   break;  //无向带权
        case DN:    break;  //有向带权    
    }
    return ERROR;
}

/*
    初始化含n个顶点且无边的kind类图G
 */
Status InitGraph_M(MGraph &G, GraphKind kind, VexType *vexs, int n){

    int i, j, info;
    if(n < 0 || (n > 0 && vexs == NULL)) return ERROR;
    // 如果有向图，置权为0；无向图为 inf
    if(kind == DG || kind == UDG) info = 0;
    else if(kind == DN || kind == UDN) info = INFINITY;
    else return ERROR;

    //顶点和边数
    G.n = n;
    G.e = 0;

    //空图
    if(n == 0) return SUCCESS; 
    
    if(NULL == (G.vexs = (VexType*)malloc(n*sizeof(VexType))))
        return OVERFLOW;

    // 建立顶点数组
    for (i = 0; i < G.n; i++) G.vexs[i] = vexs[i];
    
    //分配指针
    for(i = 0; i < n; i++){
        if(NULL == (G.arcs = (int**)malloc(n*sizeof(int))))
            return OVERFLOW;
    }

    //分配每个指针所指向的数组
    for(i = 0; i < n; i++)  
        if(NULL == (G.arcs[i] = (int*)malloc(n*sizeof(int))))
            return OVERFLOW;
    
    if(NULL == (G.tags = (int*)malloc(n*sizeof(int)))) return OVERFLOW;

    //初始化标志数组和关系数组
    for(i = 0; i < n; i++){
        G.tags[i] = UNVISITED;
        for(j = 0; j < n; j++)  G.arcs[i][j] = info;
    }

    return SUCCESS;
}

/*
    求图G中k顶点的第一个邻接顶点的位序
 */
int FirstAdjVex_M(MGraph G, int k){

    int i;
    if(k < 0 || k >= G.n) return -1;    //k顶点不存在

    for(i = 0; i < G.n; i++){

        if((G.kind == UDG || G.kind == DG) && G.arcs[k][i] != 0) 
            return i;
        else if((G.kind == UDN || G.kind == DN) && G.arcs[k][i] != INFINITY)
            return -2;
    }

    return -1;  //k顶点无邻接顶点
}


int NextAdjVex_M(MGraph G, int k, int m)  //v是顶点，w是当前顶点连接的顶点
{
    int i;
    if(k < 0 || k >= G.n) return -1;    // k顶点不存在
    if(m < 0 || m >= G.n) return -1;    // m顶点不存在
    if(G.arcs[k][m] == 0) return -1;
    for(i= m + 1; i <= G.n; i++)
        if(G.arcs[k][i] != 0)
            return i;
    return -2;
}

Status AddArc_M(MGraph &G,int k,int m,int info)
{
    int i;
    if(k < 0 || k >= G.n) return -1;    // k顶点不存在
    if(m < 0 || m >= G.n) return -1;    // m顶点不存在
    if(G.arcs[k][m] == 0) return -1;

    G.arcs[k][m] = 1;
    G.e++;
    return SUCCESS;
}

int Degree(MGraph G,int k)// 只针对无权图
{
    int i,j;
    int out = 0;
    if(k < 0 || k >= G.n) return -1;    // k顶点不存在
    if(G.kind == UDG)// 无向图
    {
        for(i = 0; i < G.n; i++)
        {
            if(G.arcs[k][i]!=0)
                out++;
        }
    }
    if(G.kind == DG)// 有向图
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
    创建无向图的邻接数组存储结构
 */
Status CreateUDG_M(MGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e){

    int i, j, k;
    VexType v, w;

    //初始化
    if(InitGraph_M(G, G.kind, vexs, n) != SUCCESS) return ERROR;

    //边数
    G.e = e;

    //建立关系数组
    for(k = 0; k < G.e; k++){
        //读入边(v,w)
        v = arcs[k].v;
        w = arcs[k].w;

        //确定v和w在顶点数组中的位序i和j
        i = LocateVex_M(G,v);
        j = LocateVex_M(G,w);

        if(i < 0 || j < 0)  return ERROR;

        //对应行列的元素赋值为1
        G.arcs[i][j] = G.arcs[j][i] = 1;
    }
    
    return SUCCESS;
}

Status CreateDG_M(MGraph& G, VexType* vexs, int n, ArcInfo* arcs, int e) {
    int i, j, k;
    VexType v, w;
    //初始化
    if (InitGraph_M(G, G.kind, vexs, n) != SUCCESS) return ERROR;
    //边数
    G.e = e;
    //建立关系数组
    for (k = 0; k < G.e; k++) {
        //读入边(v,w)
        v = arcs[k].v;
        w = arcs[k].w;

        //确定v和w在顶点数组中的位序i和j
        i = LocateVex_M(G, v);
        j = LocateVex_M(G, w);

        if (i < 0 || j < 0)  return ERROR;

        //对应行列的元素赋值为1
        G.arcs[i][j] = 1;
    }
    return SUCCESS;
}
// 连通图的深度优先遍历
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
// 图的深度优先遍历
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


// 查找s顶点到t顶点是否存在一条简单路径
Status isReachable_DFS(MGraph G,int s,int t,int path[],int num)
{
    int i;
    path[num++] = s;
    Status found = FALSE;// 标识是否找到终点t
    G.tags[s] = VISITED;
    if(s==t)
    {
        for(i = 0;i<num;i++)
        {
            printf("%d%c",path[i],i==num-1?'\n':' ');
        }
        return SUCCESS;
    }//一旦遇到终点t，则遍历终止
    printf("%c\n", G.vexs[s]);/* 打印顶点 */
    G.tags[s] = 1;
    for(i = FirstAdjVex_M(G,s);i>=0&&FALSE == found;i= NextAdjVex_M(G,s,i))
    {
        if(UNVISITED == G.tags[i])
            //保存查找结果
            found = isReachable_DFS(G,i,t,path,num);
    }
    G.tags[s] = 0;
    return found; // 继续返回查找结果
}



Status ExistPathLenK(MGraph G, int s, int t,int visit[],int &nodeNum) {
    int i;
    visit[s]=++nodeNum; //第几次访问到
    if (s==t) return TRUE; //找到
    else{
        //从v的邻边开始找
        for (i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i)) {
            if ( visit[i]==0 && ExistPathLenK(G, i, i+1,visit,nodeNum) ) return TRUE;
            visit[i+1] = 0;
            nodeNum--; //退一步，继续找
              if(nodeNum<-1)
                  return FALSE;
        }
    }
    return FALSE;
}


//查找s顶点到t顶点所有的路径
Status AllReachable_DFS(MGraph G,int s,int t,int path[],int num,int visit[])
{
    int i,nodeNum;
    path[num++] = s;
    Status found = FALSE;// 标识是否找到终点t
    G.tags[s] = VISITED;
    if(s==t)
    {
        for(i = 0;i<num;i++)
        {
            printf("%d%c",path[i],i==num-1?'\n':' ');
        }
        return SUCCESS;

    }  //一旦遇到终点t，则遍历终止
//    printf("%c\n", G.vexs[s]);  /* 打印顶点 */
    G.tags[s] = 1;
    for(i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i))
    {   nodeNum = 0;
        if(!ExistPathLenK(G,i,i+1,visit,nodeNum))
            //保存查找结果
            found = isReachable_DFS(G,i,t,path,num);
    }
    G.tags[s] = 0;
    return found; // 继续返回查找结果
}



// {
//    int i;
//    path[num++] = s;
//    Status found = FALSE;// 标识是否找到终点t
//    G.tags[s] = VISITED;
//    if(s==t)
//    {
//        for(i = 0;i<num;i++)
//        {
//            printf("%d%c",path[i],i==num-1?'\n':' ');
//        }
//        nnum++;
////        return SUCCESS;
//    }//一旦遇到终点t，则遍历终止
//    printf("%c\n", G.vexs[s]);/* 打印顶点 */
//    G.tags[s] = 1;
//    for(i = FirstAdjVex_M(G,s);i>=0&&i<G.n;i= NextAdjVex_M(G,s,i))
//    {
//        if(UNVISITED == G.tags[i])
//            //保存查找结果
//            isReachable_DFS(G,i,t,path,num);
//    }
//    G.tags[s] = 0;
//}