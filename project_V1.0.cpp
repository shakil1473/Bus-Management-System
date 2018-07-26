#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void admin(void);
void del_bus();
void add_bus( void );
int main()
{
//    char ch;
//    printf("\t\t\t\t\t\tWelcome To ASTRO Travels");
//    printf("\n\nPassenger\n\n");
//    printf("please press P to enter: ");
//    ch=getche();
//    if(ch=='p'||ch=='P')passenger();
//
//    if(ch=='a'||ch=='A')
    admin();

    return 0;

}
void admin (void)
{

    ///ACTIVATE Pin MODE
//    int p;
//    printf("\nPlease Enter The Pin: ");
//    scanf("%d",&p);
//    if(p==1473|| p==1445)
//
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
x:
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
y:
    printf("\nDo you wat to add more bus? ( y / n) : ");
    c=getche();
    if(c=='Y' || c=='y')goto x;
    else if(c=='n'||c=='N');
    else goto y;
    admin();
}

void del_bus()
{
    FILE *fp;
    FILE *fp2;
    fp = fopen("busadded.txt", "r");
    fp2 = fopen("File_copy.txt", "w");
    int number,num,i=1;
    char c[40],d[40],e[12];
    printf("Enter the BUS NO. to eliminate: ");
    scanf("%d", &num);
    while (fscanf( fp, "%d %s %s %s\n",&number,c,d,e)>0)
    {
        printf("%d %s %s %s\n",number,c,d,e);
        if(number==num)continue;
        fprintf(fp2, "%d %s %s %s\n",number,c,d,e);
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
        //adminpanel();
}
void passenger()
{
    system("cls");
    printf("\t\t\t\t\t\tWelcome To ASTRO Travels\n");
    printf("\t\t\t\t\t\tPassenger Dashboard\n");
    printf("\n\n\
           1.Ticket Booking\n\n\
           2.Manage Booking\n\n\
           3.Bus Schedule\n\n\
           4.Bus Status\n\n\
           5.Comments\n");
}
