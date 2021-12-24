#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#define UNVISITED 0
#define VISITED 1
#define INFINITY 32567 //�����������������ֵ
#include"Common.h"

typedef char VexType;

//ͼ��4�����ͣ�����ͼ�������Ȩͼ������ͼ�������Ȩͼ��
typedef enum{DG, DN, UDG, UDN} GraphKind;

//ͼ�ṹ
typedef struct{
    VexType v, w;
    int info;
}ArcInfo;

#endif