#include <stdio.h>
#include <stdlib.h>
int balance = 0;
int pin = -1;
void authenticate(int entered_pin) 
{
    if (pin == -1) 
    {
        pin = entered_pin;
        printf("PIN set successfully!\n");
    }
    else if (pin == entered_pin) 
    {
        printf("Authentication successful.\n");
    }
    else 
    {
        printf("Invalid PIN.\n");
        exit(1);
    }
}
void deposit(int amount)
{
    balance += amount;
    printf("Rs%d deposited successfully.\n", amount);
}

void withdraw(int amount) 
{
    if (balance < amount) 
    {
        printf("Insufficient funds.\n");
    }
    else 
    {
        balance -= amount;
        printf("Rs%d withdrawn successfully.\n", amount);
    }
}
void show_balance() 
{
    printf("Your balance is: Rs%d.\n", balance);
}
void change_pin(int old_pin, int new_pin) 
{
    authenticate(old_pin);
    pin = new_pin;
    printf("PIN changed successfully!\n");
}
int main() 
{
    int choice,entered_pin,amount,old_pin,new_pin;
    printf("Welcome to the ATM!\n");
    printf("Please enter your PIN: ");
    scanf("%d", &entered_pin);
    authenticate(entered_pin);
    while (1) 
    {
        printf("What would you like to do?\n");
        printf("1. Withdraw\n");
        printf("2. Deposit\n");
        printf("3. Check balance\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                withdraw(amount);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                deposit(amount);
                break;
            case 3:
                show_balance();
                break;
            case 4:
                printf("Enter your old PIN: ");
                scanf("%d", &old_pin);
                printf("Enter your new PIN: ");
                scanf("%d", &new_pin);
                change_pin(old_pin, new_pin);
                break;
            case 5:
                printf("Thank you for using the ATM!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}