#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char ch[10][130] = {"MOTOR COACH", "SHUTTLE SOLUTIONS", "TRANSIT TITANS", "COACH CONNECTIONS", "SINGLE DECKER", "JOURNEY JOURNEY"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32];
int trno;
void login(); // for login the program
void bus();   // for list of bus
void name_number(int booking, char numstr[100]);
void booking();            // for booking the tickets
int read_number(int trno); // for reading the number from the file
void read_name(int trno);  // for reading the name from the file
void status();             // for printing the status by user input
void status_1(int trno);   // for printing the status while booking ticket
void cancle();

int main()
{

    login();
    int num, i;
    do
    {

        system("CLS");
        printf("\n\n.................WELCOME TO BUS RESERVATION SYSTEM CREATED BY HARSHIT.....................\n\n");

        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancle Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            bus(); // for list of bus
            break;
        case 2:
            booking(); // for booking the tickets
            break;
        case 3:
            cancle(); // for cancel the tickets
            break;
        case 4:
            status(); // for status of board `
            break;
        }
        getch();
    } while (num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This Program\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}

void bus()
{
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n", ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n", ch[1]);
    printf("\n");
    printf("\t\t\t\t\t[3]  =>  %s\n", ch[2]);
    printf("\n");
    printf("\t\t\t\t\t[4]  =>  %s\n", ch[3]);
    printf("\n");
    printf("\t\t\t\t\t[5]  =>  %s\n", ch[4]);
}

void booking()
{

    int i = 0;
    char numstr[100];
    system("cls");
    printf("\n\n");
    bus(); // ############################################                                                                                                                        // for seeing train least
    printf("\nEnter the Bus number:--->");
    scanf("%d", &trno); // choose your bus
    system("cls");

    status_1(trno); // ##########

    FILE *f1, *fopen(); // for reading the seats from the user.
    char str1[80] = "32", str2[4], str3[4];
    int seat1, seat2, booking = 0;
    if (trno == 1)
    {
        f1 = fopen("tr1.txt", "r+");
        fgets(str1, 80, f1); // at first run 32 will be stored in tr1.txt file in motor coach.
        fclose(f1);
    }
    else if (trno == 2)
    {
        f1 = fopen("tr2.txt", "r+"); // at first run 32 will be stored in tr1.txt shuttle solutions.
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 3)
    {
        f1 = fopen("tr3.txt", "r+"); // similarly
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 4)
    {
        f1 = fopen("tr4.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (trno == 5)
    {
        f1 = fopen("tr5.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }

    seat1 = atoi(str1); // covert the string into number AT first it seat1 stored 32 as an integer value

    if (seat1 <= 0)
    {
        printf("There is no blank seat in this bus ");
    }
    else
    {
        printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1); // At Intially seat1=32
        printf("\n\t\t\t\tNumber of Tickets:----->");
        scanf("%d", &booking);
        printf("\n");

        seat1 = seat1 - booking;
        // Now --> seat1=32-1=31
        itoa(trno, numstr, 10);
        // 1 in numstr in booking function
        name_number(booking, numstr); // ######
        // name_number(1, 1 in string of 100 length); // #####
        printf("\n\t\t\t\tThe Total booking amount is %d\n\n", 200 * booking);

        itoa(seat1, str1, 10); // ######
        //  Now 31 is stored in str1 if you book one ticket.
        // for reading the seats from the user.
        if (trno == 1)
        {
            f1 = fopen("tr1.txt", "w"); // In tr1.txt file 31 is stored
            fputs(str1, f1);            // 31 in str1
            fclose(f1);
        }
        else if (trno == 2)
        {
            f1 = fopen("tr2.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (trno == 3)
        {
            f1 = fopen("tr3.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (trno == 4)
        {
            f1 = fopen("tr4.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (trno == 5)
        {
            f1 = fopen("tr5.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
    }
}

void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int seatnumber;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);     // status1.txt  --> it stored the person name.
    strcat(tempstr2, numstr);     // number1.txt  --> it stored the seat number.
    a = fopen(tempstr1, "a");     // for open the file to write the name in the file status1.txt
    b = fopen(tempstr2, "a");     // for open the file for writing the number in the file number1.txt
    for (i = 0; i < booking; i++) // for entering the person name and seat number in the file
    {
        printf("========================Enter the details for ticket no %d ============================\n\n\n", i + 1);
        printf("\t\t\t\tEnter the seat number:--->");
        scanf("%d", &seatnumber); // #############
        printf("\t\t\t\tEnter the name of person:--->");
        scanf("%s", name[seatnumber - 1]); // char name[32][100]
        printf("\n======================================================================================================\n\n");
        printf("\n");
        itoa(seatnumber, tempstr, 10);           // it stored 1 in tempstr string
        fprintf(a, "%s ", name[seatnumber - 1]); // person name  in status1.txt file.
        fprintf(b, "%s ", tempstr);              // any seat number  in number1.txt file.
    }
    fclose(a);
    fclose(b);
}

int read_number(int trno) // for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(trno, numstr, 10);
    // printf("%s\n", numstr);
    // 1
    strcat(numstr, ".txt");
    // 1.txt
    strcat(tempstr2, numstr);
    // printf("%s\n", tempstr2);
    //  number1.txt
    a = fopen(tempstr2, "a+"); // for open the file to write the name in the file

    while (!feof(a))
    {
        number[i][j] = fgetc(a); // char number[32][2]
        if (number[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;

    for (i = 0; i < k; i++) // at first it doesn't work
    {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}

void read_name(int trno) // for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    // 1
    strcat(numstr, ".txt");
    // printf("%s",numstr);
    // 1.txt
    strcat(tempstr1, numstr);
    // status1.txt
    b = fopen(tempstr1, "a+"); // for open the file to write the name in the file
    while (!feof(b))
    {
        name[i][j] = fgetc(b);
        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    bus();
    int i, trno, index = 0, j;
    printf("Enter the number of bus:---->");
    scanf("%d", &trno);
    j = read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s     \n", trno, ch[trno - 1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void status_1(int trno)
{
    system("cls");
    printf("\nYour Bus Number is %d ", trno);
    printf("and you choose %s Bus \n\n", ch[trno - 1]);
    // printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, j, index = 0;
    j = read_number(trno); // j=0 at first run if you book one ticket //j=1 at second run if you book one ticket.
    read_name(trno);       // at second run it on i=1=k if you book one ticket.
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++) // j=1
    {
        strcpy(tempname[num1[i]], name[i]); // int num1[32],char name[32][100]
                                            //  strcpy(tempname[0],harshit)
    }                                       //     strcpy (target,source)

    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);

            index++;
        }
        printf("\n");
    }
}

void cancle()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    bus();
    printf("Enter your bus number\n:---->");
    scanf("%d", &trno);
    itoa(trno, numstr, 10);
    // 1 in numstr
    strcat(numstr, ".txt");
    // 1.txt file
    strcat(tempstr1, numstr);
    // status1.txt file
    strcat(tempstr2, numstr);
    // number1.txt file
    read_number(trno);
    read_name(trno);
    status_1(trno);
    printf("Enter the seat number you want to cancel:--->");
    scanf("%d", &seat_no);
    FILE *a, *b;
    a = fopen(tempstr1, "w+"); // a points to status1.txt file
    b = fopen(tempstr2, "w+"); // b points to number1.txt file
    for (i = 0; i < 32; i++)
    {
        if (num1[i] == seat_no)
        {
            for (j = 0; j < 32; j++)
            {
                if (num1[j] != seat_no && num1[j] != 0)
                {
                    fprintf(b, "%d ", num1[j]);
                    fprintf(a, "%s", name[j]);
                }
                else if (num1[j] == seat_no && num1[j] != 0)
                {
                    strcpy(name[j], "Empty ");
                }
            }
        }
    }
    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}

void login()
{
    int a = 0;
    int i;
    char uname[10];
    char user[10] = "user";
    char pword[10], code[10];
    char pass[10] = "pass";

    do
    {
        printf("\n  =========================  log FORM  =========================  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", uname);
        printf(" \n                        ENTER PASSWORD:-");

        for (i = 0; i < 4; i++)
        {

            // Get the hidden input using getch() method
            pword[i] = getch();

            printf("*"); // Print * to show that a character is entered.
        }

        pword[i] = '\0';

        if (strcmp(uname, "user") == 0)
        {
            if (strcmp(pword, "pass") == 0)

            {
                printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
                printf("\n\n\n\t\t\t\tPress any key to continue...\n\n");
                getch(); // holds the screen
                break;
            }
            else
            {
                printf("\n WRONG PASSWORD  ENTER ANY KEY TO CoNTINUE \n");
                printf("ENTER ANY KEY TO CONTINUE...\n:");
                getch(); // holds the screen
                a++;
            }
        }
        else
        {
            printf("\n      SORRY !!!! YOU ENTERED WRONG USERNAME \n try again:");
            printf("\n      ENTER ANY KEY TO CONTINUE \n:");
            getch(); // holds the screen
            a++;
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
};