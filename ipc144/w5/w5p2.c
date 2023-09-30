/*****************************************************************************
<assessment name example: Workshop - #5 (Part-2)>
Full Name : Jagraj Singh Benipal
Student ID#:156374217
Email : jbenipal1@myseneca.ca
Section :ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
int main(void)
{

    int month, year;
    double r1, r2, r3, R1, R2, R3;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if ((year < MIN_YEAR || year > MAX_YEAR) && (month >= 1 && month <= 12))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month < 1 || month > 12))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if ((year < MIN_YEAR || year > MAX_YEAR) && (month < 1 || month > 12))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else
        {
            printf("\n*** Log date set! ***\n\n");
        }
    } while (year > MAX_YEAR || year < MIN_YEAR || month < 1 || month > 12);

    printf("2022-FEB-01\n");
    for (;;)
    {
        printf("   Morning rating (0.0-5.0): ");
        scanf(" %lf", &r1);
        if (r1 < 0.0 || r1 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (r1 <= 5.0 && r1 >= 0.0)
        {
            break;
        }
    }
    for (;;)
    {
        printf("   Evening rating (0.0-5.0): ");
        scanf(" %lf", &R1);
        if (R1 < 0.0 || R1 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (R1 <= 5.0 && R1 >= 0.0)
        {
            break;
        }
    }

    printf("\n2022-FEB-02\n");
    for (;;)
    {
        printf("   Morning rating (0.0-5.0): ");
        scanf(" %lf", &r2);
        if (r2 < 0.0 || r2 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (r2 <= 5.0 && r2 >= 0.0)
        {
            break;
        }
    }
    for (;;)
    {
        printf("   Evening rating (0.0-5.0): ");
        scanf(" %lf", &R2);
        if (R2 < 0.0 || R2 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (R2 <= 5.0 && R2 >= 0.0)
        {
            break;
        }
    }

    printf("\n2022-FEB-03\n");
    for (;;)
    {
        printf("   Morning rating (0.0-5.0): ");
        scanf(" %lf", &r3);
        if (r3 < 0.0 || r3 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (r3 <= 5.0 && r3 >= 0.0)
        {
            break;
        }
    }
    for (;;)
    {
        printf("   Evening rating (0.0-5.0): ");
        scanf(" %lf", &R3);
        if (R3 < 0.0 || R3 > 5.0)
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
        }
        else if (R3 <= 5.0 && R3 >= 0.0)
        {
            break;
        }
    }

    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", r1 + r2 + r3);
    printf("Evening total rating:  %.3lf\n", R1 + R2 + R3);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", r1 + r2 + r3 + R1 + R2 + R3);

    printf("Average morning rating:  %0.1lf\n", (r1 + r2 + r3) / 3);
    printf("Average evening rating:  %0.1lf\n", (R1 + R2 + R3) / 3);
    printf("----------------------------\n");
    printf("Average overall rating:  %0.1lf\n", (r1 + r2 + r3 + R1 + R2 + R3) / 6);

    return 0;
}