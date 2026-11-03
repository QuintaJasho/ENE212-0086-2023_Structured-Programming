#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Header required for sleep() function on Linux/Windows GCC

int main()
{
    const int CORRECT_PIN = 1234; // Set predefined 4-digit PIN
    int pin;
    int attempts = 3;
    int choice;
    int authenticated = 0;

    printf("======================================\n");
    printf("    ELECTRONIC DOOR LOCK SYSTEM       \n");
    printf("======================================\n\n");

    while (attempts > 0 && !authenticated)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &pin);

        // Validate PIN length using if-else-if
        if (pin < 1000 && pin >= 0)
        {
            printf("PIN is too short (must be 4 digits)\n");
        }
        else if (pin > 9999 || pin < 0)
        {
            printf("PIN is too long (must be 4 digits)\n");
        }
        else
        {
            printf("PIN is exactly 4 digits\n");
        }

        // Validate if correct PIN was entered
        if (pin == CORRECT_PIN)
        {
            authenticated = 1;
        }
        else
        {
            attempts--;
            if (attempts > 0)
            {
                printf("Incorrect PIN! Remaining attempts: %d\n\n", attempts);
            }
        }
    }

    // If successfully authenticated, display menu options
    if (authenticated)
    {
        printf("\n--------------------------------------\n");
        printf("              SYSTEM MENU             \n");
        printf("--------------------------------------\n");
        printf("1. Unlock Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        printf("\n");
        switch (choice)
        {
            case 1:
                printf("Access granted. Door unlocked\n");
                break;
            case 2:
                printf("Change username feature coming soon.\n");
                break;
            case 3:
                printf("Change PIN feature coming soon.\n");
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    else
    {
        // System lockout logic if 3 failed attempts reached
        printf("\nIncorrect PIN entered too many times.\n");
        printf("System locked! Wait for 5 seconds...\n");

        for (int i = 5; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1); // 1-second delay
        }

        printf("You can try again now.\n");
    }

    return 0;
}
