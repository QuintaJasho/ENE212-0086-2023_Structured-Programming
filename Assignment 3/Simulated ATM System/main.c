#include <stdio.h>
#include <stdbool.h>

// Global variable or initial account balance
float balance = 1000.00; // Starting balance

// Function Prototypes
bool login();
void checkBalance();
void deposit(float amount);
void withdraw(float amount);
void showMenu();

int main()
{
    printf("===========================================\n");
    printf("         WELCOME TO THE SIMULATED ATM      \n");
    printf("===========================================\n\n");

    // Requirement 1: Login / PIN Verification
    if (!login())
    {
        printf("\nMaximum attempts exceeded. Access denied.\n");
        printf("Exiting system...\n");
        return 0; // Exit program if login fails
    }

    int choice;
    float amount;
    bool running = true;

    // Requirement 4: Repeat Until Exit
    while (running)
    {
        // Requirement 2: Show ATM Menu
        showMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        printf("\n");

        // Requirement 3: Handle User Choice
        switch (choice)
        {
            case 1:
                checkBalance();
                break;

            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(amount);
                break;

            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(amount);
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                running = false;
                break;

            default:
                printf("Invalid option! Please choose between 1 and 4.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

// Function 1: PIN Verification
bool login()
{
    const int STORED_PIN = 4321; // Stored PIN
    int enteredPIN;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == STORED_PIN)
        {
            printf("Login successful!\n");
            return true;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN. Remaining attempts: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    return false;
}

// Function 2: Show Menu
void showMenu()
{
    printf("-------------------------------------------\n");
    printf("                 ATM MENU                  \n");
    printf("-------------------------------------------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

// Function 3: Check Balance
void checkBalance()
{
    printf("Your current balance is: $%.2f\n", balance);
}

// Function 4: Deposit Money
void deposit(float amount)
{
    // Requirement 5: Validation for positive deposit amount
    if (amount <= 0)
    {
        printf("Error: Deposit amount must be a positive number.\n");
    }
    else
    {
        balance += amount;
        printf("Successfully deposited $%.2f.\n", amount);
        printf("New Balance: $%.2f\n", balance);
    }
}

// Function 5: Withdraw Money
void withdraw(float amount)
{
    // Requirement 5: Validation for positive withdrawal and sufficient balance
    if (amount <= 0)
    {
        printf("Error: Withdrawal amount must be a positive number.\n");
    }
    else if (amount > balance)
    {
        printf("Error: Insufficient funds! Your current balance is $%.2f.\n", balance);
    }
    else
    {
        balance -= amount;
        printf("Successfully withdrew $%.2f.\n", amount);
        printf("New Balance: $%.2f\n", balance);
    }
}
