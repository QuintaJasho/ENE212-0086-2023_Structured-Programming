#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    char regNum[30];
    char name[50];
    float marks;
    char grade;

    printf("===========================================\n");
    printf("    STUDENT GRADING SYSTEM (SWITCH-CASE)   \n");
    printf("===========================================\n\n");

    printf("Enter the number of students: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        printf("\n-------------------------------------------\n");
        printf("Entering details for Student %d of %d\n", i, N);
        printf("-------------------------------------------\n");

        printf("Enter Registration Number: ");
        scanf("%s", regNum);

        printf("Enter Student Name: ");
        scanf(" %[^\n]s", name);

        printf("Enter Marks (0-100): ");
        scanf("%f", &marks);

        // Grade determination using switch-case with integer division
        switch ((int)marks / 10)
        {
            case 10:
            case 9:
            case 8:
            case 7:
                grade = 'A';
                break;
            case 6:
                grade = 'B';
                break;
            case 5:
                grade = 'C';
                break;
            case 4:
                grade = 'D';
                break;
            default:
                grade = 'F';
                break;
        }

        // Display formatted report card
        printf("\n========== STUDENT RESULT ==========\n");
        printf("Reg Number : %s\n", regNum);
        printf("Name       : %s\n", name);
        printf("Marks      : %.2f\n", marks);
        printf("Grade      : %c\n", grade);

        // Pass/Fail check
        if (marks >= 40)
        {
            printf("Status     : PASSED\n");
        }
        else
        {
            printf("Status     : FAILED\n");
        }
        printf("====================================\n");
    }

    return 0;
}
