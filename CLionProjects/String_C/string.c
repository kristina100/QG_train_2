//
// Created by HUAWEI on 2021-12-12.
//
#include "string.h"


/* 由串S复制得串T */
Status string_copy(String T,const String S)
{
    int i=0;
    while(i<=S[0])
    {
        T[i]=S[i];
        i++;
    }
    return OK;
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status string_empty(const String S)
{
    if(S[0]==0)
        return TRUE;
    else
        return FALSE;
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int compare_string(String S,String T)
{
    int i;
    for(i=1;i<=S[0]&&i<=T[0];++i)
        if(S[i]!=T[i])
            return S[i]-T[i];
    return S[0]-T[0];
}

/* 计算串的元素个数 */
int length_string(String S)
{
    return S[0];
}

Status assign_string(String T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSIZE)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
            T[i]=*(chars+i-1);
        return OK;
    }
}

/* 初始条件:串S存在。操作结果:将S清为空串 */
Status clear_string(String S)
{
    S[0]=0; /*  令串长为零 */
    return OK;
}

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status string_concat(String T,const String S1,const String S2)
{
    int i;
    if(S1[0]+S2[0]<=MAXSIZE)
    {   //  未截断
        for(i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(i=1;i<=S2[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=S1[0]+S2[0];
        return TRUE;
    }
    else
    {   //  截断S2
        for(i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(i=1;i<=MAXSIZE-S1[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=MAXSIZE;
        return FALSE;
    }
}

// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。
// 其中,T非空,1≤pos≤StrLength(S)。
int Index(const String S, String T, int pos)
{
    int i = pos;	// i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配
    int j = 1;				// j用于子串T中当前位置下标值
    while (i <= S[0] && j <= T[0]) // 若i小于S的长度并且j小于T的长度时，循环继续
    {
        if (S[i] == T[j]) 	// 两字母相等则继续
        {
            ++i;
            ++j;
        }
        else 				// 指针后退重新开始匹配
        {
            i = i-j+2;		// i退回到上次匹配首位的下一位
            j = 1; 			// j退回到子串T的首位
        }
    }
    if (j > T[0])
        return i-T[0];
    else
        return 0;
}


//  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1
//  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE
Status insert_string(String S,int pos,const String T)
{
    int i;
    if(pos<1||pos>S[0]+1)
        return ERROR;
    if(S[0]+T[0]<=MAXSIZE)
    {
        //  完全插入
        for(i=S[0];i>=pos;i--)
            S[i+T[0]]=S[i];
        for(i=pos;i<pos+T[0];i++)
            S[i]=T[i-pos+1];
        S[0]=S[0]+T[0];
        return TRUE;
    }
    else
    { /*  部分插入 */
        for(i=MAXSIZE;i<=pos;i--)
            S[i]=S[i-T[0]];
        for(i=pos;i<pos+T[0];i++)
            S[i]=T[i-pos+1];
        S[0]=MAXSIZE;
        return FALSE;
    }
}

/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
Status string_delete(String S,int pos,int len)
{
    int i;
    if(pos<1||pos>S[0]-len+1||len<0)
        return ERROR;
    for(i=pos+len;i<=S[0];i++)
        S[i-len]=S[i];
    S[0]-=len;
    return OK;
}



//  输出字符串T
void print_string(String T)
{
    int i;
    for(i=1;i<=T[0];i++)
        printf("%c",T[i]);
    printf("\n");
}

