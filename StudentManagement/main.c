#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void adminmenu();
void stdmenu();
void adminpass();
void adminlogin();
void stdlogin();
void add();
void view();
void stdsearchview();
void search();
void modify();
void deleterec();
void createschedule();
void cgpacal();
void showrot();

void showcgpa();


char stdid[90];
char stdpass[90];
int number;


struct adminlogin
{
    char admid[20];
    char admpass[20];
};

struct student
{
    char email[50];
    char name[50];
    char mobile[50];
    char id[50];
    char password[20];
    char address[90];
};

struct cgpa
{
    double crd,grade,grade1,crd1,res,res1,result,result1,final,crdcount,crdcount1,finalCredit,cgpa;

    char press;
    char studentid[90];
    char course[40];
    char status[90];

};

struct stdroutine
{
    char id[50];
    char pass[50];
};

struct routine
{
    char name[50];
    char suneight[50];
    char moneight[50];
    char tueseight[50];
    char wedeight[50];
    char thurseight[50];

    char sunten[50];
    char monten[50];
    char tuesten[50];
    char wedten[50];
    char thursten[50];

    char suntwet[50];
    char montwet[50];
    char tuestwet[50];
    char wedtwet[50];
    char thurstwet[50];

    char id[50];
};


int main()
{
    int selection;
    system("cls");
    printf ("\t\t\t--------------------------------------------\n");
    printf("\t\t\t---<<STUDENT RECORD MANAGEMENT SYSTEM>>---\n");
    printf ("\t\t\t--------------------------------------------\n");
    printf("\nChoose one: \n\n1.ADMIN LOGIN\n2.STUDENT LOGIN\n");
    printf("\nEnter choice: ");
    scanf("%d",&selection);
    if(selection==1)
    {
        adminlogin();
    }
    else if(selection==2)
    {
        stdlogin();
    }

    else
    {
        printf("\nEnter correctly.\n");
    }
    return 0;
}

void adminpass()
{
    FILE *ap;
    struct adminlogin admn;
    ap=fopen("admin.txt","ab+");
    printf("\nEnter ID: ");
    fflush(stdin);
    gets(admn.admid);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(admn.admpass);
    fwrite(&admn,sizeof(admn),1,ap);
    fclose(ap);
    getch();
    main();
}

void adminlogin()
{
    FILE *ap;
    struct adminlogin admn;
    char aid[50];
    char apass[50];
    printf("\nEnter ID: ");
    fflush(stdin);
    gets(aid);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(apass);
    ap=fopen("admin.txt","rb+");
    while(fread(&admn,sizeof(admn),1,ap))
    {
        if(strcmp(aid,admn.admid)==0 && strcmp(apass,admn.admpass)==0)
        {
            adminmenu();
        }
        else{
            printf("\nID or password wrong.");
        }
    }
    fclose(ap);
    getch();
    main();
}

void stdlogin()
{
    FILE *fp;
    struct student std;
    printf("\nEnter ID : ");
    fflush(stdin);
    gets(stdid);
    printf("\nEnter password : ");
    fflush(stdin);
    gets(stdpass);
    fp=fopen("record.txt","rb+");
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
           if(strcmp(stdid,std.id)==0 && strcmp(stdpass,std.password)==0)
        {
            stdmenu();
        }
        else
        {
            printf("\nID or password incorrect.");

        }
    }
    fclose(fp);
    getch();
    main();
}
void adminmenu()
{
    int choice;
    system("cls");

    printf("<--:MENU:-->");

    printf("Enter appropriate number to perform following task.");

    printf("\n1 : Add Record.");

    printf("\n2 : View Record.");

    printf("\n3 : Search Record.");

    printf("\n4 : Modify Record.");

    printf("\n5 : Delete Record.");

    printf("\n6 : Create Routine.");

    printf("\n7 : Calculate CGPA.");

    printf("\n8 : Logout.");

    printf("\nEnter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        createschedule();
        break;

    case 7:
        cgpacal();
        break;

    case 8:
        main();
        break;

    default:

        printf("Invalid Choice.");
    }
}

void stdmenu()
{
    int choice;
    system("cls");

    printf("<--:MENU:-->");

    printf("Enter appropriate number to perform following task.");

    printf("\n1 : View personal information.");

    printf("\n2 : View routine.");

    printf("\n3 : Show CGPA.");

    printf("\n4 : Logout");

    printf("\nEnter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        stdsearchview();
        break;

    case 2:
        showrot();
        break;

    case 3:
        showcgpa();
        break;

    case 4:
        main();
        break;

    default:

        printf("Invalid Choice.");
    }
}

void add()
{
    FILE *fp;    //0x67686898
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");

    fflush(stdin);
    while(another == 'y')
    {

        printf("<--:ADD RECORD:-->");
          printf("\n\nEnter details of student.");

        printf("\nEnter Email : ");
        fflush(stdin);
        gets(std.email);

        printf("\nEnter Name : ");
        fflush(stdin);
        gets(std.name);

        printf("\nEnter Mobile Number : ");
        fflush(stdin);
        gets(std.mobile);

        printf("\nEnter ID : ");
        fflush(stdin);
        gets(std.id);


        printf("\nEnter password : ");
        fflush(stdin);
        gets(std.password);
        printf("Enter address : ");
        fflush(stdin);
        gets(std.address);

        fwrite(&std,sizeof(std),1,fp);

        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);

    fclose(fp);
    }
    printf("\nPress 1 to go back to main menu .\nPress 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nWrong entered.\n");
    }
    getch();
}

void view()
{
    FILE *fp;
    int i=1;
    int j;
    struct student std;
    system("cls");

    printf("<--:VIEW RECORD:-->");

    printf("\n\n\nS.No   Email of Student       \t\tName           \tMobile No   \t\tID  \t\tPassword     \t\t Address");

    printf("\n---------------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file.");
        exit(1);
    }

    while  (fread(&std,sizeof(std),1,fp) == 1){

        printf("\n%-3d%-35s%-18s%-20s%-23s%-20s%-20s",i,std.email,std.name,std.mobile,std.id,std.password,std.address);
        i++;

    }
    fclose(fp);


    printf("\n\n\nPress any key to continue.");
    getch();
     printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

void stdsearchview()
{
    FILE *fp;
    struct student std;
    struct stdroutine rot;
    char stname[20];
    char sid[90];
    system("cls");

    printf("<--:SEARCH RECORD:-->");


    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }

            while(fread(&std,sizeof(std),1,fp ) == 1){

            if(strcmp(stdid,std.id)==0)
            {
                    printf("\n\nEmail: %s",std.email);

                    printf("\nName : %s",std.name);

                    printf("\nMobile Number : %s",std.mobile);

                    printf("\nID : %s",std.id);

                    printf("\nPassword : %s",std.password);

                    printf("\nAddress : %s",std.address);
            }

        }

    fclose(fp);
    getch();
    printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        stdmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    char sid[90];
    char spass[50];
    system("cls");

    printf("<--:SEARCH RECORD:-->");

    printf("Enter ID of student : ");
    fflush(stdin);
    gets(sid);
    printf("\t\tEnter Pass of student : ");
    fflush(stdin);
    gets(spass);

    fp = fopen("record.txt","rb+");
    fflush(stdin);
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
        {
        if(strcmp(sid,std.id) == 0 && strcmp (spass,std.password)== 0)
           {
            printf("\n\nEmail: %s",std.email);

            printf("\nName : %s",std.name);

            printf("\nMobile Number : %s",std.mobile);

            printf("\nID : %s",std.id);

            //printf("\nPassword : %s",std.password);

            printf("\nAddress : %s",std.address);
            fflush(stdin);
        }

    }
    fclose(fp);

    printf("\nPress any key to continue.");
    getch();
     printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

void modify()
{
    char sid[90];
    FILE *fp;
    struct student std;
    system("cls");

    printf("<--:MODIFY RECORD:-->");

    printf("Enter ID of student to modify: ");
    fflush(stdin);
    gets(sid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }

    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(sid,std.id) == 0){
            printf("Enter email: ");
            gets(std.email);
            printf("Enter name: ");
            fflush(stdin);
            gets(std.name);

            printf("Enter mobile number : ");
            fflush(stdin);
            gets(std.mobile);

            printf("Enter id : ");
            fflush(stdin);
            gets(std.id);

            printf("Enter Password : ");
            fflush(stdin);
            gets(std.password);

            printf("Enter Address : ");
            fflush(stdin);
            gets(std.address);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);

    printf("Press any key to continue.");
    getch();
     printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}
void deleterec()
{
    char sid[90];
    FILE *fp,*ft;
    struct student std;

    printf("<--:DELETE RECORD:-->");

    printf("Enter ID of student to delete record : ");
    fflush(stdin);
    gets(sid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){

        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(sid,std.id)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");

    printf("Press any key to continue.");
    getch();
     printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}


void showrot()
{

    FILE *ft;
    struct routine rout;
    int i=1,j;
    int sel;
            system("cls");
            printf(" \n -------------------------Login Screen------------------------\n\n\n");
                ft=fopen("routine.txt","rb+");
                while(fread(&rout,sizeof(rout),1,ft) == 1)
                {
                    if(strcmp(stdid,rout.id)==0)
                    {
                        ft=fopen("routine.txt","rb+");
                        if(ft == NULL)
                        {
                        printf("Error opening file.");
                        exit(1);
                        }
                            printf("                             Sun                               Mon                             Tues                                   Wed                                   Thurs\n\n");
                            printf("             -------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                            printf("             8:00-9:30      %s                                 %s                            %s                                   %s                                   %s\n\n",rout.suneight,rout.moneight,rout.tueseight,rout.wedeight,rout.thurseight);
                            printf("             --------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                            printf("             10:00-11:30    %s                                 %s                            %s                                   %s                                   %s\n\n",rout.sunten,rout.monten,rout.tuesten,rout.wedten,rout.thursten);
                            printf("             ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                            printf("             12:30-2:00     %s                                 %s                            %s                                   %s                                   %s\n\n",rout.suntwet,rout.montwet,rout.tuestwet,rout.wedtwet,rout.thurstwet);
                            printf("             --------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

                    }
            }

    fclose(ft);
    getch();
    printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        stdmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

void createschedule()
{
    FILE *ft;
    struct routine rout;
    char repeat='y';

    ft=fopen("routine.txt","ab+");
    fflush(stdin);
    while(repeat=='y')
    {
            printf("\nEnter student ID : ");
            fflush(stdin);
            gets(rout.id);
            printf("\nEnter course for Sunday at 8:00 am : ");
            fflush(stdin);
            gets(rout.suneight);
            printf("\nEnter course for Sunday at 10:00 am : ");
            fflush(stdin);
            gets(rout.sunten);
            printf("\nEnter course for Sunday at 12:30 am : ");
            fflush(stdin);
            gets(rout.suntwet);

            printf("\nEnter course for Monday at 8:00 am : ");
            fflush(stdin);
            gets(rout.moneight);
            printf("\nEnter course for Monday at 10:00 am : ");
            fflush(stdin);
            gets(rout.monten);
            printf("\nEnter course for Monday at 12:30 am : ");
            fflush(stdin);
            gets(rout.montwet);

            printf("\nEnter course for Tuesday at 8:00 am : ");
            fflush(stdin);
            gets(rout.tueseight);
            printf("\nEnter course for Tuesday at 10:00 am : ");
            fflush(stdin);
            gets(rout.tuesten);
            printf("\nEnter course for Tuesday at 12:30 am : ");
            fflush(stdin);
            gets(rout.tuestwet);

            printf("\nEnter course for Wednesday at 8:00 am : ");
            fflush(stdin);
            gets(rout.wedeight);
            printf("\nEnter course for Wednesday at 10:00 am : ");
            fflush(stdin);
            gets(rout.wedten);
            printf("\nEnter course for Wednesday at 12:30 am : ");
            fflush(stdin);
            gets(rout.wedtwet);

            printf("\nEnter course for Thursday at 8:00 am : ");
            fflush(stdin);
            gets(rout.thurseight);
            printf("\nEnter course for Thursday at 10:00 am : ");
            fflush(stdin);
            gets(rout.thursten);
            printf("\nEnter course for Thursday at 12:30 am : ");
            fflush(stdin);
            gets(rout.thurstwet);
            fseek(ft,sizeof(rout),SEEK_END);
            fwrite(&rout,sizeof(rout),1,ft);
            printf("\nWant to enter another record ? Press y or n \n");
            repeat=getch();
            system("cls");
            fflush(stdin);
            }

    fclose(ft);
    printf("\nPress any key to continue");
    getch();
     printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

void cgpacal()
{
    FILE *cgpa;
    char session ='y';
    int i,j;
    struct cgpa cg;
    cgpa = fopen("cg.txt","ab+");
    fflush(stdin);
    while(session=='y')
    {
    for(i=1;i<=4;i++)
    {

        printf("\n\nEnter course name: ");
        fflush(stdin);
        gets(cg.course);
        printf("\n\nEnter grade: ");
        scanf("%lf",&cg.grade);
        printf("\nEnter credit: ");
        scanf("%lf",&cg.crd);



        cg.res = cg.grade*cg.crd;

         cg.result=cg.result+cg.res;
         cg.crdcount=cg.crdcount+cg.crd;
         printf("\nGrade : %lf",cg.result);
         printf("\n\nTotal credits : %lf",cg.crdcount);
    }
    printf("\nWant to enter more? Y or N\n\n");
    scanf("%s",&cg.press);
    if(cg.press=='Y')
    {
        for(j=1;j<=2;j++)
        {
            printf("\n\nEnter course name: ");
            fflush(stdin);
            gets(cg.course);
            printf("Enter grade: ");
            scanf("%lf",&cg.grade1);
            printf("\nEnter credit: ");
            scanf("%lf",&cg.crd1);
            cg.crd=cg.crd1;
            cg.crdcount1 = cg.crdcount1 + cg.crd;
            cg.res1 = cg.grade*cg.crd;
            cg.result1 = cg.result1+cg.res1;
        }
        cg.final = cg.result1+cg.result;
        cg.finalCredit=cg.crdcount1+cg.crdcount;
        printf("Total credits : %lf\n",cg.finalCredit);
        printf("%lf\n\n",cg.final);
        printf("Enter student ID: ");
        fflush(stdin);
        gets(cg.studentid);
        cg.cgpa = cg.final/cg.finalCredit;
        printf("\n\nCGPA is %lf\n\n",cg.cgpa);
        fwrite(&cg,sizeof(cg),1,cgpa);
    }
    else if(cg.press='N')
    {
        cg.cgpa = cg.result/cg.crdcount;
        cg.finalCredit=cg.crdcount;
        printf("\nCGPA is %lf\n",cg.cgpa);
        printf("\nEnter student ID: ");
        fflush(stdin);
        gets(cg.studentid);

        fwrite(&cg,sizeof(cg),1,cgpa);
        }
    else
    {
        printf("\n\nWrong key entered.\n");
    }
    printf("\nWant to enter more ? y or n ?");
    session=getch();
}
fclose(cgpa);
printf("\nPress any key");
getch();
printf("\nPress 1 to go to main menu.\n Press 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        adminmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }

}

void showcgpa()
{
    FILE *cgpa;
    int i=1,j;
    char cgp[50];
    struct cgpa cg;
    system("cls");
    printf("                   View CGPA\n\n\n");
    cgpa=fopen("cg.txt","rb+");
    if(cgpa==NULL)
    {
        printf("Error opening");
        exit(1);
    }
    while(fread(&cg,sizeof(cg),1,cgpa)==1)
    {
        if(strcmp(stdid,cg.studentid)==0)
        {
        printf("\n     ID                CGPA                   Credits   ");
        printf("\n   --------------------------------------------------------\n");


            printf("\n%-25s%-25lf%-15lf",cg.studentid,cg.cgpa,cg.finalCredit);
        }
    }
    fclose(cgpa);
    printf("\n\n\n\npress any key to continue");
    getch();
     printf("\nPress 1 to go to main menu.\nPress 0 to logout\n");
    scanf("%d",&number);
    if(number==1)
    {
        stdmenu();
    }
    else if(number==0)
    {
        main();
    }
    else
    {
        printf("\nEnter correctly\n");
    }
}

