#include "string.h"


void Menu();
int InputInteger();
void safe_flush(FILE *fp);
void Quit();
void Menu0();

void safe_flush(FILE *fp)
{
    int ch;
    while( (ch = fgetc(fp)) != EOF && ch != '\n' );
}

void Quit()
{
    system("cls");
    int temp;
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t|      1.YES      2.NO       |\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\tPlease enter your choice:\n");
    while(1)
    {
        temp = InputInteger();
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
        else
            printf("The input is illegal, please re-enter.Thanks.--:");
    }
}
void Menu0()
{   printf("\n\n\n\n\t\t\t*-----------------------------------------------------------*\n");
    printf("\t\t\t|               Welcome to Tomato's big work ~              |\n");
    printf("\t\t\t|                Some operations on String ~                |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    1. Make String                7. Concat String         |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    2. Visualization String       8. Pattern Matching      |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    3. Length of String           9. Delete String         |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    4. Copy String                10. Insert String        |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    5. Clear String               11. Quit System          |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t|    6. Compare String             Thank you ~  ^_^         |\n");
    printf("\t\t\t|                                                           |\n");
    printf("\t\t\t*-----------------------------------------------------------*\n");
    printf("\n\t\t\nPlease enter your choice (1 to 11) :\n");
}

int InputInteger()
{
    /* store converted numbers */
    int integer;
    /* flag status */
    int status;
    /* receive string */
    char str[100];

    do {
        scanf("%s", str);
        status = OK;
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            /* check for illegal characters */
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = ERROR;
            }
        }
        if (status == ERROR) {
            printf("Your input is illegal, please re-enter :");
            continue;
        } else {
            /* Convert string to number */
            for (i = 0, integer = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        integer *= 10;
                        integer += (str[i] - 48);
                    }
                } else {
                    integer *= 10;
                    integer += (str[i] - 48);
                }
            }
            if (str[0] == '-') integer = -integer;

            /* check if the number entered is out of bounds */
            if (i >= 10) {
                printf("Overflow, please re-enter:");
                status = ERROR;
            }
        }
    } while (status == ERROR);

    return integer;
}

void Menu()
{
    int i,j,pos;
    Status k;
    char s;
    String s1,s2,s3,s4,s5,s6,t;
    char SSS[MAXSIZE+1],FFF[MAXSIZE+1];
    int exist_flag = 0;  /* 标记树是否存在 */
    while(1)
    {
        Menu0();
        switch (InputInteger()) {
            case 1:
                system("cls");
                printf("\nMake String.  ^_^\n");
                printf("Please input the string s1: \n");
                scanf("%s",SSS);
                safe_flush(stdin);
                k=assign_string(s1,SSS);
                if(!k)
                {
                    printf("The String's length is over MAXSIZE(=%d)\n",MAXSIZE);
                    exit(0);
                }
                exist_flag = 1;
                system("pause");
                break;
            case 2:
                system("cls");
                if(exist_flag)
                {
                    printf("\nVisualization String.^_^\n");
                    print_string(s1);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 3:
                system("cls");
                if(exist_flag)
                {
                    printf("\nLength of String.^_^\n");
                    printf("The length of string s1 is %d Is it empty? %d(1:YES 0:NO)\n",length_string(s1),string_empty(s1));
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 4:
                system("cls");
                if(exist_flag)
                {
                    printf("\nCopy String.^_^\n");
                    printf("s1 : \n");
                    print_string(s1);
                    string_copy(s2,s1);
                    printf("Copy s1 to s2, s2 : \n");
                    print_string(s2);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 5:
                system("cls");
                if(exist_flag)
                {
                    printf("\nClear String.^_^\n");
                    printf("Before clearing, String s1 is : \n");
                    print_string(s1);
                    clear_string(s1);
                    printf("\n After clearing, String s1 is : \n");
                    print_string(s1);
                    exist_flag = 0;
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 6:
                system("cls");
                if(exist_flag)
                {
                    printf("\nCompare String.^_^\n");
                    printf("Please input the string s3: ");
                    scanf("%s",FFF);
                    safe_flush(stdin);
                    k=assign_string(s3,FFF);
                    if(!k)
                    {
                        printf("The string is over MAXSIZE(%d)\n",MAXSIZE);
                        exit(0);
                    }
                    i=compare_string(s1,s3);
                    if(i<0)
                        s='<';
                    else if(i==0)
                        s='=';
                    else
                        s='>';
                    printf("s1 %c s3\n",s);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 7:
                system("cls");
                if(exist_flag)
                {
                    printf("\nConcat String.^_^\n");
                    printf("String s1 is : \n");
                    print_string(s1);
                    printf("Please input the string s4: ");
                    scanf("%s",FFF);
                    safe_flush(stdin);
                    k=assign_string(s4,FFF);
                    if(!k)
                    {
                        printf("The string is over MAXSIZE(%d)\n",MAXSIZE);
                        exit(0);
                    }
                    printf("String s4 is : \n");
                    k=string_concat(t,s1,s4);
                    printf("s1 concat s4 to t, t is : ");
                    print_string(t);
                    if(k==FALSE)
                        printf("t is truncated.\n");
                    print_string(t);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 8:
                system("cls");
                if(exist_flag)
                {
                    printf("\nPattern Matching.^_^\n");
                    printf("Please input the string s5: ");
                    scanf("%s",FFF);
                    safe_flush(stdin);
                    k=assign_string(s5,FFF);
                    if(!k)
                    {
                        printf("The string is over MAXSIZE(%d)\n",MAXSIZE);
                        exit(0);
                    }
                    printf("String s5 is : \n");
                    print_string(s5);
//                    k=string_concat(t,s1,s5);
//                    printf("s1 concat s5 to t, t is : ");
//                    print_string(t);
//                    if(k==FALSE)
//                        printf("t is truncated.\n");
//                    printf("input the position you want to match:\n");
//                    scanf("%d",&pos);
//                    safe_flush(stdin);
                    i=Index(s1,s5,1);
                    printf("First match with t from the %dth letter of s1 \n",i);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 9:
                system("cls");
                if(exist_flag)
                {
                    printf("\nDelete String.^_^\n");
                    printf("Delete 'len' characters from the 'pos' character of string s1. Please enter pos,len: ");
                    scanf("%d",&i);
                    safe_flush(stdin);
                    scanf("%d",&j);
                    safe_flush(stdin);
                    printf("pos: %d, len: %d \n",i,j);
                    string_delete(s1,i,j);
                    printf("The deleted string s1 is : ");
                    print_string(s1);
                }
                else printf("No  string exists, please make string first!\n");
                system("pause");
                break;
            case 10:
                system("cls");
                if(exist_flag)
                {
                    printf("\nInsert String.^_^\n");
                    printf("Please input the string s6: ");
                    scanf("%s",FFF);
                    safe_flush(stdin);
                    k=assign_string(s6,FFF);
                    if(!k)
                    {
                        printf("The string is over MAXSIZE(%d)\n",MAXSIZE);
                        exit(0);
                    }
                    printf("String s6 is : \n");
                    i= length_string(s1)/2;
                   insert_string(s1,i,s6);
                    printf("After inserting the string t before the %d character of the string s1, the string s1 is:\n",i);
                    print_string(s1);
                }
                else printf("No  string exists, please make string first!\n");

                system("pause");
                break;
            case 11:
                system("cls");
                Quit();
                exit(0);
            default:
                printf("Sorry, please enter a right integer:^_^ \n");
                break;
        }
    }
}
int main()
{
    Menu();
    return 0;
}

