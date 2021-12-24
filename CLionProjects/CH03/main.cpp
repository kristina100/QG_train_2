#include <iostream>

#include "RcdSqList.h"
#define MAXSIZE 10000

void TraverseRcdSqList(RcdSqList L){
	printf("L = (");
	for(int i = 1; i<=L.length; i++){
		printf(" %d", L.rcd[i]);
	}
	printf(" )\n");
}

void InsertSort(RcdSqList L){
	int i, j;
	for(i = 2; i<=L.length; ++i)
		if(L.rcd[i].key<L.rcd[i-1].key){
			L.rcd[0] = L.rcd[i];
			for(j = i-1; L.rcd[0].key<L.rcd[j].key; j--)
				L.rcd[j+1] = L.rcd[j];
			L.rcd[j+1] =  L.rcd[0];
		}
}

void ShellInsert(RcdSqList L,int dk){
	int i, j;
	for(i = dk+1; i<=L.length; ++i)
		if(L.rcd[i].key<L.rcd[i-dk].key){
			L.rcd[0] = L.rcd[i];
			for(j = i-dk; j>0 && L.rcd[0].key<L.rcd[j].key; j-=dk)
				L.rcd[j+dk] = L.rcd[j];
			L.rcd[j+dk] =  L.rcd[0];
		}
}

void ShellSort(RcdSqList L){
	int i, dk[] =  {31, 15, 7, 3, 1};//{109, 41, 19, 5, 1};
	for(i = 0; i<5; i++)
		ShellInsert(L, dk[i]);
}



/* 归并排序 */

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(const int SR[],int TR[],int i,int m,int n)
{
    int j,k,l;
    for(j=m+1,k=i;i<=m && j<=n;k++)	/* 将SR中记录由小到大地并入TR */
    {
        if (SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
    }
    if(i<=m)
    {
        for(l=0; l <= m-i; l++)
            TR[k+l]=SR[i+l];		/* 将剩余的SR[i..m]复制到TR */
    }
    if(j<=n)
    {
        for(l=0; l <= n-j; l++)
            TR[k+l] = SR[j+l];		/* 将剩余的SR[j..n]复制到TR */
    }
}


/* 递归法 */
/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
    int m;
    int TR2[MAXSIZE+1];
    if(s==t)
        TR1[s]=SR[s];
    else
    {
        m=(s+t)/2;				/* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
        MSort(SR,TR2,s,m);		/* 递归地将SR[s..m]归并为有序的TR2[s..m] */
        MSort(SR,TR2,m+1,t);	/* 递归地将SR[m+1..t]归并为有序的TR2[m+1..t] */
        Merge(TR2,TR1,s,m,t);	/* 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] */
    }
}

/* 对顺序表L作归并排序 */
void MergeSort(RcdSqList *L)
{
    MSort(reinterpret_cast<int *>(L->rcd), reinterpret_cast<int *>(L->rcd), 1, L->length);
}

//快速排序
/* 交换L中数组r的下标为i和j的值 */
void swap(RcdSqList *L,int i,int j)
{
    int temp=L->rcd[i].key;
    L->rcd[i]=L->rcd[j];
    L->rcd[j].key = temp;
}

int Partition(RcdSqList *L,int low,int high)
{
    int pivotkey;

    pivotkey=L->rcd[low].key; /* 用子表的第一个记录作枢轴记录 */
    while(low<high) /*  从表的两端交替地向中间扫描 */
    {
        while(low<high&&L->rcd[high].key>=pivotkey)
            high--;
        swap(L,low,high);/* 将比枢轴记录小的记录交换到低端 */
        while(low<high&&L->rcd[low].key<=pivotkey)
            low++;
        swap(L,low,high);/* 将比枢轴记录大的记录交换到高端 */
    }
    return low; /* 返回枢轴所在位置 */
}


// 三向切分，有三个变量，lo,hi，i是用来扫描所有元素，将所有元素划分为三个部分，停留在中间区域的边界上 // 当i小于轴 // 当i大于轴 // 当i等于轴
//int QuickSort3(RcdSqList *rcd, int low, int high)
//{
//    int lo, hi, i;
//    lo = low;
//    hi = high;
//    i = low+1;
//    // 轴还是low
//    KeyType v = rcd->rcd[low].key;
//    // 当i小于轴的时候
//    while(i<hi)
//    {
//        if(i < lo)
//        {
//            lo++;
//            i++;
//            v = lo;
//        }
//        swap(rcd, i, lo);
//        if(i>lo)
//        {
//            high--;
//            v = lo;
//        }
//        swap(rcd,i,high);
//        if(i == lo) {
//            i++;
//            lo++;
//            if (i > hi) {
//                v = lo;
//                break;
//            }
//        }
//    }
//    return v;
//}

void QuickSort2(int* arr, int low, int high) {
    if (low >= high)
        return;
    int lo, hi, i;
    lo = low; hi = high; i = low + 1;
    int v = arr[low];
    while (i <= hi)
    {
        if (arr[i] < v)
        {
            int t = arr[i];
            arr[i++] = arr[lo];
            arr[lo++] = t;
        }
        else if (arr[i] > v) {
            int t = arr[i];
            arr[i] = arr[hi];
            arr[hi--] = t;
        }
        else i++;
    }
    QuickSort2(arr, low, lo - 1);
    QuickSort2(arr, hi + 1, high);
}

/* 对顺序表L中的子序列L->r[low..high]作快速排序 */
void QSort(RcdSqList *L,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(L,low,high);    /*  将L->r[low..high]一分为二，算出枢轴值pivot */
        QSort(L,low,pivot-1);		/*  对低子表递归排序 */
        QSort(L,pivot+1,high);		/*  对高子表递归排序 */
    }
}


/* 对顺序表L作快速排序 */
void QuickSort(RcdSqList *L)
{
    QSort(L,1,L->length);
}


//void ThrMerge(RcdType rcd[], int low, int mid1, int mid2, int high)
//{
//    // [low..mid1] + [mid+1..mid2] + [mid2+1..high]
//    // 简便方法 直接调用2路调用
//
//}
//
//void ThrMergeSort(RcdType rcd[], int low, int high)
//{
//    // 3路归并排序
//    // 结束
//    // 分解[low..high]->三个，平均分
//    // 结束
//}






// 快速排序
//void quick_sort_1(int* arr, int begin, int end)
//{
//    if (begin >= end) return;
//    int lo, hi, i;
//    lo = begin; hi = end; i = begin + 1;
//    int v = arr[begin];
//    while (i <= hi) {
//        if (arr[i] < v) {
//            int temp = arr[i];
//            arr[i++] = arr[lo];
//            arr[lo++] = temp;
//        }
//        else if (arr[i] > v) {
//            int temp = arr[i];
//            arr[i] = arr[hi];
//            arr[hi--] = temp;
//        }
//        else i++;
//    }
//    quick_sort_1(arr, begin, lo - 1);
//    quick_sort_1(arr, hi + 1, end);
//}


void merge(const int *arr, int i, int m,int n)
{
    int tr[20] = {0};
    int k,j;
    for (j = m+1,k=i;i<=m&&j<=n;++k)
    {
        if(arr[i] <= arr[j])
            tr[k] = arr[i++];
        else
            tr[k] = arr[j++];
    }
    while(i<=m)tr[k++] = arr[i++];
    while(j<=n)tr[k++] = arr[j++];
}

void thrmerge(int* arr, int low, int mid1, int mid2, int high)
{
    merge(arr, low, mid1, mid2);
    merge(arr, low, mid2, high);
}

void thrmergesort(int* arr, int low, int high)
{
    if (low >= high)
        return;
    int len = (high - low);
    int interval = len / 3;
    int mid1 = low + interval;
    int mid2 = high - interval;
    thrmergesort(arr, low, mid1);
    thrmergesort(arr, mid1 + 1, mid2);
    thrmergesort(arr, mid2 + 1, high);
    thrmerge(arr, low, mid1, mid2, high);
}

int main(){
   srand((unsigned)time(nullptr));

   RcdSqList La, Lb, Lc, Ld;
   int len = 10, i;
   int arr[] = {10,4,4,5,7,12,33,12,12,12};
   int begin = 10;
   int end = 12;

   InitList_Sq(La, 100, 5);
   InitList_Sq(Lb, 100, 5);
   InitList_Sq(Lc, 100, 5);
   InitList_Sq(Ld, 100, 5);

   RcdType rcd;
   for(i = 0; i<len; i++){
	   rcd.key = arr[i];
	   Append_Sq(La, rcd);
	   Append_Sq(Lb, rcd);
       Append_Sq(Lc,rcd);
       Append_Sq(Ld,rcd);
	}

   printf("Shell Sort: \n");
   ShellSort(La);
   TraverseRcdSqList(La);

   printf("Insert Sort: \n");
   InsertSort(Lb);
   TraverseRcdSqList(Lb);

   printf("Merge Sort: \n");
   MergeSort((RcdSqList *) &Lc);
   TraverseRcdSqList(Lc);

   printf("Quick Sort: \n");
   QuickSort(&Ld);
   TraverseRcdSqList(Ld);

   QuickSort2(arr, begin, end);

   system("pause");

   return 0;
}


//源码文件 测试代码截图 测试文件 运行结果截图