#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

//Function declaration :: these functions are used to create new features in BMS PROJECT
void creatAccount(void);
void login(void);
void accountCreatedSuccessful(void);
void loginSuccessfull(void);
void dataNotFound(void);
void displayUserAccount(char username[]);
void checkBalance(char username[]);
void transferMoney(void);
void displayUserData(char username[]);
void changePassword(char username[]);
void logout(void);

//Creating a gotoxy() function to set curson positio
void gotoxy(int x, int y) 
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//DRIVER CODE
int main() 
{
	gotoxy(20, 2);
	printf("-BANK MANAGEMENT SYSTEM PROJECT-");
	
	gotoxy(18, 3);
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
	
	gotoxy(22, 5);
	printf("Team Ashirwad - WELCOMES YOU");
	
	gotoxy(20, 6);
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
	
	int choice;
	
	//Menu for user to perform actions
	
	gotoxy(20, 10);
	printf("1. -> Create Your Bank Account");
	
	gotoxy(20, 12);
	printf("2. -> Account Exist ? Log In");
	
	gotoxy(20, 14);
	printf("3. -> End Program");
	
	gotoxy(23, 17);
	printf("Enter Your Choice : ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1 : 
			creatAccount();
			break;			
		case 2 : 
			login();
			break;
		case 3 : 
			exit(0);
			break;
			getch();			
	}	
}

//Creat STRUCTURE to store user information
 struct userdata {
 	char firstName[20];
 	char lastName[20];
 	char fatherName[20];
 	char motherName[20];
 	char address[50];
 	int date, month, year;
 	char adhar[20];
 	char phone[20];
 	char username[30];
 };
 
//create structure to store money related data
struct money {
	int amt;
	char usernameto[20]; //receiver
	char usernamefrom[20]; //sender
};

//creatAccount Function is used to create user bank account
void creatAccount(void)
{
	struct userdata u1;
	
	FILE *fp;
	
	//opening file userdata to store user information in apend binary mode
	fp = fopen("userdata.txt", "ab");	
	if(fp == NULL)
	{
		printf("Error in Opening File");
	}

	//taking inputs
	system("cls");
	
	gotoxy(10, 2);
	printf("- ENTER YOUR DETAILS -");
	
	gotoxy(6, 4);
	printf("Enter First Name : ");
	scanf("%s", &u1.firstName);
	
	gotoxy(6, 5);
	printf("Enter Last Name : ");
	scanf("%s", &u1.lastName);
	
	gotoxy(6, 6);
	printf("Enter Father's Name : ");
	scanf("%s", &u1.fatherName);
	
	gotoxy(6, 7);
	printf("Enter Mother's Name : ");
	scanf("%s", &u1.motherName);
	
	gotoxy(6, 8);
	printf("Enter Address : ");
	scanf("%s", &u1.address);
	
	gotoxy(6, 9);
	printf("Enter Date of Birth- ");
	
	gotoxy(6, 10);
	printf("Date : ");
	scanf("%d", &u1.date);
	
	gotoxy(6, 11);
	printf("Month : ");
	scanf("%d", &u1.month);
	
	gotoxy(6, 12);
	printf("Year : ");
	scanf("%d", &u1.year);
	
	gotoxy(6, 13);
	printf("Adhar Number : ");
	scanf("%s", &u1.adhar);
	
	gotoxy(6, 14);
	printf("Mobile Number : ");
	scanf("%s", &u1.phone);
	
	gotoxy(6, 16);
	printf("USERNAME(in lowercase letter) : ");
	scanf("%s", &u1.username);
	
	char password[30];
	char ch;
	int i;
	
	gotoxy(6, 17);
	printf("Enter Password : ");
	
	//taking password input but in star form
	for(i=0; i<30; i++)
	{
		ch = getch(); //taking input in characters without displaying it
		if(ch != 13)  //checking if entered key is not enter
		{
			password[i] = ch; // putting enter character in password array to store
			ch = '*';
			printf("%c", ch); //printing star in place of character to hide password
		}
		else {
			break;
		}
	}
	
	//writing all the user data in the userdata file
	fwrite(&u1, sizeof(u1), 1, fp);
	
	fclose(fp);
	
	//calling "succesfully account created" function 
	accountCreatedSuccessful();
}

//this function shows that user bank account is successfully created

void accountCreatedSuccessful(void)
{
	system("cls");
	
	gotoxy(20, 3);
	printf("Please wait, we are processing.....");
	
	gotoxy(20, 5);
	printf("Uploading your data on server.......");
	
	int i;
	for(i=0; i<100000000; i++)
	{
		i++;
		i--;
	}
	
	gotoxy(30, 13);
	printf("-*BANK ACCOUNT SUCCESSFULLY CREATED*-");
	
	gotoxy(10, 21);
	printf("Press any key to continue :-");
	
	getch();
	
	//callig function to redirect on login page
	login();
}

// login function - user with account can login through this page

void login(void) 
{	
	system("cls");
	char ch;
	int i;
	
	//always declare structure related stuffs top in function because it can show error during running since it is used by any logic
	struct userdata u1;	
	FILE *fp;	
	fp = fopen("userdata.txt", "rb");
	
	if(fp == NULL)
	{
		printf("Error in opening file");
	}
	
	gotoxy(25, 2);
	printf("-* ACCOUNT HOLDER LOGIN PAGE *-");
	
	for(i=0; i<100000000; i++)
	{
		i++;
		i--;
	}
	
	gotoxy(30,5);
	printf("-*-**LOGIN**-*-");
	
	//input username and password
	char username[20], password[20];
	
	gotoxy(25, 8);
	printf("Username : ");
	scanf("%s", &username);
	
	gotoxy(25, 10);
	printf("Password : ");
	
	//taking password input but in star form
	for(i=0; i<20; i++)
	{
		ch = getch(); //taking input in characters without displaying it
		if(ch != 13)  //checking if entered key is not enter
		{
			password[i] = ch; // putting enter character in password array to store
			ch = '*';
			printf("%c", ch); //printing star in place of character to hide password
		}
		else {
			break;
		}
	}
	
	//check whether username exist in userdata or not
	int flag = 0;
	while (fread(&u1, sizeof(u1), 1, fp))
	{
    	if (strcmp(username, u1.username) == 0)
    	{
    		flag = 1;
        	loginSuccessfull(); 
    	    displayUserAccount(username);
    	    break;
    	}
	}
	if(!flag)
	{
		dataNotFound();
	}
		
	fclose(fp);	
}

//this function used to display login successfull window
void loginSuccessfull(void)
{
	system("cls");
	
	gotoxy(5,2);
	printf("Matching user data---");
	
	int i;
	for(i=0; i<100000000; i++)
	{
		i++;
		i--;
	}
	
	gotoxy(20, 10);
	printf("-*-** Successful LogIn **-*-");
	
	gotoxy(5, 18);
	printf("Press Enter to Continue :-");
	
	getch();	
}

//function to show user id and password is not present in user data or invalid login
void dataNotFound(void) 
{
	system("cls");
	
	gotoxy(20, 10);
	printf("Username or Password is incorrect...");
	
	gotoxy(5, 18);
	printf("Press Enter to Try Again :-");
	
	getch();
	login();
}

//this functon used to opne account holders data and help him perform different operation inside his bank acount
void displayUserAccount(char username[])
{
	FILE *fp;
	fp = fopen("userdata.txt", "rb");
	
	struct userdata u1;
	
	if(fp == NULL)
	{
		printf("Error in opening file");
	}
	
	system("cls");
	
	while(fread(&u1, sizeof(u1), 1, fp))
	{
		if(strcmp(username, u1.username) == 0)
		{
			gotoxy(10, 2);
			printf("Welecome, %s %s", u1.firstName, u1.lastName);
	
			gotoxy(18, 6);
			printf("-*HOME*-");
		}
	}
	
	//Menu to perform different ooperation by account holder
	
	gotoxy(10, 10);
	printf("1. -> Check Balance");
			
	gotoxy(10, 12);
	printf("2. -> Transfer Money");
			
	gotoxy(10, 14);
	printf("3. -> Account Details");
			
	gotoxy(10, 16);
	printf("4. -> Change Password");
			
	gotoxy(10, 18);
	printf("5. -> LogOut");
			
	gotoxy(10, 20);
	printf("6. -> Exit");
	
	gotoxy(10, 24);
	int choice;
	printf("Enter your Choice : ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1 :
			checkBalance(username);
			break;
		case 2 :
			transferMoney();
			break;
		case 3 :
			displayUserData(username);
			break;
		case 4 :
			changePassword(username);
			break;
		case 5 :
			logout();
		case 6 :
			exit(1);
	}
	
}

void checkBalance(char username[])
{
	struct money m;
	FILE *fm;
	fm = fopen("moneydata.txt", "rb");
	if(fm == NULL)
	{
		printf("error in opening file");
	}
	
	int i = 0, sum = 0;
	system("cls");
	
	gotoxy(30, 2);
	printf("-*TRANSECTION DASHBOARD*-");
	
	int k = 5, l = 10;
	int a = 35, b = 10;
	int p = 65, q = 10;
	
	gotoxy(k, l);
	printf("S.No.");
	
	gotoxy(a, b);
	printf("Transection ID ");
	
	gotoxy(p, q);
	printf("Amount");
	
	while(fread(&m, sizeof(m), 1, fm))
	{
		if(strcmp(username, m.usernameto) == 0)
		{
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			
			gotoxy(a, ++b);
			printf("%s", m.usernamefrom);
			
			gotoxy(p, ++q);
			printf("%d", m.amt);
			
			//calcuating total amount present in bank account
			sum = sum + m.amt;
		}
	}
	
	gotoxy(80, 10);
	printf("Total Amount");
	
	gotoxy(80, 12);
	printf("%d", sum);
	
	getch();
	
	fclose(fm);
	
	displayUserAccount(username);
	
	
}

//function to transfer money from one account to another
void transferMoney(void)
{
	struct userdata u1;
	struct money m;
	
	FILE *fp, *fm;
	fp = fopen("userdata.txt", "rb");
	if(fp == NULL) {
		printf("error in opening file");
	}
	fm = fopen("moneydata.txt", "ab");
	if(fm == NULL) {
		printf("error in opening file");
	}
	
	system("cls");
	
	char user1[50], user2[50];
	
	gotoxy(25, 2);
	printf("-* Transfer Money *-");
	
	gotoxy(20, 5);
	printf("Sender's Username :");
	scanf("%s", &user1);
	gotoxy(20, 7);
	printf("Receiver's Username :");
	scanf("%s", &user2);
	
	//check if receiver is present in userdata or not
	while(fread(&u1, sizeof(u1), 1, fp))
	{
		if(strcmp(user2, u1.username) == 0)
		{
			strcpy(m.usernameto, u1.username);
			strcpy(m.usernamefrom, user1);
		}
		
	}
	
	gotoxy(20, 10);
	printf("enter amount to be transfered : ");
	scanf("%d", &m.amt);
	
	//writing to the file
	fwrite(&m, sizeof(m), 1, fm);
	
	gotoxy(10, 20);
	printf("transferring please wait....");
	gotoxy(10, 21);
	int i, j;
	for(i=0; i<70; i++)
	{
		for(j=0; j<1200000; j++)
		{
			j++;
			j--;
		}
		printf(".");
	}
	gotoxy(10,22);
	printf("Amout Transferred Successfully---");
	
	getch();
	
	fclose(fp);
	fclose(fm);
	
	displayUserAccount(user1);	
}

// this function is used to display bank account holder personal details
void displayUserData(char username[])
{
	struct userdata u1;
	FILE *fp;
	fp = fopen("userdata.txt", "rb");
	if(fp == NULL)
	{
		printf("Error in opening file");
	}
	
	system("cls");
	
	while(fread(&u1, sizeof(u1), 1, fp))
	{
		if(strcmp(username, u1.username) == 0)
		{
			gotoxy(30, 3);
			printf(" Dear %s, Your Account Information", u1.firstName);
			
			gotoxy(29, 4);
			printf("********************************************");
			
			gotoxy(30, 6);
			printf("Name : %s %s", u1.firstName, u1.lastName);
			
			gotoxy(30, 8);
			printf("Father's Name : %s %s", u1.fatherName, u1.lastName);
			
			gotoxy(30, 10);
			printf("Mother's Name : %s %s", u1.motherName, u1.lastName);
			
			gotoxy(30, 12);
			printf("Address : %s", u1.address);
			
			gotoxy(30, 14);
			printf("DOB : %d/%d/%d", u1.date, u1.month, u1.year);
			
			gotoxy(30, 16);
			printf("Adhar No : %s", u1.adhar);
			
			gotoxy(30, 18);
			printf("Phone No : %s", u1.phone);
		}
	}
	
	fclose(fp);
	getch();
	displayUserAccount(username);
}

//to change password
void changePassword(char username[])
{
	struct userdata u1;
	FILE *fp;
	fp = fopen("userdata.txt", "rb+");
	if(fp == NULL)
	{
		printf("Error in opening file");
	}
	strcpy(username, u1.username);
	
	char p1[30], p2[30];
	int i;
	char ch;
	system("cls");
	gotoxy(10, 5);
	printf("Enter Current Password : ");
	for(i=0; i<30; i++)
	{
		ch = getch(); //taking input in characters without displaying it
		if(ch != 13)  //checking if entered key is not enter
		{
			p1[i] = ch; // putting enter character in password array to store
			ch = '*';
			printf("%c", ch); //printing star in place of character to hide password
		}
		else {
			break;
		}
	}
	
	gotoxy(10, 6);
	printf("Enter New Password : ");
	scanf("%s", &p2);
	
	gotoxy(10, 9);
	printf("Password Changed Successfully....");
	
	getch();
	fclose(fp);
	
	displayUserAccount(username);
	
	
}

//to logout
void logout(void)
{
	system("cls");
	int i, j;
	
	gotoxy(5, 2);
	printf("Please wait, logging out...");
	for(i=0; i<100000000; i++)
	{
		i++;
		i--;
	}
	
	gotoxy(15, 10);
	printf("-*SignOut Successfully*-");
	
	gotoxy(5, 18);
	printf("Press enter to login : ");
	
	getch();
	login();
}
