//
// Created by HUAWEI on 2021-12-12.
//

#include "Common.h"
#ifndef STRING_C_STRING_H
#define STRING_C_STRING_H

Status assign_string(String T,char *chars);

/** 由串S复制得串T */
Status string_copy(String T,const String S);

/** S是否为空串 */
Status string_empty(const String S);

/**  比较串大小 */
int compare_string(String S,String T);

/** 返回串的元素个数 */
int length_string(String S);

/** 将S清为空串 */
Status clear_string(String S);

/** 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status string_concat(String T,const String S1,const String S2);

// 打印串
void print_string(String T);

/**  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/**  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
Status string_delete(String S,int position,int length);

/**  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1
    操作结果: 在串S的第pos个字符之前插入串T */
Status insert_string(String S,int pos,const String T);

/** 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0 */
/** 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(const String S, String T, int pos);


#endif //STRING_C_STRING_H
