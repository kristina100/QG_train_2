//
// Created by HUAWEI on 2021-12-23.
//

/*<><><>程序预处理<><><><><>加载头文件，定义结构体，宏定义*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define NUM1 "%-12s%-12s%-16s%-8.1f%-8.1f%-8.1f%-8.1f"
#define NUM2 "%-12s%-12s%-16s%-9.1f%-9.1f%-9.1f%-9.1f%3d"
#define DATA1 p->data.num,p->data.name,p->data.classes,p->data.math,p->data.English,p->data.physic,p->data.math+p->data.English+p->data.physic
#define DATA2 p->data.num,p->data.name,p->data.classes,p->data.math,p->data.English,p->data.physic,p->data.math+p->data.English+p->data.physic,p->data.position
#define END "-----------------------------------------------------------------------------------------"
#define Nofind/*提示没有找到该学生的信息*/ "出错~   请看温馨小提示哦！"
int saveflag = 0;/*saveflag是否需要存盘的全局变量,temp文件是否有数据的变量*/

/*定义与学生信息有关的数据结构*/
struct student
{
    char num[20]; /*学号*/
    char name[20];/*学生姓名*/
    char classes[10];  /*班级*/
    float math;     /*数学*/
    float English;  /*英语*/
    float physic;  /*物理*/
    float score;    /*总分*/
    int position; /*名次*/
};

/*定义每条记录或者结点的数据结构，标记为 node*/
typedef struct node
{
    struct student data;/*数据域*/
    struct node* next;  /*指针域*/
}Node, * Link;/*Node为node类型的结构变量，*Link为node类型的指针变量*/

/*自定义函数声明*/

void color(int x);
void HideCursor();
void toxy(int x,int y);
Link creat();
void printheader1();
void printheader2();
void menu();
void menu2(Link head);
void Disp(Link head);
void Disp2(Link head);
void Wrong();
void Copy();
void Modify(Link head);
void Input(Link head);
void Delete(Link head);
void Inquire(Link head);
void Tongji(Link head);
void Sort(Link head);
void Save(Link head);
void quit(Link head);
int Tixing();
int sign();

