//
// Created by HUAWEI on 2021-12-03.
//
#include <iostream>
#include "Commn.h"

using namespace std;

/** 链队列的初始化 */
LinkQueue* InitQueue()
{
    auto* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    if (!queue)
    {
        printf("init queue error!\n");
        exit(0);
    }
    queue->front = (QueueNode*)malloc(sizeof(QueueNode));
    queue->front->next = nullptr;
    queue->rear = queue->front;
    return queue;
}
/** 链队列的销毁，注意先进去的是队列头，后进去的是队列尾 */
void DestoryQueue(LinkQueue* queue)
{
    while (queue->front)
    {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
}
/** 入队 */
void EnQueue(LinkQueue* queue, CSTNode* node)
{
    auto* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
    queueNode->data = node;
    queueNode->next = nullptr;
    queue->rear->next = queueNode;
    queue->rear = queueNode;
}
/** 出队 */
CSTNode* DeQueue(LinkQueue* queue)
{
    if (queue->front == queue->rear)//队列为空
        return nullptr;
    QueueNode* p = queue->front->next;
    CSTNode* node = p->data;
    queue->front = p;
    return node;
}
