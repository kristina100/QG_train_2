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
    printf("\t\t|   Reference:CSDN and Google.             |\n");
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
    Stack s_digit,s_opt;	//Define number stack and symbol stack.
    while (1)
    {
        if (initLStack(&s_digit) == ERROR || initLStack(&s_opt) == ERROR)
        {
            printf("\t\tInitialization failed!\n");
            return -1;//Initialization failed.
        }

        char opt[128] = {0};//Log user input.
        int i = 0, tmp = 0, digit1, digit2;
        Menu();
        printf("Please enter the expression:\n");
        scanf("%s", opt);//Accept expression.
        if (opt[0] == '@')
        {
            Quit();
            break;
        }
        while (opt[i] != '\0' || isemptyStack(&s_opt) != SUCCESS) /*The expression is not empty or
                                                                    the stack is not empty. Execute.*/
        {
            if (opt[i] >= '0' && opt[i] <= '9')    //The next digit is a number, find the ASCII code.
            {
                tmp = tmp * 10 + (opt[i] - '0');
                i++;
                if (opt[i] < '0' || opt[i] > '9')    /* If the next digit is not a number,
                                                        push tmp into the stack; if the next digit is a number,
                                                        continue to loop */
                {
                    push(&s_digit, tmp);
                    tmp = 0;
                }
            }
            else    //Operator.
            {
                if (isemptyStack(&s_opt) != SUCCESS && Priority(opt[i]) <= Priority((char) getTopLStack(&s_opt)) &&
                    !((getTopLStack(&s_opt) == '(') && (opt[i] != ')')))
                    //Is not an empty stack, and the priority is less than the top of the stack.
                {
                    if (getTopLStack(&s_opt) == '(' && opt[i] == ')')
                    {
                        pop(&s_opt);
                        i++;
                        continue;
                    }
                    if (Priority(opt[i]) <= Priority((char) getTopLStack(&s_opt)) ||
                        ((opt[i] == ')') && getTopLStack(&s_opt) != ')') ||
                        opt[i] == '\0' && isemptyStack(&s_opt) != SUCCESS)
                    {
                        switch (pop(&s_opt)) {
                            case '+':
                                system("cls");
                                digit1 = pop(&s_digit);
                                digit2 = pop(&s_digit);
                                push(&s_digit, digit1 + digit2);
                                system("pause");
                                break;
                            case '-':
                                system("cls");
                                digit1 = pop(&s_digit);
                                digit2 = pop(&s_digit);
                                push(&s_digit, digit2 - digit1);
                                system("pause");
                                break;
                            case '*':
                                system("cls");
                                digit1 = pop(&s_digit);
                                digit2 = pop(&s_digit);
                                push(&s_digit, digit1 * digit2);
                                system("pause");
                                break;
                            case '/':
                                system("cls");
                                digit1 = pop(&s_digit);
                                digit2 = pop(&s_digit);
                                if(digit1 == 0)
                                {
                                    printf("How dare you divide by Zero?\n");
                                    system("pause");
                                    break;
                                }
                                push(&s_digit, digit2 / digit1);
                                system("pause");
                                break;
                        }//end of switch
                    }//end of if
                }//end of if
                else
                    {
                    push(&s_opt, opt[i]);
                    i++;
                }
            }
        }//end of while
        printf("%d\n", getTopLStack(&s_digit));
    }//end of while
    return 0;
}

int initLStack(Stack *s)
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

int getTopLStack(Stack *s)
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

int isemptyStack(Stack *s)
{
    if (NULL == s)
    {
        return ERROR;
    }
    return (s->top == NULL) ? SUCCESS : ERROR;
}

