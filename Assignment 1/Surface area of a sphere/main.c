#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int length;

    // Ask the user to enter a string
    printf("Enter a string (e.g., your name): ");
    scanf("%99s", str);

    // Print the string back to the user
    printf("You entered: %s\n", str);

    // Find and display the length of the string
    length = strlen(str);
    printf("The length of the string is: %d\n", length);

    return 0;
}
