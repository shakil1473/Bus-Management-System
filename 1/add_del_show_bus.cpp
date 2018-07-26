#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define NL 20 //name length
#define ML 12 //mobile number length
#define R 20 //random length

int status[500];
// this is global variable
COORD coord= {0,0};  //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


typedef struct businfo bus;

struct destination
{
    char from[R];
    char to[R];
};

struct businfo
{
    int busno;
    char fname[NL]; //supervisors fast name;
    char lname[NL]; //supervisors last name;
    char mob[ML];
    struct destination des;
    struct businfo *next;
};

const char route[][30]= {"Dhaka to Mymensingh", "Mymensingh to Dhaka", "Dhaka to Comilla", "Comilla to Dhaka" };

void admin(void);
void del_bus();
void add_bus( void );
void display();


int main()
{
    //display();
    admin();
    //add_bus();
    return 0;

}

void display()
{
    FILE *fp;

    fp = fopen("bus.txt","r");
    int bn,r; //bn=bus no., r is a random value
    char c[40],d[40],e[12];
    while (fscanf(fp, "%d %s %s %s %d\n",&bn,c,d,e,&r)>0)
        printf("%d %s %s %s %d\n",bn,c,d,e,r);
    fclose(fp);
    printf("Press any key to continue to Main Menu...");
    getche();
    fflush(stdin);
    admin();
}





void admin (void)
{
    system("cls");
    int choice;

    printf("1.Add bus \n2. delete\n3. ");
    printf("Choice(): ");
x:
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
    //typedef struct businfo bus;
    bus b;
    FILE *file;
    FILE *s;
    char status[1000];
    file=fopen("bus.txt","a");

//    s=fopen("bus_status.txt","r");
//    fscanf(s,"%s",status);
//    fclose(s);
//
//    s=fopen("bus_status.txt","w");

    int n;                     //route code
x:
    system("cls");
    gotoxy(30,5);
    printf("BUS INFO");
    gotoxy(25,8);
    printf("Bus Number: ");
    fflush(stdin);
    scanf("%d", &b.busno);
    //puts(status);
//    if(status[b.busno]=='1'){
//        printf("This bus number is already in use, try another !");
//        Sleep(3000);
//        goto x;
//    }
    else status[b.busno]='1';

    fflush(stdin);
    gotoxy(25,10);
    printf("Supervisor First name: " );
    scanf("%s", &b.fname);

    gotoxy(25,12);
    printf("Supervisor Last name: " );
    scanf("%s", &b.lname);

    gotoxy(25,14);
    printf("Supervisor phone no.: ");
    scanf("%s", &b.mob);

    gotoxy(35,16);
    printf("---ROUTE---");
    for(int i=0; i<4; i++)
    {
        gotoxy(35,(18+i));
        printf("%d. ",i+1);
        puts(route[i]);
    }
    gotoxy(35,24);
    printf("Enter Your Choice (1/2/3/4):");
    scanf("%d", &n);


    ///////////////////////////////////////////////////// from shakil

    fprintf(file,"%d %s %s %s %d\n",b.busno, b.fname , b.lname, b.mob, n);
//    fprintf(s,"%s", status);
//    fclose(file);
    fclose(s);
    char c;
    fflush(stdin);
y:
    gotoxy(25,25);
    printf("Do you wat to add more bus? ( y / n) : ");
    c=getche();
    if(c=='Y' || c=='y')goto x;
    else if(c=='n'||c=='N')
        admin();
    else
    {
        gotoxy(25,26);
        printf("(press  'Y' or 'N' please)");
        goto y;
    }
}

void del_bus()
{
    FILE *fp;
    FILE *fp2;

    fp = fopen("bus.txt","r");
    fp2 = fopen("File_copy.txt","w+");

    int bn,i=1,key,r; //bn=bus no., r is a random value
    char c[40],d[40],e[12];
    bool flag=false;
    printf("Enter the BUS NO. to eliminate: ");
    fflush(stdin);
    scanf("%d", &key);

    while (fscanf(fp, "%d %s %s %s %d\n",&bn,c,d,e,&r)>0)
    {
        if(bn!=key)
            fprintf(fp2, "%d %s %s %s %d\n",bn,c,d,e,r);
        else if(bn==key)flag=true;
    }
    fclose(fp);
    fclose(fp2);
    remove("bus.txt");
    if(rename( "File_copy.txt", "bus.txt" ))
    {
        printf("Not deleted, problem with file");
    }
    else
    {
        if(flag)
            printf("deleted successfully ");
        else printf("Bus number does not match :( ");
    }

    printf("\nMain Menu Loading ");
    Sleep(1000);printf(".");
    Sleep(1000);printf(".");
    Sleep(1000);printf(".");
    admin();
}















