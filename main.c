/*
Project Title: Hospital Management System
Project By: MdRasen
Starting Date: 18/05/2021
End Date:
*/


//Declaring Header Files
#include <stdio.h>
#include <stdlib.h> //For system("cls"); Function
#include <string.h> //For strcmp, strcopy, strlen Functions


int age;
char Gender;
char First_Name[20];
char Last_Name[20];
char Contact_no[15];
char Address[30];
char Doctor[20];
char Problem[20];
int ok;
char ans;

//Main Function
int main()
{
    WelcomeScn();
    LoginPage();

    getch();
}


//Welcome Screen
void WelcomeScn(void)
{
    printf("\n\n\t\t\t\t\t\t****************************************************************");
    printf("\n\t\t\t\t\t\t***************|Rasen Hospital Management System|***************");
    printf("\n\t\t\t\t\t\t****************************************************************");
    printf("\n\n\n\n");

    printf("\t\t\t\tEnter any key to continue...");
    getch(); //Holds the screen for some time
}

//Login Page
void LoginPage(void)
{
    char username[25]= "MdRasen"; //Username
    char password[25] = "@Rasen"; //Password
    char input_username[25];
    char input_password[25];

    system("cls"); //For clearing the whole screen

    TitleScr(); //Function Calling

    printf("\n\n\t\t\t\tEnter Your Username and Password...\n");

    printf("\n\n\t\t\tEnter Username Here: ");
    scanf("%s", &input_username); //Takes Username
    printf("\n\t\t\tEnter Password Here: ");
    scanf("%s", &input_password); //Takes Password

    if(strcmp(username,input_username)==0)
    {
        printf("\n\n\t\t\tLogin successful...");
        getch();

        MainMenu(); //MainMenu() Function Calling
    }

    else
    {
        printf("\n\n\t\t\t****Invalid Username and Password!!****");

        printf("\n\n\t\t\t\tEnter any key to continue...");
        getch(); //Holds the screen for some time

        LoginPage(); //LoginPage() Function Calling
    }

}

//Title Screen
void TitleScr(void)
{
    printf("\n\n\t\t\t\t\t\t****************************************************************");
    printf("\n\t\t\t\t\t\t*********\t|Rasen Hospital Management System|\t********");
    printf("\n\t\t\t\t\t\t****************************************************************");
    printf("\n\n\n");
}

//Main Menu
void MainMenu(void)
{
    system("cls"); //Clear the whole screen
    TitleScr(); //TitleScr() Function Calling
    int choice;

    printf("\n\n\t\t\t\tMain Menu...\n");
    printf("\n\n\t\t\t1. Add Patients Record\n");
    printf("\n\t\t\t2. List Patients Record\n");
    printf("\n\t\t\t3. Search Patients Record\n");
    printf("\n\t\t\t4. Edit Patients Record\n");
    printf("\n\t\t\t5. Delete Patients Record\n");
    printf("\n\t\t\t6. Exit\n");
    printf("\n\n\n\t\t\tChoose from 1 to 6: ");
    scanf("%d", &choice); //Takes Choice From User

    switch(choice)
    {
    case 1:
        Add_rec(); //Add_rec() Function Calling
        break;
    case 2:
        Rec_list(); //Rec_list() Function Calling
        break;
    case 3:
        Search_rec(); //Search_rec() Function Calling
        break;
    case 4:
        Edit_rec(); //Edit_rec() Function Calling
        break;
    case 5:
        Dlt_rec(); //Dlt_rec() Function Calling
        break;
    case 6:
        Exit(); //Exit() Function Calling
        break;

    default:
        printf("\n\t\t\tInvalid entry. Please enter any key to continue :)");
        getch(); //Holds the screen for some time
        MainMenu(); //MainMenu() Function Calling
    }
}


//Add Patients Record
void Add_rec(void)
{
    system("cls");
    TitleScr();

    FILE *details;

    details = fopen("details.txt","a");

    printf("\n\n\t\t\t\tAdd Patient Records...\n");

    printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

A:
    printf("\n\t\t\tFirst Name: ");
    scanf("%s", &First_Name);
    First_Name[0]=toupper(First_Name[0]);
    if(strlen(First_Name)>20||strlen(First_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
        goto A;
    }

    /* ********************************************** Last name ************************************************ */
B:
    printf("\n\t\t\tLast Name: ");
    scanf("%s", &Last_Name);
    Last_Name[0]=toupper(Last_Name[0]);
    if(strlen(Last_Name)>20||strlen(Last_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
        goto B;
    }

    /* ******************************************* Gender ************************************************************** */
    do
    {
        printf("\n\t\t\tGender[F/M]: ");
        scanf(" %c",&Gender);
        if(toupper(Gender)=='M'|| toupper(Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
    }
    while(!ok);
    /* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge: ");
    scanf(" %i",&age);
    /* **************************************** Address ******************************************************************* */
C:
    printf("\n\t\t\tAddress: ");
    scanf("%s", &Address);
    Address[0]=toupper(Address[0]);
    if(strlen(Address)>20||strlen(Address)<4)
    {
        printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
        goto C;
    }

    /* ******************************************* Contact no. ***************************************** */
D:
    printf("\n\t\t\tContact no: ");
    scanf("%s", &Contact_no);
    if(strlen(Contact_no)>10||strlen(Contact_no)!=10)
    {
        printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
        goto D;
    }



    /* ********************************************************* Problem *********************************************** */
E:
    printf("\n\t\t\tProblem: ");
    scanf("%s", &Problem);
    Problem[0]=toupper(Problem[0]);
    if(strlen(Problem)>15||strlen(Problem)<3)
    {
        printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
        goto E;
    }

    /* ********************************************** Prescribed Doctor **************************************** */
F:
    printf("\n\t\t\tPrescribed Doctor: ");
    scanf("%s", &Doctor);
    Doctor[0]=toupper(Doctor[0]);
    if(strlen(Doctor)>30||strlen(Doctor)<3)
    {
        printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
        goto F;
    }

    fprintf(details,"\t\t\tFirst Name: %s \n\t\t\tLast Name: %s \n\t\t\tGender: %c \n\t\t\tAge: %i \n\t\t\tAddress: %s \n\t\t\tPhone: %s \n\t\t\tProblem: %s \n\t\t\tDoctor: %s\n\n\n", First_Name, Last_Name, Gender, age, Address, Contact_no, Problem, Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(details);//File is closed
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Add_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }

}

//List Patients Record
void Rec_list(void)
{
    system("cls");
    TitleScr();

    char c;
    FILE *details;
    if ((details = fopen("details.txt", "r")) == NULL)
    {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    printf("\n\n\t\t\t\tPatient Records...\n\n\n");


    while(!feof(details))
    {
        c = fgetc(details);
        printf("%c", c);
    }

    fclose(details);
}

//Search Patients Record
void Search_rec(void)
{
    system("cls");
    TitleScr();

    char name[25];
    char c;

    printf("\n\n\t\t\t\tPatient Records...\n");

    FILE *details;
    if ((details = fopen("details.txt", "r")) == NULL)
    {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    printf("\n\t\t\tEnter the name of the patient : ");
    scanf("%s", name);
    fflush(stdin);

    while(fscanf(details,"%s %s %c %i %s %s %s %s", First_Name, Last_Name, Gender, age, Address, Contact_no, Problem, Doctor)!=EOF)
    {
        printf("\n\n\t\t\t\tPatient Records...\n\n\n");


        while(!feof(details))
        {
            if(strcmp(First_Name,name)==0)
            {
                c = fgetc(details);
                printf("%c", c);
            }
        }
    }
}

//Edit Patients Record
void Edit_rec(void)
{

}

//Delete Patients Record
void Dlt_rec(void)
{

}

void Exit(void)
{

}
