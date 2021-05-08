#include "library.h" 
#include <malloc.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>


//1. Direct insertion sort in ascending order R[0..n-1]
void InsertSort(RecType R[],int n)
{
    int i,j;
    RecType tmp;
    for (i=1; i<n; i++)
    {
        tmp=R[i];
        j=i-1;
        //From right to left, find the insertion position of R[i] in the ordered area R[0..i-1]
        while (j>=0 && tmp.key<R[j].key)
        {
            //Move back the record whose keyword is greater than R [i]. Key
            R[j+1]=R[j];
            j--;
        }
        //Insert R [i] at j + 1
        R[j+1]=tmp;
    }
}

//4.Quick sort elements from R [S] to R [t]
void QuickSortR(RecType R[],int s,int t)
{
    int i=s,j=t;
    RecType tmp;
    //There are at least two elements in the interval
    if (s<t)
    {
        //Use the first record of the interval as the benchmark
        tmp=R[s];
        //Scan alternately from both ends of the interval to the middle until I = J
        while (i!=j)
        {
            while (j>i && R[j].key>=tmp.key)
                //Scan from right to left to find the first one less than tmp.key R [J]
                j--;
            //Find such r [J], R [i] "R [J] exchange
            R[i]=R[j];
            while (i<j && R[i].key<=tmp.key)
                //Scan from left to right to find the first greater than tmp.key Record R [i]
                i++;
            //Find this r [i], R [i] "R [J] exchange
            R[j]=R[i];
        }
        R[i]=tmp;
        QuickSortR(R,s,i-1);     //Sort left interval recursively
        QuickSortR(R,i+1,t);     //Sort right interval recursively
    }
}

/*4. Quick sort auxiliary function, unified interface with other algorithms,
 * internal call recursive quick sort*/
void QuickSort2(RecType R[],int n)
{
    QuickSortR(R, 0, n-1);
}

//7. Merge sort auxiliary 1-merge ordered lists.
void Merge(RecType R[],int begin,int mid,int end)
{
    RecType *R1;
    int i=begin,j=mid+1,k=0; /* K is the subscript of R1,
                              * I and j are the subscripts of paragraph 1 and 2 respectively*/
    R1=(RecType *)malloc((end-begin+1)*sizeof(RecType));  //Dynamic allocation of space
    while (i<=mid && j<=end)       //Cycle when both paragraphs 1 and 2 are not scanned
        if (R[i].key<=R[j].key)    //Put the record in paragraph 1 into R1
        {
            R1[k]=R[i];
            i++;
            k++;
        }
        else                            //Put the record in paragraph 2 in R1
        {
            R1[k]=R[j];
            j++;
            k++;
        }
    while (i<=mid)                      //Copy the rest of paragraph 1 to R1
    {
        R1[k]=R[i];
        i++;
        k++;
    }
    while (j<=end)                 // Copy the rest of paragraph 2 to R1
    {
        R1[k]=R[j];
        j++;
        k++;
    }
    for (k=0,i=begin; i<=end; k++,i++) // Copy R1 back into R
        R[i]=R1[k];
}

//7. Merge sort assist 2 -- one time merge
void MergePass(RecType R[],int length,int n) // Merge the whole number sequence once
{
    int i;
    for (i=0; i+2*length-1<n; i=i+2*length) // Merge two adjacent subtitles with length long
        Merge(R,i,i+length-1,i+2*length-1);
    if (i+length-1<n)                       // The remaining two sub-tables, the length of the latter is less than length
        Merge(R,i,i+length-1,n-1);          // Merge these two sub-tables.
}

// 7. Merge Sort
void MergeSort(RecType R[],int n)           // Bottom up two way merging algorithm
{
    int length;
    for (length=1; length<n; length=2*length) // Do log2n rounds to merge.
        MergePass(R,length,n);
}

// The following cardinal sort, for the sake of unified test, has the transformation
// 8. Auxiliary function of cardinal sort, creating linked list for cardinal sort
void CreateLink(RadixRecType *&p,RecType R[],int n)   // Generating linked list by post inserting method
{
    int i;
    RadixRecType *s,*t;
    for (i=0; i<n; i++)
    {
        s=(RadixRecType *)malloc(sizeof(RadixRecType));
        s->data = R[i].key;
        if (i==0)
        {
            p=s;
            t=s;
        }
        else
        {
            t->next=s;
            t=s;
        }
    }
    t->next=nullptr;
}

void write1(RadixRecType *&p,char*filename)
{
    // Is it empty
    if(p == nullptr)
    {
        printf("\n"
               "The node is empty, save failed.\n");
    }
    // pen a file
    FILE *fp = fopen(filename,"wb");
    if(fp == nullptr)
    {
        printf("Fail to open the file. \n");
    }
    // Save operation
    RadixRecType *q = p->next;
    while(q != nullptr)
    {
        fwrite(&q->data,sizeof(RecType),1,fp);
        q = q->next;
    }
    fclose(fp);
    fp = nullptr;
}

void read1(RadixRecType *&p,char *filename)
{
    if(p == nullptr)
    {
        printf("\n"
               "The node is empty, read failed.\n");
    }
    FILE *fp = fopen(filename,"rb");
    if(fp == nullptr)
    {
        printf("\n"
               "Fail to open the file.\n");
    }
    int ret = 0;
    while (true)
    {
        ret = fread(p,sizeof(RecType),1,fp);
        if(ret == 0)
        {
            if(feof(fp))
            {
                break;
            }
            else if(ferror(fp))
            {
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


//8. Auxiliary function of radix sort, release the linked list for radix sort
void DestroyLink(RadixRecType *&p)
{
    RadixRecType *q;
    while(p!=nullptr)
    {
        q=p->next;
        free(p);
        p=q;
    }
}

/*8. Realize cardinal sort: * P is the pointer to the linked list of the sequence to be sorted,
 * and cardinal R and keyword digit d have been defined as symbolic constants*/
void RadixSort(RadixRecType *&p)
{
    RadixRecType *head[Radix],*tail[Radix],*t; //Define the first and last pointers of each chain team
    int i,j;
    unsigned int k;
    unsigned int d1, d2=1;   //Used to separate the i-th digit, see note below
    for (i=1; i<=Digits; i++)                  //Cycle from low to high
    {
        d1=d2*10;
        for (j=0; j<Radix; j++)            //Initialize the first and last pointer of each chain
            head[j]=tail[j]=nullptr;
        while (p!=nullptr)                 //For each node in the original list, loop
        {
            k=(p->data%d1)/d2;             //Separate the i-th digit K
            if (head[k]==nullptr)          //Distribution
            {
                head[k]=p;
                tail[k]=p;
            }
            else
            {
                tail[k]->next=p;
                tail[k]=p;
            }
            p=p->next;                  //Take the next element to be sorted
        }
        p=nullptr;                         //Use p to collect all nodes again
        for (j=0; j<Radix; j++)             //For each chain loop
            if (head[j]!=nullptr)          //Collect
            {
                if (p==nullptr)
                {
                    p=head[j];
                    t=tail[j];
                }
                else
                {
                    t->next=head[j];
                    t=tail[j];
                }
            }
        t->next=nullptr;//The next field of the last node is set to null
        //D2 for separating the i-th digit is updated below
        d2*=10;
    }
}

void GetLargeData(RecType *&R, int n,char*filename)
{
    srand(time(nullptr));
    R=(RecType*)malloc(sizeof(RecType)*n);
    for(int i=0; i<n; i++)
        R[i].key= rand();
    //write1(reinterpret_cast<RadixRecType *&>(R), filename);
    printf("%d records generated.\n", n);
}

//Call a sort algorithm to complete the sort and return the sort time
long Sort(RecType *&R, int n, void f(RecType*, int))
{
    int i;
    long beginTime, endTime;
    auto *R1=(RecType*)malloc(sizeof(RecType)*n);
    for (i=0;i<n;i++)
        R1[i]=R[i];
    beginTime = time(nullptr);
    f(R1,n);
    endTime = time(nullptr);
    free(R1);
    return endTime-beginTime;
}

//Call the cardinality sorting algorithm to complete the sorting and return the sorting time
long Sort1(RecType *&R, int n, char *filename)
{
    long beginTime, endTime;
    RadixRecType *p;
    CreateLink(p,R,n);
    //write1(p,filename);
    beginTime = time(nullptr);
    RadixSort(p);
    endTime = time(nullptr);
    DestroyLink(p);
    return endTime-beginTime;
}

void Menu0()
{
    printf("\n\n\n\n\t\t\t|  Welcome to QG Training Camp!  |\n");
    printf("\t\t\t|  Something interesting.        |\n");
    printf("\t\t\t|  **The system provides         |\n");
    printf("\t\t\t|  **the following data volume   |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    1. 1w  filename: sort1.txt  |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    2. 5w  filename: sort2.txt  |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    3. 20w filename: sort2.txt  |\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|    0.Quit                      |\n");
    printf("\t\t\t|                                |\n");
    printf("\n\t\t\nChoose the amount of data you want to test:\n");
}

void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t\t\t-----------------------------\n");
    printf("\t\t\t\t\tPlease enter your choice:\n");
    while(1)
    {
        getchar();
        while(scanf("%d",&temp) != 1)
        {
            getchar();
            printf("The input is illegal, please re-enter.Thanks.--:");
        }
        if(temp==1)
        {
            system("cls");
            printf("\t\t\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\t\t\tSafely exited the system\n");
            printf("\t\t\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program
        }
        else if(temp==2)
        {
            Menu0();
            return;
        }
    }
}

void sum_time()
{
    int inputs = 0,select = 0;
    Menu0();
    inputs = scanf("%d",&select);
    while(inputs != 1)//Prevent users from entering illegally.
    {
        printf("Please enter an integer(But don't over 50 digits) : \n");
        getchar();
        inputs = scanf("%d",&select);
    }
    while(true)
    {
        if(select == 0)
        {
            Quit();
            break;
        }
        switch (select)
        {
            case 1: {
                RecType *R1;
                int n1 = 10000;
                char filename[10] = "sort1.txt";
                GetLargeData(R1, n1,filename);
                printf("Various sorts take time:\n");
                printf("Small data (Complete the third question):\n");
                printf("  Direct insertion sort:%ld\n", Sort(R1, n1, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R1, n1, QuickSort2));
                printf("  Merge sort:%ld\n", Sort(R1, n1,MergeSort));
                printf("Big data:(your choice can make a difference here.)\n"
                       "(Complete the forth question):\n");
                printf("  Cardinality sort:%ld\n", Sort1(R1, n1, filename));
                break;
            }
            case 2: {
                RecType *R2;
                int n2 = 50000;
                char filename[10] = "sort2.txt";
                GetLargeData(R2, n2, filename);
                printf("  Various sorts take time:\n");
                printf("Small data (Complete the third question):\n");
                printf("  Direct insertion sort:%ld\n", Sort(R2, n2, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R2, n2, QuickSort2));
                printf("  Merge sort:%ld\n", Sort(R2, n2, MergeSort));
                //printf("  Quick sort(non-recursive):%ld\n", Sort(R2, n2,QuickSort1));
                printf("  Cardinality sort:%ld\n", Sort1(R2, n2, filename));
                break;
            }
            case 3:{
                RecType *R3;
                int n3 = 200000;
                char filename[10] = "sort2.txt";
                GetLargeData(R3, n3,filename);
                printf("  Various sorts take time:\n");
                printf("  Direct insertion sort:%ld\n", Sort(R3, n3, InsertSort));
                printf("  Quick sort(recursive):%ld\n", Sort(R3, n3, QuickSort2));
                printf("  Merge sort:%ld\n", Sort(R3, n3, MergeSort));
                //printf("  Quick sort(non-recursive):%ld\n", Sort(R3, n3,QuickSort1));
                printf("Big data:(your choice can make a difference here.)\n"
                       "(Complete the forth question):\n");
                printf("  Cardinality sort:%ld\n", Sort1(R3, n3, filename));
                break;
            }
            default:break;
        }
        Menu0();
        inputs = scanf("%d",&select);
        while(inputs != 1)//Prevent users from entering illegally.
        {
            printf("Please enter an integer:\n");
            getchar();
            inputs = scanf("%d",&select);
        }
    }
}

int main()
{
    sum_time();
    return 0;
}
