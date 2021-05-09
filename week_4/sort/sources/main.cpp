#include "library.h"
#include <malloc.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include<time.h>


// Direct insertion sort in ascending order R[0..n-1]
void InsertSort(RecType R[], int n) {
    int i, j;
    RecType tmp;
    for (i = 1; i < n; i++) {
        tmp = R[i];
        j = i - 1;
        //From right to left, find the insertion position of R[i] in the ordered area R[0..i-1]
        while (j >= 0 && tmp.key < R[j].key) {
            //Move back the record whose keyword is greater than R [i]. Key
            R[j + 1] = R[j];
            j--;
        }
        //Insert R [i] at j + 1
        R[j + 1] = tmp;
    }
}

// Quick sort elements from R [S] to R [t]
void QuickSortR(RecType R[], int s, int t) {
    int i = s, j = t;
    RecType tmp;
    //There are at least two elements in the interval
    if (s < t) {
        //Use the first record of the interval as the benchmark
        tmp = R[s];
        //Scan alternately from both ends of the interval to the middle until I = J
        while (i != j) {
            while (j > i && R[j].key >= tmp.key)
                //Scan from right to left to find the first one less than tmp.key R [J]
                j--;
            //Find such r [J], R [i] "R [J] exchange
            R[i] = R[j];
            while (i < j && R[i].key <= tmp.key)
                //Scan from left to right to find the first greater than tmp.key Record R [i]
                i++;
            //Find this r [i], R [i] "R [J] exchange
            R[j] = R[i];
        }
        R[i] = tmp;
        QuickSortR(R, s, i - 1);     //Sort left interval recursively
        QuickSortR(R, i + 1, t);     //Sort right interval recursively
    }
}

/* Quick sort auxiliary function, unified interface with other algorithms,
 * internal call recursive quick sort*/
void QuickSort2(RecType R[], int n) {
    QuickSortR(R, 0, n - 1);
}


int Partition(RecType a[], int begin, int end) {
    RecType x = a[begin];
    int i = begin;
    int j = end + 1;
    RecType temp;

    while (i < j) {
        while (a[++i].key < x.key && i < end);
        while (a[--j].key > x.key);

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[begin] = a[end];
    a[j] = x;

    return j;


}


void QuickSort(RecType a[], int size) {
    int l = 0, h = size - 1;
    if (l >= h)
        return;

    int *s = new int[h - l + 1];
    int p = 0;
    s[p++] = l;
    s[p++] = h;

    int low, high, q;

    while (p > 0) {
        high = s[--p];
        low = s[--p];
        if (low >= high)
            break;

        q = Partition(a, low, high);

        if (q - low > high - q) {
            s[p++] = low;
            s[p++] = q - 1;

            if (high > q) {
                s[p++] = q + 1;
                s[p++] = high;
            }

        } else {
            s[p++] = q + 1;
            s[p++] = high;
            if (q > low) {
                s[p++] = low;
                s[p++] = q - 1;
            }
        }
    }
    delete[]s;
}

/* Quick sort auxiliary function, unified interface with other algorithms,
 * internal call recursive quick sort*/
void QuickSort3(RecType R[], int n) {
    QuickSort(R, n - 1);
}

// Merge sort auxiliary 1-merge ordered lists.
void Merge(RecType R[], int begin, int mid, int end) {
    RecType *R1;
    int i = begin, j = mid + 1, k = 0; /* K is the subscript of R1,
                              * I and j are the subscripts of paragraph 1 and 2 respectively*/
    R1 = (RecType *) malloc((end - begin + 1) * sizeof(RecType));  //Dynamic allocation of space
    while (i <= mid && j <= end)       //Cycle when both paragraphs 1 and 2 are not scanned
        if (R[i].key <= R[j].key)    //Put the record in paragraph 1 into R1
        {
            R1[k] = R[i];
            i++;
            k++;
        } else                            //Put the record in paragraph 2 in R1
        {
            R1[k] = R[j];
            j++;
            k++;
        }
    while (i <= mid)                      //Copy the rest of paragraph 1 to R1
    {
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= end)                 // Copy the rest of paragraph 2 to R1
    {
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = begin; i <= end; k++, i++) // Copy R1 back into R
        R[i] = R1[k];
}

// Merge sort assist 2 -- one time merge
void MergePass(RecType R[], int length, int n) // Merge the whole number sequence once
{
    int i;
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) // Merge two adjacent subtitles with length long
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 <
        n)                       // The remaining two sub-tables, the length of the latter is less than length
        Merge(R, i, i + length - 1, n - 1);          // Merge these two sub-tables.
}

//  Merge Sort
void MergeSort(RecType R[], int n)           // Bottom up two way merging algorithm
{
    int length;
    for (length = 1; length < n; length = 2 * length) // Do log2n rounds to merge.
        MergePass(R, length, n);
}

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a, int size) {
    int p0 = 0, p2 = size - 1, p1;        /* p0 starts from the beginning, p2 starts from the tail */
    for (p1 = 0; p1 <= p2; p1++) {
        if (a[p1] == 0)                   /* p1 goes faster than p0, put all 0s to the left */
            swap(&a[p1--],
                 &a[p0++]);               /* Execute i-- and i++ cancel each other out, compare whether the exchange can continue. */

        else if (a[p1] == 2)
            swap(&a[p1--],
                 &a[p2--]);
    }
}

// The following cardinal sort, for the sake of unified test, has the transformation
// Auxiliary function of cardinal sort, creating linked list for cardinal sort
void CreateLink(RadixRecType *&p, RecType R[], int n)   // Generating linked list by post inserting method
{
    int i;
    RadixRecType *s, *t;
    for (i = 0; i < n; i++) {
        s = (RadixRecType *) malloc(sizeof(RadixRecType));
        s->data = R[i].key;
        if (i == 0) {
            p = s;
            t = s;
        } else {
            t->next = s;
            t = s;
        }
    }
    t->next = nullptr;
}

void write1(RadixRecType *&p, char *filename) {
    // Is it empty
    if (p == nullptr) {
        printf("\n"
               "The node is empty, save failed.\n");
    }
    // pen a file
    FILE *fp = fopen(filename, "wb");
    if (fp == nullptr) {
        printf("Fail to open the file. \n");
    }
    // Save operation
    RadixRecType *q = p->next;
    while (q != nullptr) {
        fwrite(&q->data, sizeof(RecType), 1, fp);
        q = q->next;
    }
    fclose(fp);
    fp = nullptr;
}

void read1(RadixRecType *&p, char *filename) {
    if (p == nullptr) {
        printf("\n"
               "The node is empty, read failed.\n");
    }
    FILE *fp = fopen(filename, "rb");
    if (fp == nullptr) {
        printf("\n"
               "Fail to open the file.\n");
    }
    int ret = 0;
    while (true) {
        ret = fread(p, sizeof(RecType), 1, fp);
        if (ret == 0) {
            if (feof(fp)) {
                break;
            } else if (ferror(fp)) {
                fclose(fp);
                fp = nullptr;
                printf("Failed to read file.\n");
            }
        }
        p = p->next;
    }
    fclose(fp);
    fp = nullptr;
}


/* Auxiliary function of radix sort, release the linked list for radix sort */
void DestroyLink(RadixRecType *&p) {
    RadixRecType *q;
    while (p != nullptr) {
        q = p->next;
        free(p);
        p = q;
    }
}

/* Realize cardinal sort: * P is the pointer to the linked list of the sequence to be sorted,
 * and cardinal R and keyword digit d have been defined as symbolic constants*/
void RadixSort(RadixRecType *&p) {
    RadixRecType *head[Radix], *tail[Radix], *t; //Define the first and last pointers of each chain team
    int i, j;
    unsigned int k;
    unsigned int d1, d2 = 1;   //Used to separate the i-th digit, see note below
    for (i = 1; i <= Digits; i++)                  //Cycle from low to high
    {
        d1 = d2 * 10;
        for (j = 0; j < Radix; j++)            //Initialize the first and last pointer of each chain
            head[j] = tail[j] = nullptr;
        while (p != nullptr)                 //For each node in the original list, loop
        {
            k = (p->data % d1) / d2;             //Separate the i-th digit K
            if (head[k] == nullptr)          //Distribution
            {
                head[k] = p;
                tail[k] = p;
            } else {
                tail[k]->next = p;
                tail[k] = p;
            }
            p = p->next;                  //Take the next element to be sorted
        }
        p = nullptr;                         //Use p to collect all nodes again
        for (j = 0; j < Radix; j++)             //For each chain loop
            if (head[j] != nullptr)          //Collect
            {
                if (p == nullptr) {
                    p = head[j];
                    t = tail[j];
                } else {
                    t->next = head[j];
                    t = tail[j];
                }
            }
        t->next = nullptr;//The next field of the last node is set to null
        //D2 for separating the i-th digit is updated below
        d2 *= 10;
    }
}

void GetLargeData(RecType *&R, int n, char *filename) {
    srand(time(nullptr));
    R = (RecType *) malloc(sizeof(RecType) * n);
    for (int i = 0; i < n; i++)
        R[i].key = rand();
    //write1(reinterpret_cast<RadixRecType *&>(R), filename);
    printf("%d records generated.\n", n);
}

//Call a sort algorithm to complete the sort and return the sort time
long Sort(RecType *&R, int n, void f(RecType *, int)) {
    int i;
    long beginTime, endTime;
    auto *R1 = (RecType *) malloc(sizeof(RecType) * n);
    for (i = 0; i < n; i++)
        R1[i] = R[i];
    beginTime = time(nullptr);
    f(R1, n);
    endTime = time(nullptr);
    free(R1);
    return endTime - beginTime;
}

//Call the cardinality sorting algorithm to complete the sorting and return the sorting time
long Sort1(RecType *&R, int n, char *filename)
{
    long beginTime, endTime;
    RadixRecType *p;
    CreateLink(p, R, n);
    //write1(p,filename);
    beginTime = time(nullptr);
    RadixSort(p);
    endTime = time(nullptr);
    DestroyLink(p);
    return endTime - beginTime;
}

long Sort3(RecType *&R, int n, void f(RecType *, int)) {
    int i, j;
    int m = 0;
    long beginTime, endTime;
    auto *R1 = (RecType *) malloc(sizeof(RecType) * n);
    for (i = 0; i < n; i++)
        R1[i] = R[i];
    beginTime = time(nullptr);
    for (i = 0; i < 100; i++) {
        for (j = 100 * m; j < 100 * (m + 1); j++)
            R1[i] = R[i];
        f(R1, 100);
        m++;
    }

    endTime = time(nullptr);
    free(R1);
    return endTime - beginTime;
}


int tK_Big(int* a, int begin, int end, int k)
{
    if (begin >= end)
        return a[begin];
    int start = begin, last = end;
    int check = a[start];
    do
    {
        while (start < last && a[last] <= check)
            last--;
        a[start] = a[last];
        while (start < last && a[start] >= check)
            start++;
        a[last] = a[start];
    } while (start != last);
    a[start] = check;
    if (start == k)     // Backtracking at the same time
        return a[k];
    else
    {
        if (start > k)
            return tK_Big(a, begin, start, k);
        else
            return tK_Big(a, start + 1, end, k);
    }
}


void Menu0() {
    printf("\n\n\n\n\t\t\t|  Welcome to QG Training Camp!  |\n");
    printf("\t\t\t|  Something interesting.            |\n");
    printf("\t\t\t|  **The system provides             |\n");
    printf("\t\t\t|  **the following data volume       |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    1. 1w                           |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    2. 5w                           |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    3. 20w                          |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    4. 100*100                      |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    5. ColorSort                    |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    6. Find k number                |\n");
    printf("\t\t\t|                                    |\n");
    printf("\t\t\t|    0.Quit                          |\n");
    printf("\t\t\t|                                    |\n");
    printf("\n\t\t\nChoose the amount of data you want to test:\n");
}

void Quit() {
    system("cls");
    int temp;
    printf("\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t\t\t-----------------------------\n");
    printf("\t\t\t\t\tPlease enter your choice:\n");
    while (1) {
        getchar();
        while (scanf("%d", &temp) != 1) {
            getchar();
            printf("The input is illegal, please re-enter.Thanks.--:");
        }
        if (temp == 1) {
            system("cls");
            printf("\t\t\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\t\t\tSafely exited the system\n");
            printf("\t\t\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program
        } else if (temp == 2) {
            Menu0();
            return;
        }
    }
}

int input() {
    char num[3];
    scanf("%s", num);
    /* Check whether the user is legally inputting */
    while (!(num[0] >= '1' && num[0] <= '3' && num[1] == '\0'))
    {
        printf("something wrong with your input：");
        scanf("%s", num);
    }
    return (num[0] - 48);
}

void _creat_numbers(int a[],int size)
{
    int num;
    srand(666);
    //printf("Successfully created %d random numbers (within 100,000)\n",size);
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 32768;
    }
    putchar('\n');
}

void Save(int *a, int size) {
    FILE *fp1 = NULL;
    int i;
    if (!(fp1 = fopen("../F_Save.txt", "a+")))
    {
        printf("Fail to open file\n");
        return;
    }
    for (i = 0; i < size; i++)
    {
        fprintf(fp1, "%d", a[i]);
        fprintf(fp1, " ");
    }
    fprintf(fp1, "\n");
    fclose(fp1);
}

void sum_time()
{
    int inputs = 0, select = 0;
    Menu0();
    inputs = scanf("%d", &select);
    while (inputs != 1)//Prevent users from entering illegally.
    {
        printf("Please enter an integer(But don't over 50 digits) : \n");
        getchar();
        inputs = scanf("%d", &select);
    }
    while (true)
    {
        if (select == 0) {
            Quit();
            break;
        }
        switch (select)
        {
            case 1: {
                RecType *R1;
                int n1 = 10000;
                char filename[10] = "sort1.txt";
                GetLargeData(R1, n1, filename);
                printf("Various sorts take time:\n");
                printf("Small data (Complete the third question):\n");
                printf("  Direct insertion sort:%ld\n", Sort(R1, n1, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R1, n1, QuickSort2));
                printf("  Quick sort(no-recursive):%ld\n", Sort(R1, n1, QuickSort3));
                printf("  Merge sort:%ld\n", Sort(R1, n1, MergeSort));
                printf("Big data:(your choice can make a difference here.)\n"
                       "(Complete the forth question):\n");
                printf("  Cardinality sort:%ld\n", Sort1(R1, n1, filename));
                break;
            }
            case 2:
                {
                RecType *R2;
                int n2 = 50000;
                char filename[10] = "sort2.txt";
                GetLargeData(R2, n2, filename);
                printf("  Various sorts take time:\n");
                printf("Small data (Complete the third question):\n");
                printf("  Direct insertion sort:%ld\n", Sort(R2, n2, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R2, n2, QuickSort2));
                printf("  Quick sort(no-recursive):%ld\n", Sort(R2, n2, QuickSort3));
                printf("  Merge sort:%ld\n", Sort(R2, n2, MergeSort));
                //printf("  Quick sort(non-recursive):%ld\n", Sort(R2, n2,QuickSort1));
                printf("  Cardinality sort:%ld\n", Sort1(R2, n2, filename));
                break;
            }
            case 3:
                {
                RecType *R3;
                int n3 = 200000;
                char filename[10] = "sort3.txt";
                GetLargeData(R3, n3, filename);
                printf("  Various sorts take time:\n");
                printf("  Direct insertion sort:%ld\n", Sort(R3, n3, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R3, n3, QuickSort2));
                printf("  Quick sort(no-recursive):%ld\n", Sort(R3, n3, QuickSort3));
                printf("  Merge sort:%ld\n", Sort(R3, n3, MergeSort));
                //printf("  Quick sort(non-recursive):%ld\n", Sort(R3, n3,QuickSort1));
                printf("Big data:(your choice can make a difference here.)\n"
                       "(Complete the forth question):\n");
                printf("  Cardinality sort:%ld\n", Sort1(R3, n3, filename));
                break;
            }

            case 4: {
                RecType *R4;
                int n4 = 10000;
                char filename[10] = "sort4.txt";
                GetLargeData(R4, n4, filename);
                printf("  Various sorts take time:\n");
                printf("  Direct insertion sort:%ld\n", Sort3(R4, n4, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort3(R4, n4, QuickSort2));
                printf("  Quick sort(no-recursive):%ld\n", Sort3(R4, n4, QuickSort3));
                printf("  Merge sort:%ld\n", Sort3(R4, n4, MergeSort));
                //printf("  Quick sort(non-recursive):%ld\n", Sort(R3, n3,QuickSort1));
                printf("Big data:(your choice can make a difference here.)\n"
                       "(Complete the forth question):\n");
                printf("  Cardinality sort:%ld\n", Sort1(R4, n4, filename));
                break;
            }
            case 5: {
                int nm = 0;
                printf("please choose the scale of data:\n[1]:10000\n[2]:50000\n[3]:200000\n");
                int m = input();
                int size;
                if (m == 1)
                    size = 10000;
                if (m == 2)
                    size = 50000;
                if (m == 3)
                    size = 200000;
                int *a = (int *) malloc(sizeof(int) * size);
                srand(time(0));
                printf("A set of random numbers:\n");
                for (int i = 0; i < size; i++) {
                    nm = rand() % 3;
                    a[i] = nm;
                    printf("%d  ", nm);
                }
                putchar('\n');
                Save(a, size);

                double start = clock();
                ColorSort(a, size);
                double stop = clock();

                double duration = (double) (stop - start) / CLK_TCK;
                printf("it takse %f seconds\n", duration);


                system("pause");

                break;
            }
            case 6:
                {int k, k_value;
                int *a = NULL;
                int size;
                printf("please select the k\n");
                scanf("%d", &k);
                printf("please input the size of data \n");
                scanf("%d", &size);
                a = (int*)malloc(sizeof(int) * size);
                _creat_numbers(a, size);
                if (k > size)
                    break;
                double start = clock();
                k_value = tK_Big(a, 0, size-1, k);
                double stop = clock();
                double duration = (double) (stop - start) / CLK_TCK;
                printf("it takes %f second\n", duration);
                printf("the %d-th number:%d\n", k, k_value);
                system("pause");
                break;
        }
        default:
            break;
    }
    Menu0();
    inputs = scanf("%d", &select);
    while (inputs != 1)//Prevent users from entering illegally.
    {
        printf("Please enter an integer:\n");
        getchar();
        inputs = scanf("%d", &select);
    }
    }

}

int main() {
    sum_time();
    return 0;
}