//
// Created by HUAWEI on 2021-12-03.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#pragma once

#define OVERFLOW -1
#define UNVISITED 0
#define VISITED 1
#define INFINITY 32567  // 允许的整数最大值
#define OK 1
#define ERROR 0

typedef int Status;
typedef enum {DG, DN, UDG, UDN}GraphKind;
typedef char VexType;
typedef struct{
    VexType v,w;
    int info;
}ArcInfo;

#endif //GRAPH_GRAPH_H
