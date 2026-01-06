#include <stdio.h>
int main()
{
    char name[30];
    char family_name[30];
    int balance = 0;
    int pin = 1234;
    int enterpin;
    int Entred = 0;
    int choice = 0;
    int active = 0;
    int history[10];
    int historycount;
    printf("Enter pin:");
    while (1)
    {
        scanf("%d", &enterpin);
        if (enterpin == pin)
        {
            break;
        }
        Entred++;
        if (Entred == 3)
        {
            printf("Too many wrong entries . The program ended.\n");
            printf("6.Exit:");
            scanf("%d", &choice);
            if (choice == 6)
            {
                printf("good bye");
                return 0;
            }
            else
            {
                return 0;
            }
        }
        printf("wrong pin.try again:");
    }
    while (1)
    {
        printf("\n**** ATM Menu ****\n");
        printf("1.create account\n");
        printf("2.deposit\n");
        printf("3.withdraw\n");
        printf("4.check balance\n");
        printf("5.change pin\n");
        printf("6.show Transaction History\n");
        printf("7.exite\n");
        printf("choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (active == 1)
            {
                printf("Account exists:");
            }
            else
            {
                printf("Enter name:");
                scanf("%s", name);
                printf("Enter family_name:");
                scanf("%s", family_name);
                printf("Enter balance:");
                scanf("%d", &balance);
                active = 1;
                historycount = 0;
                for (int i = 0; i < 10; i++)
                    history[i] = 0;
                printf("Account created successfully");
            }
        }
        else if (choice == 2)
        {
            if (active == 0)
            {
                printf("Account not found");
            }
            else
            {
                int amount;
                printf("Enter deposit amount:");
                scanf("%d", &amount);
                if (amount > 0)
                {
                    balance += amount;
                    if (historycount < 10)
                        history[historycount++] = amount;
                    else
                    {
                        for (int i = 0; i < 9; i++)
                            history[i] = history[i + 1];
                        history[9] = amount;
                    }
                    printf("Deposit successful.\n");
                }
                else
                {
                    printf("Invalid amount.\n");
                }
            }
        }
        else if (choice == 3)
        {
            if (active == 0)
            {
                printf("Account not found");
            }
            else
            {
                int amount;
                printf("Enter Withdraw amount:");
                scanf("%d", &amount);
                if (amount <= 0)
                    printf("Invalid amount.\n");
                else if (amount > balance)
                    printf("Not enough balance");
                else
                {
                    balance -= amount;
                    if (historycount < 10)
                        history[historycount++] = -amount;
                    else
                    {
                        for (int i = 0; i < 9; i++)
                            history[i] = history[i + 1];
                        history[9] = -amount;
                    }
                    printf("withdraw successful.\n");
                }
            }
        }
        else if (choice == 4)
        {
            if (active == 0)
                printf("Account not found.\n");
            else
                printf("curent Balance:%d\n", balance);
        }
        else if (choice == 5)
        {
            int oldpin, newpin;
            printf("Enter current pin:");
            scanf("%d", &oldpin);
            if (oldpin == pin)
            {
                printf("Enter new pin:");
                scanf("%d", &newpin);
                pin = newpin;
                printf("Pin changed successfully.\n");
            }
            else
            {
                printf("Wrong Pin.\n");
            }
        }
        else if (choice == 6)
        {
            if (active == 0)
            {
                printf("Account not found.\n");
            }
            else if (historycount == 0)
            {
                printf("No transactions yet.\n");
            }
            else
            {
                printf("Last Transactions:\n");
                for (int i = 0; i < historycount; i++)
                {
                    if (history[i] > 0)
                        printf("%d:Deposit %d\n", i + 1, history[i]);
                    else
                        printf("%d:Withdraw %d\n", i + 1, -history[i]);
                }
            }
        }
        else if (choice == 7)
        {
            int confirm;
            printf("Are you sure you want to exit? (Yes = 1 , No = 0)");
            scanf("%d", &confirm);
            if (confirm == 1)
            {
                printf("Goodbye.\n");
                return 0;
            }
            else
            {
                printf("Exit canceled.\n");
            }
        }
    }
    return 0;
}