#include "library.h"
void Menu()
{
    printf("\t\t|------------------------------------------|\n");
    printf("\t\t|            ___________________           |\n");
    printf("\t\t|           | Simple calculator |          |\n");
    printf("\t\t|            -------------------           |\n");
    printf("\t\t|               Welcome to use             |\n");
    printf("\t\t|                                          |\n");
    printf("\t\t|              1    2    3   +             |\n");
    printf("\t\t|              4    5    6   -             |\n");
    printf("\t\t|              7    8    9   *             |\n");
    printf("\t\t|              0    (    )   /             |\n");
    printf("\t\t|   tips:Only supports integer operations. |\n");
    printf("\t\t|------------------------------------------|\n");
    printf("\t\t \n");
}

int Priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}

int Menu0()
{
    Stack s_num,s_opt;	//定义数字栈、符号栈
    while (1)
    {
        if (InitStack(&s_num) == ERROR || InitStack(&s_opt) == ERROR)
        {
            printf("\t\tInitialization failed!\n");
            return -1;
        }

        char opt[128] = {0};
        int i = 0, tmp = 0, num1, num2;

        printf("Please enter the expression:\n");
        scanf("%s", opt);//接受表达式
        if (opt[0] == '@')
        {
            Quit();
            break;
        }
        while (opt[i] != '\0' || EmptyStack(&s_opt) != SUCCESS) //表达式不为空或栈不为空 执行
        {
            if (opt[i] >= '0' && opt[i] <= '9')    //下一位是数字，求出asc码
            {
                tmp = tmp * 10 + (opt[i] - '0');
                i++;
                if (opt[i] < '0' || opt[i] > '9')    //下一位不是数字，将tmp入栈；若下位是数字继续循环
                {
                    push(&s_num, tmp);
                    tmp = 0;
                }
            } else    //操作符
            {
                if (EmptyStack(&s_opt) != SUCCESS && Priority(opt[i]) <= Priority((char) GetTop(&s_opt)) &&
                    !((GetTop(&s_opt) == '(') && (opt[i] != ')')))
                    //不是空栈，且优先级小于栈顶，
                {
                    if (GetTop(&s_opt) == '(' && opt[i] == ')') {
                        pop(&s_opt);
                        i++;
                        continue;
                    }
                    //此处可直接用else判断
                    if (Priority(opt[i]) <= Priority((char) GetTop(&s_opt)) ||
                        ((opt[i] == ')') && GetTop(&s_opt) != ')') ||
                        opt[i] == '\0' && EmptyStack(&s_opt) != SUCCESS) {
                        switch (pop(&s_opt)) {
                            case '+':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num, num1 + num2);
                                break;
                            case '-':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num, num2 - num1);
                                break;
                            case '*':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num, num1 * num2);
                                break;
                            case '/':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num, num2 / num1);
                                break;
                        }
                    }
                } else {
                    push(&s_opt, opt[i]);
                    i++;
                }
            }
        }
        printf("%d\n", GetTop(&s_num));
    }
}
int InitStack(Stack *s)
{
    if (NULL == s)
    {
        return ERROR;
    }

    s->top = NULL;
    s->length = 0;	//Indicates an empty stack.

    return SUCCESS;
}

int push(Stack *s, int num)
{
    if (NULL == s)
    {
        return ERROR;
    }

    StackNode *n = (StackNode *)malloc(sizeof(StackNode) * 1);
    if (NULL == n)
    {
        return ERROR;
    }

    n->data = num;
    n->next = s->top;
    s->top = n;	//Update the top pointer.
    s->length++;

    return SUCCESS;
}

int GetTop(Stack *s)
{
    if (NULL == s)
    {
        return ERROR;
    }

    if (s->top == NULL)
    {
        return ERROR;
    }

    return s->top->data;
}

int pop(Stack *s)
{
    if (NULL == s)
    {
        return ERROR;
    }

    if (s->top == NULL)	//Empty stack cannot be popped
    {
        return ERROR;
    }

    StackNode *n = s->top;
    int data = n->data;
    s->top = n->next;
    free(n);
    s->length--;

    return data;
}

void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t\t------------------------------\n");
    printf("\t\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t\t-----------------------------\n");
    printf("\t\t\t\tPlease enter your choice:\n");
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
            printf("\t\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\t\tSafely exited the system\n");
            printf("\t\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program
        }
        else if(temp==2)
        {
            Menu();
            return;
        }
    }
}

int EmptyStack(Stack *s)
{
    if (NULL == s)
    {
        return ERROR;
    }
    return (s->top == NULL) ? SUCCESS : ERROR;
}

