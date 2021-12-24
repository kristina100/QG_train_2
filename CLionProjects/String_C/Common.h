//
// Created by HUAWEI on 2021-12-12.
//

#ifndef STRING_C_COMMON_H
#define STRING_C_COMMON_H
//
// Created by HUAWEI on 2021-12-12.
//

#ifndef STRING_COMMON_H
#define STRING_COMMON_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* 函数结果状态代码 */
typedef int ElemType;

typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */




#endif //STRING_COMMON_H

#endif //STRING_C_COMMON_H
