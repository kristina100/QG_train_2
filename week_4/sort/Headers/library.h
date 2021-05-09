#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


//The following symbolic constants and structs sort cardinality
#define Radix 10           //The value of cardinality
#define Digits 10          //Number of keywords

typedef int KeyType;    //Define keyword types
typedef char InfoType[10];
typedef struct          //Record type
{
    KeyType key;        //Keyword item
    InfoType data;      //Other data items of type Linotype
} RecType;              //Record type definition for sorting

typedef struct node
{
    KeyType data;      //Keywords of records
    struct node *next;
} RadixRecType;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(RecType R[],int n);

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QSort(RecType R[],int low,int high);
void QuickSortR(RecType R[],int s,int t);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(RecType R[],int low,int high);

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeSort(RecType R[],int n); //归并排序


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void Merge(RecType R[],int begin,int mid,int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CreateLink(RadixRecType *&p,RecType R[],int n);   //Create a linked list for radix sort
void DestroyLink(RadixRecType *&p); //Release the linked list for radix sort
void RadixSort(RadixRecType *&p); //Base sort

void write(RadixRecType *&p,char*filename);
/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);

/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */


//自定义函数
void sum_time();
void Menu0();
void Quit();
void QuickSort2(RecType R[],int n);


#endif // QUEUE_H_INCLUDED