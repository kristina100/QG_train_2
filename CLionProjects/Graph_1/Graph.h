#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#define UNVISITED 0
#define VISITED 1
#define INFINITY 32567 //计算机允许的整数最大值
#include"Common.h"

typedef char VexType;

//图的4种类型：有向图，有向带权图，无向图，无向带权图。
typedef enum{DG, DN, UDG, UDN} GraphKind;

//图结构
typedef struct{
    VexType v, w;
    int info;
}ArcInfo;

#endif