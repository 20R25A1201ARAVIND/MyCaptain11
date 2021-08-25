#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
void new_acc();
void show_list();
void edit();
void transact();
void erase();
void see();
void close();
struct date{
    int month,day,year;
    };
struct {
    char name[60];
    int AcNo,Age;
    char address[60];
    char ctznsp[25];
    double PhoneNo;
    char acc_type[10];
    float amt;
    struct date DOB;
    struct date deposit;
    struct date withdraw;
    }add,updt,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
int main()
{
    char pass[10],password[10]="12345";
    int i=0;
    printf("\n\n\t\tEnter the Password to Login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nCorrect Password! Wait...\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nInvalid Password!!\a\a\a\nPlease Enter Valid Password!");
            login_try:
            printf("\nEnter 1 for Retry  or Enter 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}

void menu(void)
{   int choice;
    system("cls");
    system("color 2");
    printf("\n\n\t\t\t****BANK MANAGEMENT SYSTEM****");
    printf("\n\n\n\t\t\t*****WELCOME TO THE MAIN MENU*****\t\t\t\t\t\n\n");
    printf("\n\n\t\t1.Create a new account\n\t\t2.Updtate/Edit information of existing account\n\t\t3. Select here For transactions\n\t\t4.View the details of existing account\n\t\t5.Removing existing account\n\t\t6.show customer's list \n\t\t7.Exit\n\n\n\n\n\t\t Enter the Operation You Have to Do(Select from Above):");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:show_list();
        break;
        case 7:close();
        break;
    }
}

void new_acc()

{
    int choice;
    FILE *fp;

    fp=fopen("aravind.txt","a+");
    Ac_Num:
    system("cls");
    printf("\t\t\t ***ADDING New RECORD*** \t\t\t");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the New Account Number:");
    scanf("%d",&check.AcNo);
    while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.AcNo==add.AcNo)
            {printf("Account Number is  already in use!");
            fordelay(1000000000);
                goto Ac_Num;

            }
    }
    add.AcNo=check.AcNo;
        printf("\nEnter Your Name:");
    scanf("%s",add.name);
    printf("\nEnter Your Date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.DOB.month,&add.DOB.day,&add.DOB.year);
    printf("\nEnter Your Age:");
    scanf("%d",&add.Age);
    printf("\nEnter the Address:");
    scanf("%s",add.address);
    printf("\nEnter the citizanship number:");
    scanf("%s",add.ctznsp);
    printf("\nEnter YourPhone number: ");
    scanf("%lf",&add.PhoneNo);
    printf("\nEnter the amount to Deposit into your Account:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t->Savings\n\t->Current\n\t->Fixed1(for 1 year)\n\t->Fixed2(for 2 years)\n\t->Fixed3(for 3 years)\n\n\tEnter your choice of account type:");
    scanf("%s",add.acc_type);

        fprintf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(fp);
    printf("\nYour Account created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void show_list()
{
    FILE *show;
    show=fopen("aravind.txt","r");
    int test=0;
    system("cls");
    printf("\nACC-NO.\tNAME\t\t\tADDRESS\t\t\tPhoneNo\n");

    while(fscanf(show,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.AcNo,add.name,add.address,add.PhoneNo);
           test++;
       }

    fclose(show);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    show_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto show_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("aravind.txt","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to Edit:");
    scanf("%d",&updt.AcNo);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.AcNo==updt.AcNo)
        {   test=1;
            printf("\nWhich information do you want to Edit/Update?\n1.Address\n2.PhoneNo\n\nEnter your choice(1 for address and 2 for PhoneNo):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new Address:");
                scanf("%s",updt.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,updt.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes Saved Successfully!");
                }
            else if(choice==2)
                {
                    printf("Enter the new Phone number:");
                scanf("%lf",&updt.PhoneNo);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,updt.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes Saved Successfully!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("aravind.txt");
    rename("new.dat","aravind.txt");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!(please enter proper Account Number)\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("aravind.txt","r");
    newrec=fopen("new.dat","w");

        printf("Enter the Account no. of the customer:");
    scanf("%d",&transaction.AcNo);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.AcNo==transaction.AcNo)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to Deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to Withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("aravind.txt");
   rename("new.dat","aravind.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("aravind.txt","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Account no. of the customer you want to Delete:");
    scanf("%d",&rem.AcNo);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.AcNo!=rem.AcNo)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord Deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("aravind.txt");
   rename("new.dat","aravind.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *fp;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    fp=fopen("aravind.txt","r");
    printf("Do you want to check by\n1.Account-no (or)\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the Account number:");
        scanf("%d",&check.AcNo);

        while (fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.AcNo==check.AcNo)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nctznsp No:%s \nPhoneNo number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the Name of Account Holder:");
        scanf("%s",&check.name);
        while (fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.AcNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.Age,add.address,add.ctznsp,&add.PhoneNo,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDate-Of-Birth:%d/%d/%d \nAge:%d \nAddress:%s \nctznsp No:%s \nPhoneNo number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.AcNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.Age,add.address,add.ctznsp,add.PhoneNo,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will not get any interest on this type of account\a\a");

                     }

            }
        }
    }
    fclose(fp);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}
void close(void)
{
    printf("\n\n\n\nBank Mangement System (mini)-Project made By Aravind");
    }




/*Password to Login is 12345*/
