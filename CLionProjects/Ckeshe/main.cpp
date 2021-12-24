#include"define.h"
void color(int x)    //设置            颜色
{
    if(x>=0&&x<=15)/*SetConsoleTextAttribute函数
	                 靠一个字节的低四来控制前景色，高四位来控制背景色。*/
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
    }/*GetStdHandle（）返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
	   此处为标准输出句柄
	   	SetConsoleTextAttribute()函数的参数：（控制台屏幕缓冲区的句柄。句柄必须具有GENERIC_READ访问权限，字符属性）*/
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
    }
}

void HideCursor()     //隐藏           光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; /*CONSOLE_CURSOR_INFO包含有关控制台光标的信息*/
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    /*BOOL WINAPI SetConsoleCursorInfo(_In_  HANDLE hConsoleOutput, _In_const CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
     指向CONSOLE_CURSOR_INFO结构的指针，该结构为控制台屏幕缓冲区的光标提供新的规范*/
}

void toxy(int x, int y)      //将光标移动到     X  , Y坐标处
{
    COORD pos = { static_cast<SHORT>(x) , static_cast<SHORT>(y) };   /*定义表示一个字符在控制台屏幕上的坐标的对象*/
    HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);/*SetConsoleCursorPosition是API中定位光标位置的函数*/
}

Link creat()
{
    Link head;            /*定义链表*/
    FILE* fp;             /*文件指针*/
    int select,count=0;   /*ch保存选择结果变量,count保存文件的记录条数（或者结点个数）*/
    char ch;              /*保存用户的字符输入，比如后面部分的“y,n,Y,N”*/
    Node* p, * r;         /*定义记录指针变量*/
    head = (Node*)malloc(sizeof(Node));
    if (!head)
    {
        printf("\n allocate memory failure \n");/*如果没有申请到，打印提示信息*/
        return 0; /*返回主界面*/
    }
    head->next = NULL;
    r = head;
    fp = fopen("student.txt", "a+");
    /*以追加的方式打开一个文本文件，可读可写，若此文件不存在，会创建此文件*/
    if (fp == NULL)
    {
        printf("\n\t\t\t\topen file error!\n");
        exit(0);
    }
    while(!feof(fp))
        /*一次从文件中读取一条记录*/
    {
        p = (Node*)malloc(sizeof(Node));/*开辟了一个新的空间1*/
        if (!p)
        {
            printf("memory malloc failure!\n");/*没有申请内存成功*/
            exit(0);/*退出*/
        }
        if(fread(p,sizeof(Node),1,fp)==1)
        {
            p -> next = NULL;/*一次只读取一条，读完就结束*/
            r -> next = p;   /*新增一个结点*/
            r = p;	         /*r往后移动一个位置*/
            count++;	     /*记录条数加一*/
        }
    }
    fclose(fp);              /*关闭文件*/
    return head;
}

/*格式化输出表头*/
void printheader1()
{
    color(11);
    toxy(20,8);
    printf(END);
    toxy(28,9);
    printf("学号        姓名        班级        高数    大英    物理    总分");
    toxy(20,10);
    printf("END");
}

void printheader2()
{
    color(11);
    toxy(20,8);
    printf(END);
    toxy(28,9);
    printf("学号         姓名        班级         高数    大英    物理    总分    排名");
    toxy(20,10);
    printf(END);
}

/*<><><><><>主菜单<><><><><>*/
void menu()
{
    system("cls");     /*清屏*/
    HideCursor();
    color(14);
    toxy(35,6);		printf("|               学生奖学金管理系统               |");
    toxy(35,7);		printf("|                                                |");
    toxy(35,8);		printf("|       1. 信息录入           2. 信息总览        |");
    toxy(35,9);		printf("|                                                |");
    toxy(35,10);	printf("|       3. 查询记录           4. 统计信息        |");
    toxy(35,11);	printf("|                                                |");
    toxy(35,12);	printf("|       5. 删除信息           6. 修改信息        |");
    toxy(35,13); 	printf("|                                                |");
    toxy(35,14);	printf("|       7. 排序               8. 保存信息        |");
    toxy(35,15); 	printf("|                                                |");
    toxy(35,16);	printf("|       9. 复制文件           0. 退出系统        |");
    toxy(35,17);	printf("|                                                |");
    toxy(35,18);	printf("|                                                |");
    toxy(35,19);	printf("|                                                |");

}

int Tixing(Link head)
{
    if (head->next==NULL)
    {
        system("cls");
        toxy(45,8);		printf("没有学生记录哦,请添加一些信息吧！");
        toxy(45,9);		system("pause");
        return 1;
    }
    else
        return 0;
}

void menu2(Link head)
{
    system("cls");
    char temp[10];	/*保存输入的学号*/
    Node*p;		    /*临时指针变量*/
    p=head->next;
    color(14);
    toxy(35,6);		printf("|               学生奖学金管理系统               |");
    toxy(35,7);		printf("|                                                |");
    toxy(35,8);		printf("|               信息查询                         |");
    toxy(40,12);	printf("请输入您的学号:");
    scanf("%s",temp);
    while(p)
    {
        if(strcmp(p->data.num,temp)==0)
        {
            break;
        }
        else
            p=p->next;
    }
    if(p)
    {
        system("cls");
        printheader2();
        toxy(28,11);
        printf(NUM2,DATA2);
        toxy(20,16);
        printf("【PS:更多功能在开发中,敬请期待O(∩_∩)O】");
    }
    else
    {
        system("cls");
        toxy(30,11);
        printf("没有此学号,请退出系统,进行信息确认后再来吧^-^!");
        toxy(30,14);
        system("pause");
    }
}


/*<><><><><>显示记录<><><><><>*/
void Disp(Link head)
/*  显示链表head中头结点的指针，头结点不储存的信息
	指针域指向的是后结点（即首元结点）才有学生的信息*/
{
    system("cls");
    Node* p;	/*临时指针变量*/
    int i=10;	/*光标y值*/
    p = head->next;
    if(Tixing(head))
    {
        return;
    }
    printheader1();/*输出表格头部*/
    while (p)/*逐条输出链表中储存的信息*/
    {
        i+=2;
        toxy(28,i);
        printf(NUM1,DATA1);
        p = p->next;/*直接移向下一个结点，输出*/
        toxy(20,i-1);
        printf(END);
    }
    system("pause");
}
void Disp2(Link head)
{
    system("cls");
    Node* p;
    p = head->next;
    int i=10;
    Tixing(head);
    printf("\n\n");
    printheader2();/*输出表格头部*/

    while (p)/*逐条输出链表中储存的信息*/
    {
        i+=2;
        toxy(28,i);
        printf(NUM2,DATA2);
        p = p->next;/*直接移向下一个结点，输出*/
        toxy(20,i-1);
        printf(END);
    }
    system("pause");
}
/*提示输出按键错误信息*/
void Wrong()
{
    toxy(35,24);	printf("输入错误，请重新输入哦！");
    return;
}
/*<><><><><>修改<><><><><>*/
/*系统按照输入的学号查找到该记录，然后提示用户修改学号之外的值，编号不能修改*/
void Modify(Link head)
{
    system("cls");
    Node* p;	/*临时指针变量*/
    char num[20];	/*保存输入学号*/
    color(11);
    if(Tixing(head))
    {
        return;
    }
    toxy(45,6);		printf("修改学生记录");
    toxy(45,6);		printf("-----------------------------");
    toxy(45,8);		printf("注：学号不能修改!");
    toxy(45,10);	printf("-----------------------------");
    toxy(45,11);	printf("请输入学号:");
    scanf("%s",num);
    while(strlen(num)>10)
    {
        printf("输入数据错误，请重新输入！\n");
        scanf("%s",num);
    }
    p=head->next;
    while(p)//p！=NULL
    {
        if(strcmp(p->data.num,num)==0)
            break;
        else
            p=p->next;
    }
    if (p)//p!=NULL
    {
        toxy(45,12);	printf("学号:%s", p->data.num);
        toxy(45,13);	printf("原名字：:%s", p->data.name);
        toxy(45,14);
        getchar();
        printf("请输入学生姓名：");gets(p->data.name);
        toxy(45,15);
        printf("请输入学生班级：");gets(p->data.classes);
        toxy(45,16);
        printf("请输入数学成绩：");
        scanf("%f",&p->data.math);getchar();
        toxy(45,17);
        printf("请输入英语成绩：");
        scanf("%f",&p->data.English);getchar();
        toxy(45,18);
        printf("请输入物理成绩：");
        scanf("%f",&p->data.physic);getchar();
        p->data.score=(p->data.physic)+(p->data.English)+(p->data.math);
        saveflag = 1;/*修改记录  saveflag记作 1 尚未存盘*/
        system("cls");
        toxy(45,12);
        printf("修改成功！");
        Disp(head);
    }
    else
        printf(Nofind);
    system("pause");
}
/*<><><><><>信息录入<><><><><>*/
/*进入学生奖学金管理系统，若数据为空，将从单链表的头部开始，增加学生记录结点，
  否则将该学生的记录结点添加在链表尾部*/
void Input(Link head)
{
    color(11);
    Node* p, * r, * s;/*实现添加操作的临时的结构体变量,
					    p是用来临时储存开辟空间，
					    s用来记住头结点后一位地址（数据是从头结点的后一位来储存）
					    r是用来移动到最后一位*/
    char ch, num[20];
    int flag = 0; 		/*标记重复编号*/
    r = head;
    s = head->next;    /*s记住头结点后一位指针*/
    system("cls");
    //Disp(head);        /*先打印出已有的学生信息*/

    while (r->next)    /*不空  继续*/
        r = r->next;   /*将指针移至于链表最末尾，准备添加记录*/
    while (1)          /*一次可输入多条记录，直至输入编号为0的记录结点添加操作*/
    {
        while (1)
            /*输入编号，保证该编号没有被使用，若输入的编号为0，则退出添加操作*/
        {
            while(1)/*出错提醒*/
            {
                system("cls");
                toxy(45,6);
                printf("欢迎进入学生奖学金管理系统\n");
                toxy(50,8);
                printf("信息录入：\n");
                toxy(45,10);
                printf("请输入学号（判断）(0 to quit):");
                scanf("%s",num);

                if(strlen(num)>20)
                {
                    toxy(45,12);
                    printf("您输入数据有误，请重新输入：\n");
                    scanf("%s",num);
                }
                else
                    break;
            }
            flag = 0;
            if (strcmp(num, "0") == 0)/*如果输入的为0，则退出添加操作，返回主界面*/
            {
                return;
            }
            s = head->next;
            while (s)/*当s不是空指针时*/
                /*查询该编号是否已经存在，若存在，则要求重新输入一个未被占用的编号*/
            {
                if (strcmp(s->data.num, num) == 0)
                {
                    flag = 1;
                    break;
                }
                s = s->next;//没找到，就移动到下一位
            }
            if (flag == 1)/*提示用户是否重新输入*/
            {
                getchar();
                toxy(45,10);
                printf("编号 %s 已经存在，是否重新输入？（Y/N）：", num);
                scanf("%c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                    system("cls");
                    continue;
                }
                else
                    return;/*返回主界面*/
            }
            else
            {
                break;//说明编号没有被使用
            }
        }
        p = (Node*)malloc(sizeof(Node));/*申请内存空间*/
        if (!p)
        {
            system("cls");
            toxy(45,8);		printf("申请内存失败！");/*如果没有申请到，打印提示信息*/
            toxy(45,9);		system("pause");
            return;/*返回主界面*/
        }
        strcpy(p->data.num,num);
        toxy(45,12);	printf("请输入学生姓名：");
        scanf("%s",p->data.name);
        toxy(45,13);	printf("请输入学生班级：");
        scanf("%s",p->data.classes);
        toxy(45,14);	printf("请输入数学成绩：");
        scanf("%f",&p->data.math);getchar();
        toxy(45,15);	printf("请输入英语成绩：");
        scanf("%f",&p->data.English);getchar();
        toxy(45,16);	printf("请输入物理成绩：");
        scanf("%f",&p->data.physic);getchar();
        p->data.position=0;
        p->data.score=(p->data.physic)+(p->data.English)+(p->data.math);
        p->next = NULL;/*表明这是链表尾部结点*/
        r->next = p;   /*r是指向原链表的最后一个，增加结点*/
        r=p;
        saveflag = 1;
    }
    return;
}
/*<><><><><>删除学生记录<><><><><>*/
/*删除学生记录，先找到保存该学生记录的结点
  然后删除该结点*/
void Delete(Link head)
{
    system("cls");
    Node* p, * r;	/*r用于记住目标结点前一位，p查找目标结点*/
    char num[10],name[10],m,n;/*num保存学号，name保存姓名，m，n记住选择*/
    int t;	//记住选择
    p=head->next;
    if(Tixing(head))
    {
        return;
    }
    system("cls");
    color(12);
    toxy(45,6);		printf("-----学生奖学金管理系统-----");
    toxy(50,8);		printf("信息删除");
    toxy(47,10);	printf("1)  按学号删除");
    toxy(47,12);	printf("2)  按姓名删除");
    toxy(47,14);	printf("按 0 返回主菜单");
    scanf("%d",&t);
    if(Tixing(head)==0)//判断文件初始是否有数据，有则执行 无则返回主菜单信息录入
    {
        if (t == 1)
        {
            system("cls");
            toxy(47,10);
            printf("请输入学号:");
            scanf("%s",num);
            while(p)//p不为空
            {
                if(strcmp(p->data.num,num)==0)
                    break;//找到则结束
                else
                    p=p->next;
            }
            if (p)//判断是否找到 找到则执行
            {
                system("cls");
                toxy(45,11);	printf("--------------------------");
                toxy(45,12);	printf("|    您确定要删除吗？    |");
                toxy(45,14);	printf("|  1.确定      2.取消    |");
                toxy(45,15);	printf("--------------------------");
                m=getch();
                if(m='1')
                {
                    system("cls");
                    r = head;
                    while (r->next != p)
                        r = r->next;/*没找到，继续找*/
                    r->next = p->next;/*跳过p*/
                    free(p);/*释放内存*/
                    toxy(47,12);
                    printf("成功删除！\n");
                    saveflag = 1;
                    Disp(head);
                }
                else if(m='2')
                {
                    return;
                }
            }//end of 确定if
            else
            {
                toxy(47,10);
                printf("对不起，没有找到此编号的学生哦\n");
            }
            system("pause");
        }//end of 选择if
        else if (t == 2)
        {
            system("cls");
            toxy(47,10);
            printf("请输入学生名字:");
            scanf("%s",name);
            while(p)
            {
                if(strcmp(p->data.name,name)==0)
                    break;
                else
                    p=p->next;
            }
            if (p)/*p!=NULL*/
            {
                system("cls");
                toxy(45,11);	printf("--------------------------");
                toxy(45,12);	printf("|    您确定要删除吗？    |");
                toxy(45,14);	printf("|  1.确定      2.取消    |");
                toxy(45,15);	printf("--------------------------");
                n=getch();
                if(n='1')
                {
                    system("cls");
                    r = head;
                    while (r->next != p)
                        r = r->next;/*没找到，继续找*/
                    r->next = p->next;/*跳过p*/
                    free(p);/*释放内存*/
                    toxy(47,12);
                    printf("成功删除！\n");
                    saveflag = 1;
                    Disp(head);
                }
                else if(n='2')
                {
                    return;
                }
            }//end of确定if
            else
            {
                toxy(47,12);
                printf("对不起，没有找到此学生哦\n");
            }
        }//end of 选择 elseif
        else if(t == 0)
            return;
    }//end of 外部if
    else
        system("pause");
    return;
}
/*查询学生记录
当用户执行此查询任务时，系统会提醒用户进行查询字段的选择
 按照进行查询，若该学生的记录存在
 则会打印输出该学生记录*/
void Inquire(Link head)
{
    system("cls");
    Node* p;
    int searchinput1,i=0,j=10,k;//i保存输出前几名，j保证toxy函数的y值，k保证查询班级名次下限
    float Shang,Xia;	//上限下限
    char searchinput2[10],m;	//保存输入
    if(	Tixing(head))
    {
        return;
    }
    color(12);
    toxy(20,5);
    printf("温馨小提示！");
    color(11);
    toxy(20,6);		printf("如果您录入数据尚未进行名次排序，请先返回主菜单，完成这两项操作吧O(∩_∩)O");
    toxy(35,8);		printf("|       学生奖学金管理系统       |");
    toxy(35,10);	printf("|       1)按照名次查询           |");
    toxy(35,12);	printf("|       2)按照班级查询           |");
    toxy(35,14);	printf("|       3)按照分数段查询         |");
    toxy(35,16);	printf("|       0）返回                  |");
    toxy(35,18);	printf("请输入您的选择:");
    m = getch();
    while(m!='1'&&m!='2'&&m!='3'&&m!='0')
    {
        toxy(35,18);printf("输入错误请重新修改\n");
        m = getch();
    }
    p=head->next;
    if (m =='1')//按照名次查询某个人的成绩
    {
        system("cls");
        toxy(35,8);
        printf("请输入您想查询的名次:");
        scanf("%d",&searchinput1);
        while(p)
        {
            if(p->data.position==searchinput1)
                break;
            else
                p=p->next;
        }
        if (p)
        {
            printheader2();
            toxy(28,12);	printf(NUM2,DATA2);
        }
        else
        {
            toxy(28,16);
            printf(Nofind);
        }
        system("pause");
    }
    else if(m=='2')
    {
        system("cls");
        toxy(35,6);		printf("请输入您想查询的班级:");
        scanf("%s",searchinput2);
        toxy(35,7);		printf("输入您想查询名次的下限:");
        scanf("%d",&k);
        printheader1();
        while(p)
        {
            if(strcmp(p->data.classes,searchinput2)==0&&i<k)
            {
                toxy(28,12+i);
                printf(NUM1,DATA1);
                i++;
            }
            p=p->next;
        }
    }
    else if(m=='3')
    {
        system("cls");
        toxy(35,8);		printf("管理员您好！本次成绩总分300分  请输入您想查询的分数段:");
        toxy(35,9);		printf("请输入上限:");	scanf("%f",&Shang);
        toxy(35,10);	printf("请输入下限:");	scanf("%f",&Xia);
        system("cls");
        printheader1();
        while(p)
        {
            if(p->data.score<=Shang&&p->data.score>=Xia)
            {
                j+=2;
                toxy(30,j);		printf(NUM1,DATA1);
                toxy(20,j-1);	printf(END);
            }
            p=p->next;
        }
        toxy(35,j+1);
    }
    else if(m=='0')
        return;
    system("pause");
}
/*<><><><><>统计<><><><><>
----统计学生的*/
void Tongji(Link head)
{
    system("cls");
    float sum=0, gMIN, gMAX, EMIN, EMAX, pMIN, pMAX, SMAX=0,SMIN=0;
    char cla[10],m;	//保存输入值
    Node *p1,*p;	//临时指针变量
    color(11);
    if(Tixing(head)==0)
    {
        system("cls");
        toxy(45,6);
        printf("-----学生奖学金管理系统-----");
        toxy(50,8);		printf("分数统计");
        toxy(45,10);	printf("1) 总计");
        toxy(45,12);	printf("2) 分班统计");
        toxy(45,14);	printf("0) 返回");
        toxy(45,16);	printf("请输入您的选择:");
        m = getch();
        while(m!='1'&&m!='2'&&m!='0')
        {
            toxy(45,16);	printf("输入错误,请按照提示输入\n");
            m = getch();
        }
        p=p1=head->next;
        if( m == '1')
        {
            system("cls");
            gMIN = gMAX = p1->data.math;
            EMIN = EMAX = p1->data.English;
            pMIN = pMAX = p1->data.physic;
            while(p1->next!=NULL)
            {
                if(p1->data.math > gMAX)
                    gMAX = p1->data.math;
                if(p1->data.math < gMIN)
                    gMIN = p1->data.math;
                if(p1->data.English > EMAX)
                    EMAX = p1->data.English;
                if(p1->data.English < EMIN)
                    EMIN = p1->data.English;
                if(p1->data.physic > pMAX)
                    pMAX = p1->data.physic;
                if(p1->data.physic < pMIN)
                    pMIN = p1->data.physic;
                if(p1->data.score > SMAX)
                    SMAX = p1->data.score;
                p1 = p1->next;
            }
            toxy(45,8);		printf("|            总计               |");
            toxy(45,10);	printf("     数学最高分为:%4.1f        ", gMAX);
            toxy(45,11);	printf("     数学最低分为:%4.1f        ", gMIN);
            toxy(45,12);	printf("     英语最高分为:%4.1f        ", EMAX);
            toxy(45,13);	printf("     英语最低分为:%4.1f        ", EMIN);
            toxy(45,14);	printf("     物理最高分为:%4.1f        ",pMAX);
            toxy(45,15);	printf("     物理最低分为:%4.1f        ",pMIN);
            toxy(45,16); 	printf("     总成绩最高分为:%4.1f      ", SMAX);
            toxy(45,17);	printf("                               ");
            system("pause");
        }
        else if(m=='2')
        {
            system("cls");
            toxy(45,6);		printf("分班统计");
            toxy(45,8);		printf("请输入你想统计的班级总分:");
            scanf("%s",cla);
            while(p->next)
            {
                if(strcmp(p->data.classes,cla)==0)
                    sum+=p->data.score;
                p=p->next;
            }
            toxy(45,9);		printf("%s:",cla);
            toxy(45,10);	printf("总分:%.2f",sum);
            toxy(30,12);	printf("【PS:更多统计功能更在开发中,敬请期待O(∩_∩)O】");
            system("pause");
        }
        else if(m=='0')
            return;
    }
    else
        system("pause");
    return;
}
/*<><><><><>排序<><><><><>*/
void Sort(Link head)
{
    system("cls");
    Node* p, *q, *r, *s, *h1;/*p每次内循环的首结点
							   r内循环结束最小或最大关键字结点的前驱结点
							   s指向最小或最大关键字的结点
							   h1是新链表的首结点*/
    int n=1;
    char m;
    if(Tixing(head))
    {
        return;
    }
    Disp(head);    /*显示之前记录*/
    system("cls");
    toxy(40,10);	printf("---------------------------");
    toxy(45,12);	printf("1) 按总分排序");
    toxy(45,14);	printf("2) 按学号排序");
    toxy(45,16);    printf("0) 返回");
    toxy(40,18);	printf("---------------------------");
    toxy(45,20);	printf("请输入您的选择:");
    m = getch();
    while(m!='1'&&m!='2'&&m!='0')
    {
        toxy(45,22);	printf("输入错误请重新修改");
        m = getch();
    }

    h1 = p = (Node*)malloc(sizeof(Node));/*用于创建新的头结点*/
    if(!p)
    {
        printf("error!\n");
        exit(0);
    }
    if(m=='1')
    {
        p->next=head->next;
        //head所指向的结点为不存有数据的结点，下一个结点才有学生记录
        while(p->next != NULL)
        {
            q=p->next;
            r=p;
            while(q->next != NULL)//内循环找到当前总分最大结点
            {
                if(q->next->data.score > r->next->data.score)
                    r=q;//r为记录当前总分最高结点的前驱结点的指针变量
                q = q->next;//移向下一个结点
            }
            r->next->data.position=n;//结束循环后，此时r是总分最高的结点的前一个结点
            n++;
            if(r != p)//就是确认原来结点的最大，不是此时得到的r，改变指针的关系
                //将总分最大的的结点与本轮循环的首结点进行位置交换
            {
                s = r->next;//s指向最小结点
                r->next = s->next;//r的指针域指向当前p指针所指向的下一个结点
                s->next = p->next; //s的指针域指向当前p指针所指向的下一个结点
                p->next = s;//p的指针域指向本次循环结束以后总分最大的的结点
            }
            p=p->next;//移至下一个结点
        }//外层while
        p->next=NULL;
        head->next = h1->next;//将排序好的给原来链表的头结点
        Disp2(head);//显示
    }
    else if(m=='2')
    {
        p->next=head->next;
        //head所指向的结点为不存有数据的结点，下一个结点才有学生记录
        while(p->next != NULL)
        {
            q=p->next;
            r=p;
            while(q->next != NULL)//内循环找到当前学号最小结点
            {
                if(atoi(q->next->data.num) < atoi(r->next->data.num))
                    r=q;//r为记录当前最小结点的前驱结点的指针变量
                q = q->next;//移向下一个结点
            }
            if(r != p)
                //表示原来结点不是学号最小的结点，改变指针的关系，将学号最小的结点与本轮循环的首结点进行位置交换
            {
                s = r->next;//s指向最小结点
                r->next = s->next;//r的指针域指向当前p指针所指向的下一个结点
                s->next = p->next; //s的指针域指向当前p指针所指向的下一个结点
                p->next = s;//p的指针域指向本次循环结束以后学号最小的结点
            }
            p=p->next;//移至下一个结点，p又是下一个循环的首结点。
        }//外层while
        head->next = h1->next;//将排序好的给原来链表的头结点
        Disp(head);//显示
    }
    else if(m=='0')
        return;
}
/*<><><><><>储存记录<><><><><>*/
void Save(Link head)
{
    FILE* fp;	//文件指针
    Node* p;	//临时指针变量
    int count = 0;
    fp = fopen("student.txt", "w");/*以只写的方式打开*/
    if (fp == NULL)/*打开文件失败*/
    {
        printf("\t\t\t\topen file error!\n");
        exit(0);//结束程序
    }
    p = head->next;
    while(p)//一次只输一条
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)
        {
            p = p->next;
            count++;
        }
        else
        {
            break;
        }
    }
    if (count > 0)
    {
        getchar();
        printf("\n\t\t\t成功保存，成功存入信息%d条。",count);
        system("pause");
        saveflag = 0;
    }
    else
    {
        system("cls");
        printf("没有记录");
        system("pause");
    }
    fclose(fp);/*关闭此文件*/
}
/*<><><><><>退出系统<><><><><>*/
void quit(Link head)
{
    system("cls");
    char t, ch;//记住输入
    color(11);
    while(1)
    {
        if(saveflag == 1)
        {
            getchar();
            printf("\n\t\t\t\tWhether save the modified record to file?(Y/N):");
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
                Save(head);
        }
        break;
    }
    toxy(45,11);	printf("--------------------------");
    toxy(45,12);	printf("|    您确定要退出吗？    |");
    toxy(45,14);	printf("|  1.确定      2.取消    |");
    toxy(45,15);	printf("--------------------------");
    while(1)
    {
        t=getch();
        if(t=='1')
        {
            system("cls");
            color(14);
            toxy(48,10);	printf("正在安全退出....");
            Sleep(1000);     //暂停1秒
            system("cls");
            color(14);
            toxy(48,10);	printf("已安全退出系统");
            toxy(48,12);	printf("谢谢使用！");
            exit(0);  break; //终止程序
        }
        else if(t=='2')
        {
            menu();
            return;
        }
        else
        {
            Wrong();
        }
    }
}
/*<><><><><><>登录<><><><><><>*/
int sign()
{
    system("cls");
    char m;	//记住输入
    Node*p;	//临时指针变量
    color(14);
    toxy(45,10);	printf("|                                |");
    toxy(45,11);    printf("|  欢迎进入学生奖学金管理系统！  |");
    toxy(45,12);	printf("|                                |");
    toxy(45,13);	printf("|  身份确认                      |");
    toxy(45,14);	printf("|                                |");
    toxy(45,15);	printf("|  1)管理员                      |");
    toxy(45,16);	printf("|                                |");
    toxy(45,17);	printf("|  2)学生                        |");
    toxy(45,18);    printf("|                                |");
    toxy(90,25);	printf("作者：计算机类12班聂芳琪");
    m=getch();
    while(m!='1'&&m!='2')
    {
        toxy(45,19);	printf("|  输入出错啦！请重新输入:       |");
        toxy(45,20);	printf("|                                |");
        m = getch();
    }
    if(m=='1')
    {
        char _password[10];
        do
        {
            system("cls");
            color(11);
            char str[]="000000";
            toxy(45,6);
            printf("-----学生档案管理系统-----");
            toxy(45,8);
            printf("请输入管理者密码：");
            scanf("%s",_password);
            if(strcmp(str,_password)==0)   //判断密码是否输入正确
            {
                system("cls");
                toxy(45,8);
                printf("正在登陆....");
                Sleep(500);
                menu();
                return 1;
            }
            else
            {
                toxy(45,10);
                printf("您的密码错误！请重新输入:");
                Sleep(500);
            }
        }while(1);
    }
    else if(m=='2')
    {
        p=creat();
        menu2(p);
        return 0;
    }
}
/*<><><><><>复制文件<><><><><>*/
void Copy()
{
    system("cls");
    int n=0;	//记住输入个数
    char s[1000];	//循环读取源文件内容到s中，再写到目标文件中
    FILE*fp=fopen("student.txt","r");	//源文件
    FILE*fp1=fopen("des.txt","w");	//目标文件
    if(!fp)
    {
        system("cls");
        toxy(45,8);		printf("文件打开失败哦！");
        toxy(45,9);		system("pause");
        exit(0);
    }
    if(!fp1)
    {
        system("cls");
        toxy(45,8);		printf("文件打开失败哦！");
        toxy(45,9);		system("pause");
        exit(0);
    }
    while((n=fread(s,1,sizeof(s),fp))>0)
    {
        fwrite(s,1,n,fp1);
    }
    toxy(35,12);
    printf("复制文件成功！");
    fclose(fp);
    fclose(fp1);
    system("pause");
    return;
}
int main()
{
    Node*head;/*Link head，定义二维指针*/
    int select,h;//保留用户输入，保留函数返回值
    head=creat();
    h=sign();
    while(h)
    {
        while (1)
        {
            system("cls");
            menu();
            color(11);
            toxy(35,22);
            printf("请输入您的选择：");/*显示提示信息*/
            scanf("%d", &select);
            switch (select)
            {
                case 1:system("cls");Input(head); break;              /*输入*/
                case 2:system("cls");Disp(head); break;               /*查看*/
                case 3:system("cls");Inquire(head); break;            /*查询*/
                case 4:system("cls");Tongji(head); break;             /*统计*/
                case 5:system("cls");Delete(head); break;
                case 6:system("cls");Modify(head);break;
                case 7:system("cls");Sort(head); break;               /*排序*/
                case 8:system("cls");Save(head);break;                /*保存记录*/
                case 9:Copy(); break;
                case 0:quit(head);
                default:Wrong(); system("pause"); break;/*按键有误，请重新输入，输入数值必须为0~9*/
            }
        }
    }
    return 0;
}

