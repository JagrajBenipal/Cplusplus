/*****************************************************************************
<assessment name example: Workshop - #6 (Part-2)>
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
#define PRIORITY 6
#define FINANCE 5
#define COST 6
#define ITEM 5
int main()
{
    int i,items, prior[PRIORITY];
    char fin[FINANCE];
    float income;
    double cost[COST];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%f", &income);

        if (income < 500)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (income > 400000)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    } while (income < 500 || income > 400000);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items < 1 || items > 10)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (items < 1 || items > 10);

    printf("\nItem-1 Details:\n"); // first
    do
    {
        printf("   Item cost: $");
        scanf("%lf", &cost[0]);
        if (cost[0] < 100)
        {
            printf("      ERROR: Cost must be at least $100.00\n");
        }
    } while (cost[0] < 100);
    do
    {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &prior[0]);
        if (prior[0] != 1 && prior[0] != 2 && prior[0] != 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (prior[0] != 1 && prior[0] != 2 && prior[0] != 3);
    do
    {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[0]);
        if (fin[0] != 'y' && fin[0] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[0] != 'y' && fin[0] != 'n');

    printf("\nItem-2 Details:\n"); // second
    do
    {
        printf("   Item cost: $");
        scanf("%lf", &cost[1]);
        if (cost[1] < 100)
        {
            printf("      ERROR: Cost must be at least $100.00\n");
        }
    } while (cost[1] < 100);
    do
    {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &prior[1]);
        if (prior[1] != 1 && prior[1] != 2 && prior[1] != 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (prior[1] != 1 && prior[1] != 2 && prior[1] != 3);
    do
    {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[1]);
        if (fin[1] != 'y' && fin[1] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[1] != 'y' && fin[1] != 'n');

    printf("\nItem-3 Details:\n"); // third
    do
    {
        printf("   Item cost: $");
        scanf("%lf", &cost[2]);
        if (cost[2] < 100)
        {
            printf("      ERROR: Cost must be at least $100.00\n");
        }
    } while (cost[2] < 100);
    do
    {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &prior[2]);
        if (prior[2] != 1 && prior[2] != 2 && prior[2] != 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (prior[2] != 1 && prior[2] != 2 && prior[2] != 3);
    do
    {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[2]);
        if (fin[2] != 'y' && fin[2] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[2] != 'y' && fin[2] != 'n');

    printf("\nItem-4 Details:\n"); // fourth
    do
    {
        printf("   Item cost: $");
        scanf("%lf", &cost[3]);
        if (cost[3] < 100)
        {
            printf("      ERROR: Cost must be at least $100.00\n");
        }
    } while (cost[3] < 100);
    do
    {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &prior[3]);
        if (prior[3] != 1 && prior[3] != 2 && prior[3] != 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (prior[3] != 1 && prior[3] != 2 && prior[3] != 3);
    do
    {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[3]);
        if (fin[3] != 'y' && fin[3] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[3] != 'y' && fin[3] != 'n');

    printf("\nItem-5 Details:\n"); // fifth
    do
    {
        printf("   Item cost: $");
        scanf("%lf", &cost[4]);
        if (cost[4] < 100)
        {
            printf("      ERROR: Cost must be at least $100.00\n");
        }
    } while (cost[4] < 100);
    do
    {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &prior[4]);
        if (prior[4] != 1 && prior[4] != 2 && prior[4] != 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
        }
    } while (prior[4] != 1 && prior[4] != 2 && prior[4] != 3);
    do
    {
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[4]);
        if (fin[4] != 'y' && fin[4] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[4] != 'y' && fin[4] != 'n');

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    printf("%3d  %5d    %5c    %11.2lf\n", 1, prior[0], fin[0], cost[0]);
    printf("%3d  %5d    %5c    %11.2lf\n", 2, prior[1], fin[1], cost[1]);
    printf("%3d  %5d    %5c    %11.2lf\n", 3, prior[2], fin[2], cost[2]);
    printf("%3d  %5d    %5c    %11.2lf\n", 4, prior[3], fin[3], cost[3]);
    printf("%3d  %5d    %5c    %11.2lf\n", 5, prior[4], fin[4], cost[4]);
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", cost[0] + cost[1] + cost[2] + cost[3] + cost[4]);

    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &i);
        printf("\n");
        if (i == 0)
        {
            i = 0;
        }
        else if (i == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            cost[5] = cost[0] + cost[1] + cost[2] + cost[3] + cost[4];
            printf("Amount:   $%1.2lf\n",cost[5]);

                        int year = (int)cost[5] / (int)(income * 12);
            float remain = (cost[5] / (income * 12)) - year;

            printf("Forecast: %d years, %d months\n", (int)cost[5] / (int)(income * 12), (int)(remain * 12 + 1));
            if(fin[0] || fin[1] || fin[2] || fin[3] || fin[4] == 'y'){
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");}
            printf("====================================================\n\n");
        }
        else if (i == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &prior[5]);
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", prior[5]);
            if (prior[5] == 1)
            {
            printf("Amount:   $%1.2lf\n", cost[0] + cost[3]);
            }
            if (prior[5] == 2)
            {
                printf("Amount:   $%1.2lf\n", cost[2]);
            }
            if (prior[5] == 3)
            {
                printf("Amount:   $%1.2lf\n", cost[1] + cost[4]);
            }

            if (prior[5] == 1)
            {
                int year = (int)(cost[0] + cost[3]) / (int)(income * 12);
                float remain = ((cost[0] + cost[3]) / (income * 12)) - year;

                printf("Forecast: %d years, %d months\n", (int)(cost[0] + cost[3]) / (int)(income * 12), (int)(remain * 12 + 1));
            }
            if (prior[5] == 2)
            {
                int year = (int)cost[2] / (int)(income * 12);
                float remain = (cost[2] / (income * 12)) - year;

                printf("Forecast: %d years, %d months\n", (int)cost[2] / (int)(income * 12), (int)(remain * 12 + 1));
            }
            if (prior[5] == 3)
            {
                int year = (int)(cost[1] + cost[4]) / (int)(income * 12);
                float remain = ((cost[1] + cost[4]) / (income * 12)) - year;

                printf("Forecast: %d years, %d months\n", (int)(cost[1] + cost[4]) / (int)(income * 12), (int)(remain * 12 + 1));
            }

            if ((prior[5] == 1 && (fin[0] == 'y' || fin[3] == 'y')) || (prior[5] == 2 && fin[2] == 'y') || (prior[5] == 3 && (fin[4] == 'y' || fin[1] == 'y')))
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }
        else
        {
            printf("ERROR: Invalid menu selection.\n\n");
        }
    }while (i > 0);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}