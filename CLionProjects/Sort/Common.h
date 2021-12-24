//
// Created by HUAWEI on 2021/9/29.
//

#ifndef SORT_COMMON_H
#define SORT_COMMON_H

#include <stdlib.h>
#include <stdio.h>

//用于排序数组个数最大值
#define MAXSIZE 10000
/* 用于快速排序时判断是否选用插入排序阈值 */
#define MAX_LENGTH_INSERT_SORT 7

#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct
{
    int r[MAXSIZE+1];
    int length;
}SqList;

// 交换L中数组r的下标为i和j的值
void swap(SqList *L, int i, int j);
// 打印链表
void print(SqList L);
// 对顺序表L作交换排序（冒泡初级排序初级版）
void BubbleSort0(SqList *L);
// 对顺序表L作冒泡排序
void BubbleSort(SqList *L);
// 对顺序表进行改进的冒泡算法
void BubbleSort2(SqList *L);
// 对顺序表L作简单选择排序
void SelectSort(SqList *L);
// 对顺寻表作直接插入排序
void InsertSort(SqList *L);
// 对顺序表L作希尔排序
void ShellSort(SqList *L);
/* 已知L->r[s..m]中记录的关键字除了L->r[s]之外均满足堆的定义 */
/* 本函数调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆 */
void HeapAdjust(SqList *L,int s,int m);
// 对顺序表L进行堆排序
void HeapSort(SqList *L);
// 有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] 归并排序
void Merge(int SR[],int TR[],int i,int m,int n);

/* 快速排序 */
/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int Partition(SqList *L,int low,int high);
void QSort(SqList *L,int low,int high);
void QuickSort(SqList *L);

/* 改进后快速排序 */
/* 快速排序优化算法 */
int Partition1(SqList *L,int low,int high);
void QSort1(SqList *L,int low,int high);
void QuickSort1(SqList *L);

/* 对顺序表L作归并非递归排序 */
void MergeSort2(SqList *L);
/* 非递归法 */
/* 将SR[]中相邻长度为s的子序列两两归并到TR[] */
void MergePass(int SR[],int TR[],int s,int n);
/* 对顺序表L作归并排序 */
void MergeSort(SqList *L);

#endif //SORT_COMMON_H
