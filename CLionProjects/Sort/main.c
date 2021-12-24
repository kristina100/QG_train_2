#include <stdio.h>
#include "Common.h"
#define N 9
int main()
{
    int i;

    /* int d[N]={9,1,5,8,3,7,4,6,2}; */
    int d[N]={50,10,90,30,70,40,80,60,20};
    /* int d[N]={9,8,7,6,5,4,3,2,1}; */

    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;

    for(i=0;i<N;i++)
        l0.r[i+1]=d[i];
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("Before sort:\n");
    print(l0);

    printf("Primary bubble sort:\n");
    BubbleSort0(&l0);
    print(l0);

    printf("Bubble sort:\n");
    BubbleSort(&l1);
    print(l1);

    printf("Improving bubble sort:\n");
    BubbleSort2(&l2);
    print(l2);

    printf("Select sort:\n");
    SelectSort(&l3);
    print(l3);

    printf("Insert sort:\n");
    InsertSort(&l4);
    print(l4);

    printf("Shell Sort:\n");
    ShellSort(&l5);
    print(l5);

    printf("Heap sort:\n");
    HeapSort(&l6);
    print(l6);

    printf("Subsumption sort (recursive):\n");
    MergeSort(&l7);
    print(l7);

    printf("Subsumption sort (no recursive):\n");
    MergeSort2(&l8);
    print(l8);

    printf("Quick sort:\n");
    QuickSort(&l9);
    print(l9);

    printf("Improving Quick sort:\n");
    QuickSort1(&l10);
    print(l10);


    /*����������*/
    /*
    srand(time(0));
    int Max=10000;
    int d[10000];
    int i;
    SqList l0;
    for(i=0;i<Max;i++)
        d[i]=rand()%Max+1;
    for(i=0;i<Max;i++)
        l0.r[i+1]=d[i];
    l0.length=Max;
    MergeSort(l0);
    print(l0);
    */
    return 0;
}
