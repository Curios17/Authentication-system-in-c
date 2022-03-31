/* This is a little authenication system
It basically takes in user's information
if it is a new user, it registers the user.
It takes information like;
     -Name(First and Second)
     -Email
     -Contact
     -Password
if it is an old user, it lets him login
by checking information like;
   -Username
   -Email or contact

   BY @curious17.tech on instagram
   31st -March -2022

   */
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define key 13
 struct info
{
    char firstname[20];
    char secondname[20];
    char contact[9];
    char email[20];
    char PassWord[20];
    char username[20];
};
//*****Functions*******
void  TakePassword( char Password[8])
{ 
 int i=0;
    while(1)
    {
        Password[i]=getch();
        printf("*");//Keeps getting user's password untill the enter key is pressed
        if(Password[i]==key)
        {
                
            Password[i]='\0';

            break;
        }
        i++;
    }
    printf("%s",Password);
}
void takeinput(char ch[20])
{
    fgets(ch,20,stdin);  //for the users input
    ch[strlen(ch)-1]=0;
   
   }
void generateName(char ch[], char ch2[])
{   
	int i=0;
	for(i=0; i<strlen(ch);i++)
	{
		if(ch[i]=='@')  //takes the name on the user's email as username
		break;
		else
		ch2[i]=ch[i];
	}
}
//*******************************************

typedef struct info infos;
 int main()
{  
     
    infos users;
    char Pasword[20],L_name[20],L_password[20],mail[20];//for testing
    int act;
    FILE *Fp;
	printf("|* Welcome to curious 17 Authentication System *|\n");
    printf("|********************MENU||********************|\n");
    printf("|                  **ENTER**                   |\n");
    printf("|      1 -To login if you are and old user     |\n");
    printf("|      2 -To register if you are a new  user   |\n");
    printf("|      0 -To Quit                              |\n");
    printf("|**********************************************|\n");
    scanf("%d",&act);
    fgetc(stdin); //consumes \n\r
    switch(act)
    {
        case 1:
        	Fp=fopen("Users.txt","r");  //creating a new text file
            printf("***********LOGIN MENU************\n");

                    printf("ENTER\n1- Login with Username \n2- Login with Email: \n ");
                    scanf("%d", &act);
                     fgetc(stdin);
                          if(act==1)
                          {
                            printf("Enter username\n");
                            //get username
                            takeinput(L_name);
                            printf("Enter you login Password\n");
                            //get password
                            TakePassword(L_password );
                            //compare if the given information matches any information in the database
                            while(fread(&users,sizeof( users),1,Fp))
                            {
                      
                            if(strcmp(L_password,users.PassWord)==0)
                            {
                              if(strcmp(L_name,users.username)==0)
                              printf("Success!!!, Welcome!");
                             }
                            else
                            printf("Invalid Username or Password!");
                          }
                            break;
                        }
                        else if(act==2){
                        
                            printf("Enter EMAIL\n");
                            //get email
                            takeinput(mail);
                            printf("Enter you login Password\n");
                            //get password
                            TakePassword(L_password );
                            //compare if the given information matches any information in the database
                            while(fread(&users,sizeof( users),1,Fp))
                            {
                      
                            if(strcmp(L_password,users.PassWord)==0)
                            {
                              if(strcmp(mail,users.email)==0)
                              printf("Success!!!, Welcome!");
                             }
                            else
                           {
						    printf("Invalid Email or Password!");
						     break;
                          }
                            
                     exit(0);
                      }
                  }
                       else
                       break;
                   
                           

        case 2:
             Fp=fopen("Users.txt","a+");
            printf("*********REGISTRATION MENU*********\n");
            printf("Enter your first name:\t");
            takeinput(users.firstname);
            printf("Enter your second name:\t");
            takeinput(users.secondname);
            printf("Enter your Email:");
            takeinput(users.email);
              //generate a username for the new user;
            generateName(users.email,users.username);
            printf("Enter your phone number:");
            takeinput(users.contact);
            
            //take password 
            printf("Enter your password:\t");
              TakePassword(users.PassWord);
             
            printf("\nConfirm your password:\t");
            TakePassword(Pasword);
            //Comparing the two passwords
            if(strcmp(Pasword,users.PassWord)==0)
            {
            	printf("Registration Complete!!\nWelcome Dear user\nYour user name is *->  %s <-*",users.username);
			}
			else
			{printf("\nPasswords did not match\nRegistration Failed!!");}
			fwrite(&users,sizeof( users),1,Fp);  //writes instance of the user's information in the system
            break;
        case 0:
        	exit(0);
        break;
        default:
         break;
    } 
    fclose(Fp);
getchar();
}
