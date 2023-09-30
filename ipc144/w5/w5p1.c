/*****************************************************************************
<assessment name example: Workshop - #5 (Part-1)>
Full Name : Jagraj Singh Benipal
Student ID#:156374217
Email : jbenipal1@myseneca.ca
Section :ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
int main()
{

    int month, year;

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
        else{
            printf("\n*** Log date set! ***\n");
            printf("\nLog starting date: 2022-FEB-01\n");
        }
    } while (year > MAX_YEAR || year < MIN_YEAR || month < 1 || month > 12);

    return 0;
}
