#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct create_an_account
{
    char email[20];
    char number[10];
    char password[8];
} cre;

void create(cre *arr)
{
    cre *temp = arr;
    printf("Enter a new email:\n");
    gets(temp->email);
    printf("\nEnter your Password(8 digits):\n");
    for (int i = 0; i < 8; i++)
    {
        *(temp->password) = getch();
        printf("*");
        temp++;
    }
    *(temp->password) = '\0';
    printf("\n");
    printf("\nEnter your mobile number(10 digits):\n");
    gets(temp->number);
    printf("\n");
    printf("Account successfully created!!!");
    printf("\n");
}
void show(cre *arr, FILE *ptr1)
{
    cre *temp1 = arr;
    int num, numb;
    int number = rand();

    ptr1 = fopen("code.txt", "w");
    fprintf(ptr1, "%d", number);
    fclose(ptr1);
    ptr1 = fopen("code.txt", "r");
    fscanf(ptr1, "%d", &num);
    fclose(ptr1);
    printf("Enter the code sent to your mobile number to see information details:\n");
    scanf("%d", &numb);
    if (num == numb)
    {
        printf("*************************************************************************\n");
        printf("\nEntered Information:\n\n");
        printf("Email:\n");
        puts(temp1->email);
        printf("\nPassword:\n");
        for (int i = 0; *(temp1->password) != '\0'; i++)
        {
            printf("%c", *(temp1->password));
            temp1++;
        }
        printf("\n");
        printf("\nYour Number:\n");
        puts(temp1->number);
        printf("\n********************************************************************\n");
    }
    else
    {
        printf("Get Lost\n");
        exit(0);
    }
}

void change(cre *ptr, FILE *ptr1)
{
    cre *temp2 = ptr;
    ptr1 = fopen("code.txt", "w");
    int number = rand();
    fprintf(ptr1, "%d", number);
    fclose(ptr1);
    ptr1 = fopen("code.txt", "r");
    int numb;
    fscanf(ptr1, "%d", &numb);
    fclose(ptr1);
    printf("Enter the code sent to your mobile number\n");
    int num;
    scanf("%d", &num);
    if (num == numb)
    {
        printf("\nEnter your new Password(8 digits):\n");
        for (int i = 0; i < 8; i++)
        {
            *(temp2->password) = getch();
            printf("*");
            temp2++;
        }
        *(temp2->password) = '\0';
        printf("\n");
        show(ptr, ptr1);
    }
    else
    {
        printf("Incorrect pin!");
        exit(0);
    }
    printf("Do you want to change your password again?(y/n)\n");
    char q;
    fflush(stdin);
    scanf("%c", &q);
    if (q == 'n')
    {
        printf("Thankyou for using the program!");
    }
    else
    {
        change(ptr, ptr1);
    }
}

int main()
{
    srand(time(0));
    FILE *ptr1;

    printf("***************Create an Account****************\n");

    cre pinky;
    cre *ptr = &pinky;
    create(ptr);
    show(ptr, ptr1);

    char q;
    printf("Do you want to change your password?(y/n)\n");
    fflush(stdin);
    scanf("%c", &q);
    if (q == 'y')
    {
        change(ptr, ptr1);
    }
    else
    {
        printf("Thankyou for using the program!");
    }
    return 0;
}