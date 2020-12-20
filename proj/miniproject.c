#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#define max 78
void hello();
void bye();
int getlen(FILE *fp,char *filename);
void reception();
void login();
void receplogin();
void enter();
void list();
void cio();
void checkin();
void checkout();
void userdetails();
void adminlogin();
void view();
void searchuser();
void regist();
void feedetails();
void user();
void feepayment(int);
#pragma startup hello
#pragma exit bye
void hello()
{
	printf("***************HELLO WELCOME TO VASAVI HOSTEL******************");
}
void bye()
{
	printf("******************GOOD BYE***********************");
}
int main()
{
	
	int no=1,n;
	printf("\n\nEnter\n ");
	//Main page where the user/admin/receptionist enter one of these
	do{
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
		printf("\n\t\t\t\t\t\t1.Receptionist\n\t\t\t\t\t\t2.Admin\n\t\t\t\t\t\t3.User\n\t\t\t\t\t\t4.Exit\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				reception();
                break;
			case 2:
				adminlogin();
				break;
			case 3:
			hello();
				user();
				break;
			case 4:
			exit(0);
		}
	}while(n!=4);
	bye();
	return 0;
}
struct VisitorsDetails   //Structure Declaration
{
	char roomnumber[10];
	char name[20];
	char arrivaldate[10];
	char time[10];
	char date[10];
}s;
int getlen(FILE *fp,char *fname)
{
	//This function returns the number of lines in a file
	char c;
	int count=0;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		for(c=getc(fp);c!=EOF;c=getc(fp))
		{
			if(c=='\n')
			{
				count=count+1;
			}
		}
	}
	fclose(fp);
	return count;
}
void reception()
{
	//Function handled by receptionist
	int i=0;
	time_t t;
	time(&t);
	char visitorname[20];
	char alloteename[20];
	char choice;
	system("cls");   // For Clearing Screen

	printf(" \n Press any key to continue:");

	getch();
    system("cls");
    receplogin();
    system("cls");
	while (1)      // Infinite Loop
	{
		system("cls");
		
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf(" \n Enter 1 -> Enter Visitors details");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Visitors list");
		printf("\n----------------------------------");
		printf(" \n Enter 3-> Enter Check in/out details");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> View Check in/out details of allotees");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Back to main menu");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // Switch Statement
		{
			case '1':
				enter();break;
			case '2':
				list();break;
			case '3':
				cio();break;
			case '4':
				view();break;
            case '5':
                main();break;
			case '6':
				system("cls");
				printf("\n\n\t THANK YOU");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void receplogin()
{
	//Function for reception login
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="reception";
    char pass[10]="pass";
    do
{
	system("cls");

    printf("\n**********LOGIN FORM********");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
    	pword[i]=getch();
    	c=pword[i];
    	if(c==13) break;
    	else printf("*");
    	i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
void enter()
{
	FILE *f;
	time_t t;
	time(&t);
	char test;
	char alloteename[20];
	char visitorname[20];
	int arrivaldate;
	f=fopen("visitor.txt","a");
	printf("\n Enter Visitors Details:");
		//printf("\n**");
		printf("\n Enter Allotee name:\n");
		scanf("%s",&alloteename);
		//fflush(stdin);
		printf("Enter Visitor name:\n");
		scanf("%s",&visitorname);
	if(f==NULL)
	{
		printf("File is empty");
	}
	else
	{
		fprintf(f,"%s\t\t%s\t\t\t%s\n",alloteename,visitorname,ctime(&t));
	}
	//fflush(stdout);
	fclose(f);
}
void list()
{
	FILE *f;
	time_t t;
	time(&t);
	char alloteename[20];
	char visitorname[20];
	char str[80];
	int i;
	if((f=fopen("visitor.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ALLOTEENAME    ");
	printf("VISITOR NAME\t ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<118;i++)
		printf("-");
	printf("\n");
	while(fgets(str,80,f)!=NULL)
	{
		
		//printf("\n%s \t%s  \t  %s",s.alloteename, s.visitorname, ctime(&t));
		puts(str);
	}
	//printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}
void cio()
{
	int i=0;
	char choice;
	//int len;
	char alloteename[20];
	//int time;
	//int date;
   FILE *f;
	//time_t t;
	//time(&t);
	char test;
	f=fopen("cio.txt","a");
	printf("\n Enter Check in/out  Details:");
		printf("\n**");
		printf("\n Enter Allotee name:\n");
		scanf("%s",&alloteename);
		//fflush(stdin);
		printf("Enter your choice\n");
		printf(" \n Enter 1 -> Check in");
		printf("\n------------------------");
		printf(" \n Enter 2 -> Check out");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
		if(f==NULL)
		{
			printf("File is empty");
		}
		else
		{
			fprintf(f,"%s",alloteename);
		}
		fclose(f);
		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				checkin();break;
			//case '2':
			//	list();break;
			case '2':
				checkout();break;
			//case '4':
			//	view();break;
			case '3':
				system("cls");
				printf("\n\n\t THANK YOU");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	
		//printf("Enter Checkin/out :\n");
		//scanf("%d",&time);
		//printf("Enter Checkin/out date(dd\\mm\\yyyy):\n");
		//scanf("%d",&date);
		//int len=getlen(f,"visitor.txt");	
	/*if(f==0)
	{   f=fopen("visitor.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Check in/out  Details:");
		printf("\n**");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Checkin/out time:\n");
		scanf("%s",s.time);
		printf("Enter Checkin/out date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.date);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Check in/out  is successfully added!!");
		printf("\n Press esc  key to main menu,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	//fclose(f);*/
	//fflush(stdout);
}
void checkin()
{
	time_t t;
	time(&t);
	FILE *f;
	f=fopen("cio.txt","a");
	if(f==NULL)
	{
		printf("File is empty");
	}
	else
	{
		fprintf(f,"\t%s",ctime(&t));
	}
	fclose(f);
}
void checkout()
{
	time_t t;
	time(&t);
	FILE *f;
	f=fopen("cio.txt","a");
		if(f==NULL)
	{
		printf("File is empty");
	}
	else
	{
		fprintf(f,"\t\t\t\t\t%s",ctime(&t));
	}
	fclose(f);
}
void view()
{
	//Viewing the check in and check out deatils of allotees
	FILE *f;
	char alloteename[20];
	char str[80];
	time_t t;
	time(&t);
	int i;
	if((f=fopen("cio.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("NAME    ");
	printf("CHECKINTIME,DATE\t ");
	printf("\t CHECKOUTTIME,DATE \n");

	for(i=0;i<118;i++)
		printf("-");
	printf("\n");
	while(fgets(str,80,f)!=NULL)
	{
		puts(str);
	}
	for(i=0;i<118;i++)
		printf("-");
	fclose(f);
	getch();
}
void adminlogin()
{
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin@12";
    char pass[10]="12345678";
    do
	{
	system("cls");
	//Login form for admin
    printf("\n  *  LOGIN FORM  *  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
    	pword[i]=getch();
    	c=pword[i];
    	if(c==13) break;
    	else printf("*");
    	i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
	}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

	}
        int n;
		printf("\n\t\tPlease Enter choice from menu\n");
        printf("\n\n");
		do
		{
            printf(" \n Enter 1 -> View details of Allotees details");
		    printf("\n---------------------------------------------");
            printf(" \n Enter 2 -> View Visitors details");
		    printf("\n--------------------------------------");
            printf(" \n Enter 3 -> Search a Allotee");
		    printf("\n-----------------------------");
            printf(" \n Enter 4 ->View Fee Details");
            printf("\n-----------------------------");
            printf(" \n Enter 5 ->Back to main menu");
            printf("\n-----------------------------");
            printf(" \n Enter 6 ->Exit");
            printf("\n-----------------");
			scanf("%d",&n);
			switch(n)
			{
				case 1:
					userdetails();
					break;
				case 2:
					list();
					break;
				case 3:
				searchuser();
					break;
				case 4:
                feedetails();
					break;
				case 5:
                    main();
					break;
				case 6:
					exit(0);
			}
		}while(n!=6);
}
void userdetails()
{
	
	//Lists all the details of all the user
	char line[256];
	FILE *fp=fopen("Admin.txt","r");
	while(fgets(line,sizeof(line),fp)!=NULL){
        printf("\n");
		fputs(line,stdout);
	}
	fclose(fp);
}
void searchuser()
{
	//This function searches by roll number and displays
	int n,i=0,k=0,j=0,g=0;
	char line[256];
	
	printf("Enter the sno to search");
	scanf("%d",&n);
    
	if(n==0)
	{
        printf("\nNO USER\n");
    }
	else
	{
		
	    FILE *fp=fopen("Admin.txt","r");
        k=((n-1)*10)+3;
		while(fgets(line,sizeof(line),fp)!=NULL){
		i++;
		if(i>=k)
		{
			if(j==9)
			{
				break;
			}
			fputs(line,stdout);
			g=1;
			j++;
		}
		}
		if(g==0)
		{
			printf("\nNO USER\n");
		}
		
		fclose(fp);
    }
}
void feedetails()
{
	//Details of list of students who have paid and not paid the fee
	char line[256];
	FILE *fp=fopen("Pay.txt","r");
	printf("\nSno - Paid\n");
	while(fgets(line,sizeof(line),fp)!=NULL){
		fputs(line,stdout);
	}
	fclose(fp);
}
void user()
{
	int age,noofd,n;
	char fname[20],name[20],qual[30],fno[13],res[40];
	FILE *fptr;
	do{
		//Asks the user to enter the registration or login(if already exists then login)
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
		printf("\n\t\t\t\t\t\t1.Registration\n\t\t\t\t\t\t2.Login\n\t\t\t\t\t\t3.Exit\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t||                                          ||\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        printf("\n\t\t\t\t\t---------------------------------------------\n");
        
		scanf("%d",&n);
		switch(n)
		{
			//Deatils for the student for filling
			case 1:
			printf("\n1-Enter your name:");
			scanf("%s",name);
            printf("\n----------------");
			printf("\n2-Enter your age:");
			scanf("%d",&age);
            printf("\n----------------");
			printf("\n3-Enter your qualifications :");
			scanf("%s",qual);
            printf("\n-------------------------");
			printf("\n4-Enter your father's name:");
			scanf(" %[^\n]",fname);
            printf("\n----------------------");
			printf("\n5-Enter your father's phone number:");
			scanf(" %[^\n]",fno);
            printf("\n------------------------------");
			printf("\n6-Enter your residency:");
			scanf(" %[^\n]",res);
            printf("\n-------------------");
			printf("\n7-Enter your duration of course in days:");
			scanf("%d",&noofd);
            printf("\n-----------------------------------");
			fptr=fopen("Admin.txt","a");
			int p=getlen(fptr,"Admin.txt");
			if(fptr==NULL)
			{
				printf("File doesn't exist");
			}
			//Writes all the information into a file
			else
			{
				fprintf(fptr,"\n\nSno - %d\nName - %s\nAge - %d\nQualifications - %s\nFather's name - %s\nFather's Number - %s\nResidency - %s\nDuration of course - %d days\n",(p/10)+1,name,age,qual,fname,fno,res,noofd);
				fclose(fptr);
			}
			printf("\n                         Your permanent SERIAL NUMBER is %d for registration",(p/10)+1);
			regist();
			break;
			case 2:
				login();
				break;
			case 3:
				main();
		}
	}while(n!=5);
}
void regist()
{
	//Function to register the student username and password
	char user_name[30],password[20],c=' ';
    int i=0;
	FILE *usp,*ad;
	usp=fopen("Register.txt","a");
	ad=fopen("Admin.txt","a");
	printf("\n**************Registering*****************\n");
	printf("                                         Enter your username:");
	scanf("%s",user_name);
	printf("                                         Enter your password:");
    while(i<15)
	{
    	password[i]=getch();
    	c=password[i];
    	if(c==13) break;
    	else printf("*");
    	i++;
	}
	password[i]='\0';
	i=0;
	int len=getlen(usp,"Register.txt");
	if(usp==NULL)
	{
		printf("File is empty");
	}
	//Enters the student username and password in the file named Register.txt
	else
	{
		fprintf(usp,"Sno - %d\nUsername - %s\nPassword - %s\n",(len/3)+1,user_name,password);
			printf("\nYOU HAVE SUCCESSFULLY REGISTERED\n\n");
	}

	fclose(usp);
	fclose(ad);
}
void login()
{
	int sno,choice;
	char usn[30],pssd[20],b[100],c=' ';
	char ch,*n;
    int i=0;
    printf("***************LOGIN****************");
	//Asks to enter the serial number
	printf("\n                                     Enter your sno:");
	scanf("%d",&sno);
	//Asks to enter the password
	printf("\n                                     Enter username:");
	scanf("%s",usn);
	printf("\n                                     Enter password");
    while(i<15)
	{
    	pssd[i]=getch();
    	c=pssd[i];
    	if(c==13) break;
    	else printf("*");
    	i++;
	}
	pssd[i]='\0';
	i=0;
	FILE *sm=fopen("Register.txt","r");
	int len=getlen(sm,"Register.txt");
	char buf[30],l[len/3][20];
	while(fscanf(sm,"%*s %*s %s",buf)==1)
	{
		strcpy(l[i],buf);
			i++;
	}
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(strcmp(l[i],usn)==0){
			if(strcmp(l[i+1],pssd)==0){
				flag=0;
				break;
			}
		}
		else{
			flag=1;
		}
	}
	
	int amt=0;
	int dur,num;
	FILE *fptr;
	FILE *fptr1;
	char line[256];
	int j=0;
	//if username and password is correct then displays below
	if(flag==0){
		printf("\n\n---------------------------------------Login successful---------------------------------------------------");
		do{
			//List of options that the student has to go through when he enters the logins for the first time
			printf("\nPlease Enter your choice\n");
            printf("\n\t\t\t\t\t---------------------------------------------\n");
            printf("\n\t\t\t\t\t---------------------------------------------\n");
            printf("\n\t\t\t\t\t||                                          ||\n");
            printf("\n\t\t\t\t\t||                                          ||\n");
			printf("\t\t\t\t\t\t1.Allotting rooms\n\t\t\t\t\t\t2.Services \n\t\t\t\t\t\t3.FeePayment\n\t\t\t\t\t\t4.Log Out\n");
            printf("\n\t\t\t\t\t||                                          ||\n");
            printf("\n\t\t\t\t\t||                                          ||\n");
            printf("\n\t\t\t\t\t---------------------------------------------\n");
            printf("\n\t\t\t\t\t---------------------------------------------\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					//Automatically this code allocates a member to a room with bed number along with three members per room 
					fptr1=fopen("checkRooms.txt","r");
					while(fgets(line,sizeof(line),fptr1))
					{
						j++;
						if(j==sno)
						{
							printf("\n                                    Your room no with bed number is %s\n",line);
						}
					}
					fclose(fptr1);
				break;
                case 2:
					
					fptr=fopen("FeePayment.txt","a");
					
					int length=getlen(fptr,"FeePayment.txt");
					//If the number of lines in file is less than serial number then the following prompts
					if(length<sno)
					{
							printf("\nEnter the services you want for your stay in the hostel\n\n");
						printf("Enter your duration of course");
						scanf("%d",&dur);
						do{
							printf("\n1.Laundry\n2.Food\n3.Cleaning\n4.Exit\n");
							scanf("%d",&num);
							switch(num)
							{
								case 1:
									amt+=50;
									break;
								case 2:
									amt+=70;
									break;
								case 3:
									amt+=40;
									break;
								case 4:
									goto LOOP;
							}
						}while(num!=4);
						LOOP:
						//calculates the total amout of services wanted and writes into file
						fprintf(fptr,"%d - %d\n",sno,amt*dur);
						fclose(fptr);
						printf("you have successfully entered the services you want");
					}
					//If already entered then displays below
					else
					{
						printf("You have already entered your services");
					}
                    break;
				case 3:
					feepayment(sno);
				break;
				case 4:
					user();
				break;
				default:
				printf("Please enter the correct number");
				break;
			}
		}while(choice!=5);
	}
	//If username or password is incorrect then displays below
	else
	{
		printf("\n----------------------------------------------------------LOGIN ERROR---------------------------------------------------------");
	}
	fclose(sm);
}
void feepayment(int sno)
{
	int n,amt;
	char buf[90],v[max][90],s[4];
	char buffer[90],k[max][90];
	int i=0,j=0;
	FILE *fpay=fopen("Pay.txt","a");
	FILE *fptr=fopen("FeePayment.txt","r");
	FILE *fpay2;
	while(fscanf(fptr,"%*s %*s %s",buf)==1)
	{
		//Copying the fee in buf variable 
		strcpy(v[i],buf);
		i++;
	}
	printf("Your fee");
	//Serial number then the fee gets displayed
	printf("%s",v[sno-1]);
	int len=getlen(fpay,"Pay.txt");
	//If paid the fee then it writes you have paid the fee otherwise
	if(len<sno)
	{
		printf("\nDid you pay the fee yes/no");
		scanf("%s",s);
		fprintf(fpay,"%d - %s\n",sno,s);
		fclose(fpay);
	}
		fpay2=fopen("Pay.txt","r");
	while(fscanf(fpay2,"%*d %*s %s",buffer)==1){
		strcpy(k[j],buffer);
		j++;
	}
	
		//Displays whether the student has paid the fee or not
	if(len>=sno){
		if(strcmp(k[sno-1],"yes")==0){
			printf("\n\nYOU HAVE PAID THE FEE\n");
		}
		else{
			printf("\n\nYOU HAVE NOT PAID THE FEE\n");
		}
	}
		fclose(fpay2);
	fclose(fptr);
}