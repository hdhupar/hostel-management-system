#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j;
int main_exit;
void menu();
void closer();
struct date{
    int month,day,year;
};
struct {

    char name[60];
    int age;
    char city[60];
    char mail_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    char hostel_name[6];
    char roll_no[10];
    struct date dob;
    }add,upd,check,rem,sort;

void new_entry()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    roll_no:
    
    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%s",check.roll_no);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
    {
        if (check.roll_no==add.roll_no)
            {printf("Students roll no. already in use!");
             goto roll_no;
        }
    }

    strcpy(add.roll_no,check.roll_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%d",&add.father_phone);
    printf("\n Enter your room no.:");
    scanf("%s",add.room_no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",add.hostel_name);
        fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);

    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    
    printf("\nROLL NO.\tNAME\t\t\tcity\t\t\tPHONE\n");

    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d",add.roll_no,add.name,add.city,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",upd.roll_no);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(add.roll_no,upd.roll_no)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);
            
            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, upd.room_no, add.hostel_name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else
            closer();
        }
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll np. of student whose data you want to delete:");
    scanf("%s",rem.roll_no);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
   {
        if(add.roll_no!=rem.roll_no)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else
            closer();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the roll number:");
        scanf("%s",check.roll_no);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.roll_no,check.roll_no)==0)
            {   
                test=1;

                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {   
                test=1;
                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {   
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    see();
                else
                    {
                        
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
          menu();
        }

        else
           {
             closer();
            }

}

void sorter(void)
{
    int choice;
    printf("Enter year choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. BH-3 \n\t\t4. GH-1 \n\n");
    scanf("%d",&choice);
    
    FILE *fp, *sort1, *sort2, *sort3, *sort4;
    fp=fopen("record.dat","r");
    int test=0;
    
    while(fscanf(fp,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",sort.roll_no, sort.name, &sort.dob.month, &sort.dob.day, &sort.dob.year, &sort.age, sort.city, &sort.phone, sort.mail_id, sort.father_name, &sort.father_phone, sort.room_no, sort.hostel_name)!=EOF)
    {       
        if(choice==1 && strcmp(sort.hostel_name,"BH-1")==0)
        {  
           sort1=fopen("sortBH-1.dat","a+");
           printf("\t\tFollowing are students of BH-1 hostel:");
           printf("\n\tROLL NO.\tROOM NO.\tNAME\n");
           printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
           test++;
           fprintf(sort1, "%s %s %s\n", sort.roll_no, sort.room_no, sort.name);
           fclose(sort1);
        }
        else if(choice==2 && strcmp(sort.hostel_name,"BH-2")==0)
        {  
           sort2=fopen("sortBH-2.dat","a+");
           printf("\t\tFollowing are students of BH-2 hostel:");
           printf("\n\tROLL NO.\tROOM NO.\tNAME\n");
           printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
           test++;
           fprintf(sort2, "%s %s %s\n", sort.roll_no, sort.room_no, sort.name);
           fclose(sort2);
        }
        else if(choice==3 && strcmp(sort.hostel_name,"BH-3")==0)
        {
           sort3=fopen("sortBH-3.dat","a+");
           printf("\t\tFollowing are students of BH-3 hostel:");
           printf("\n\tROLL NO.\tROOM NO.\tNAME\n");
           printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
           test++;
           fprintf(sort3, "%s %s %s\n", sort.roll_no, sort.room_no, sort.name);
           fclose(sort3);
        }
        else if(choice==4 && strcmp(sort.hostel_name,"GH-1")==0)
        {
           sort4=fopen("sortBH-4.dat","a+");
           printf("\t\tFollowing are students of GH-1 hostel:");
           printf("\n\tROLL NO.\tROOM NO.\tNAME\n");
           printf("\n\t%8s\t %8s\t %s", sort.roll_no, sort.room_no, sort.name);
           test++;
           fprintf(sort4, "%s %s %s\n", sort.roll_no, sort.room_no, sort.name);
           fclose(sort4);
        }
    }
    fclose(fp);
    if (test==0)
        {   
        printf("\nNO RECORDS!!\n");}

sort_list_invalid:
 printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }
    
}

void closer()
{
    printf("\n\n\n\nDeveloped by Himanshu Daga\n\n\n");
}


void menu(void)
{   int choice;
    

    printf("\n\n\t\t\tHOSTEL DATA MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Enter new Student's data\n\t\t2.Update information of existing account\n\t\t3.Check the details of existing account\n\t\t4.View all Students of a particlar Hostel\n\t\t5.Removing existing account\n\t\t6.View all students list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    
    switch(choice)
    {
        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:sorter();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:closer();
        break;

    }



}
int main()
{
  menu();
  return 0;
}
