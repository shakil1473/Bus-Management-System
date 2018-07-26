#include <time.h>       /* time_t, time, ctime */
#include <iostream>
#include <numeric>
#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
using namespace std;

typedef struct newbus nbus;
COORD coord= {0,0}; // this is global variable
//center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct newbus
{
    int bus_num;
    char sup_name_f[20]; //supervisor first name
    char sup_name_l[20]; //supervisor last name
    char sup_cellno[12];
};

void add_bus( void );
void del_bus();
void adminpanel (void);
bool password_check(void);
bool Y_or_N(void );
int main()
{
    adminpanel();
    return 0;
}
void adminpanel (void)
{
    if(password_check());

    system("cls");
    int choice;
    printf("1.Add bus \n2. delete\n");
x:
    printf("Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        add_bus();
        break;
    case 2:
        del_bus();
        break;
    default:
        goto x;
    }
}

void add_bus( void )
{
    FILE *file;
    system("cls");
    system("cls");
    file=fopen("busadded.txt","a");

    int a;
    char fn[40];
    char ln[40];
    char phno[12];
    printf("Bus Number: ");
    scanf("%d", &a);

    printf("Supervisor First name: " );
    scanf("%s", &fn);

    printf("Supervisor Last name: " );
    scanf("%s", &ln);

    printf("Supervisor phone no.: ");
    scanf("%s", &phno);

    fprintf(file,"%d %s %s %s\n",a,fn,ln,phno);
    fclose(file);
    char c;
    fflush(stdin);
    printf("\nDo you wat to add more bus? ( Y / N) : ");
    if(Y_or_N())add_bus();
    else adminpanel();
}

void del_bus()
{
    FILE *fp;
    FILE *fp2;
    fp = fopen("busadded.txt", "r");
    fp2 = fopen("File_copy.txt", "w");
    int number,num,flag=0;
    char c[40],d[40],e[12];
    printf("Enter the BUS NO. to eliminate: ");
    scanf("%d", &num);
    while (fscanf( fp, "%d %s %s %s\n",&number,c,d,e)>0)
    {
        if(number==num)
        {
            flag=1;
            continue;
        }
        fprintf(fp2, "%d %s %s %s\n",number,c,d,e);
    }
    if(!flag)
    {
        printf("NOT found in the list");
    }
    fclose(fp);
    fclose(fp2);
    remove("busadded.txt");
    if(rename( "File_copy.txt", "busadded.txt" ))
    {
        printf("Not deleted");
    }
    else
        printf("deleted successfully ");
}
bool password_check(void)
{
    char a[5];
    int n=0;
x:
    gotoxy(10,10);
    printf("Enter your PIN:");
    int i;
    for(i=0; i<4 ; i++)
    {
        a[i]=getche();
        //if(a[i]=='\n')break;
        printf("\b*");
    }
    a[i]='\0';
    if(strcmp(a,"1445")==0)return true;
    else
    {
        n++;
        system("cls");
        gotoxy(10,8);
        printf("\nYou have entered WRONG PIN, Please try again !\n");
        if(n<3)goto  x;
    }
    gotoxy(10,12);
    printf("You Have tried 3 times, better Luck next time");
    for(int j=0; j<100000000; j++);
    for(int j=0; j<100000000; j++);
    for(int j=0; j<100000000; j++);
    exit(1);
}
bool Y_or_N(void )
{
y:
    char c=getche();
    if(c=='Y' || c=='y')return true;
    else if(c=='n'||c=='N')return false;
    else
    {
        system("cls");
        printf("\n please press Y / N :  ");
        goto y;
    }
}
