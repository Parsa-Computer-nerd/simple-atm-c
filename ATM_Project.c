#include <stdio.h>
#include <string.h>
int main()
{
    int password, count, login = 0, Program = 1, menu, oldpassword, newpassword, i;
    float amount;
    char Question;
    char firstName[20];
    char lastName[20];
    float balance = 0;
    int pin = 1234;
    int accountActive = 0;
    float transactionHistory[10];
    int transactionCount = 0;

    for (count = 1; count <= 3; count++)
    {
        printf("Enter Password: ");
        scanf("%d", &password);
        if (password == 1234)
        {
            printf("Successful.\n\n");
            login = 1;
            break;
        }
        else
        {
            printf("The password is incorrect.\n");
            login = 0;
        }
    }

    if (login == 0)
    {
        printf("You entered the password incorrectly three times.\n");
    }

    if (login == 1)
    {
        while (Program == 1) // منو
        {
            printf("1.Create account\n\n");
            printf("2.Deposit\n\n");
            printf("3.Withdraw\n\n");
            printf("4.Exit\n\n");
            printf("5.Change PIN\n\n");
            printf("6.Transaction history\n\n");
            printf("7.View Balance\n\n");

            printf("Enter number of menu: ");
            scanf("%d", &menu);

            switch (menu)
            {
            case 1:
                if (accountActive == 0)
                {
                    printf("Please enter your firstname: ");
                    scanf(" %s", firstName);

                    printf("Please enter your lastname: ");
                    scanf(" %s", lastName);

                    printf("Please enter your balance: ");
                    scanf(" %f", &balance);

                    accountActive = 1;

                    transactionCount = 0;
                }
                break;
            case 2:

                if (accountActive == 1)
                {
                    printf("Enter amount: ");
                    scanf("%f", &amount);

                    if (amount > 0)
                    {
                        balance += amount;
                        transactionHistory[transactionCount % 10] = amount; // این خط، مبلغ واریزی را به‌صورت مثبت، در تاریخچه ۱۰ تراکنش آخر ذخیره می‌کند.
                        transactionCount++;
                        printf("Successful.\n\n");
                    }
                    else
                    {
                        printf("Invalid amount!\n");
                    }
                }
                else
                {
                    printf("First create an account.\n");
                }
                break;
            case 3:
                if (accountActive == 1)
                {
                    printf("Enter amount: ");
                    scanf("%f", &amount);

                    if (amount > 0)
                    {
                        if (balance >= amount)
                        {
                            balance -= amount;
                            transactionHistory[transactionCount % 10] = -amount; //مقدار برداشت شده را به‌صورت منفی،در تاریخچه ۱۰ تراکنش آخر ذخیره می‌کند.
                            transactionCount++;
                            printf("Successful.\n\n");
                        }
                        else
                        {
                            printf("Not enough balance.");
                        }
                    }
                    else
                    {
                        printf("Invalid amount!\n");
                    }
                }
                else
                {
                    printf("First create an account.\n");
                }
                break;
            case 4:
                printf("Are you sure about your exit? [y/n]: ");
                scanf(" %c", &Question);
                if (Question == 'y' || Question == 'Y')
                {
                    printf("Goodbye! See you next time.\n");
                    Program = 0;
                    break;
                }
                else if (Question == 'n' || Question == 'N')
                {
                    Program = 1;
                }
                else
                {
                    printf("Returning to menu ...\n\n");
                    Program = 1;
                }
                break;
            case 5:
                printf("Enter current PIN: ");
                scanf("%d", &oldpassword);

                if (oldpassword == pin)
                {
                    printf("Enter new PIN: ");
                    scanf("%d", &newpassword);
                    pin = newpassword;
                    printf("PIN changed successfully.\n");
                }
                else
                {
                    printf("Wrong PIN.\n");
                }
                break;
            case 6:
                if (transactionCount == 0)
                {
                    printf("No transactions yet.\n");
                }
                else
                {
                    printf("Transaction History:\n");
                    for (i = 0; i < transactionCount && i < 10; i++)
                    {
                        if (transactionHistory[i] > 0)
                            printf("Deposit: +%.3f\n", transactionHistory[i]); // نشان دادن تراکنش ها به صورت مثبت (واریز)
                        else
                            printf("Withdraw: %.3f\n", transactionHistory[i]); // نشان دادن تراکنش ها به صورت منفی (برداشت)
                    }
                }
                break;
            case 7:
                if (accountActive == 1)
                {
                    printf("Current balance: %.3f\n", balance);
                }
                else
                {
                    printf("First create an account.\n");
                }
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}


