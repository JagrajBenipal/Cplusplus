/*****************************************************************************
<assessment name example: Workshop - #6 (Part-1)>
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
#define PRIORITY 3
#define FINANCE 3
#define COST 3
#define ITEM 3
int main()
{
    int items ,prior[PRIORITY];
    char fin[FINANCE];
    float income;
    double cost[COST];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    
    do{
        printf("Enter your monthly NET income: $");
        scanf("%f", &income);
        
        if (income < 500){
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (income > 400000){
        printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    }while (income < 500 || income > 400000);

    do{
    printf("\nHow many wish list items do you want to forecast?: ");
    scanf("%d", &items);
    if (items < 1 || items > 10){
        printf("ERROR: List is restricted to between 1 and 10 items.\n");
    }
    }while (items < 1 || items > 10);

    printf("\nItem-1 Details:\n");                   //first
    do{
    printf("   Item cost: $");
    scanf("%lf", &cost[0]);
    if (cost[0]<100){
    printf("      ERROR: Cost must be at least $100.00\n");
    }
    }while(cost[0] < 100);
    do{
    printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
    scanf("%d", &prior[0]);
    if (prior[0] != 1 && prior[0] != 2 && prior[0] != 3){
    printf("      ERROR: Value must be between 1 and 3\n");
    }
    }while(prior[0] !=1 && prior[0] !=2 && prior[0] !=3);
    do
    {
    printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &fin[0]);
        if (fin[0] != 'y' && fin[0] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        }
    } while (fin[0] != 'y' && fin[0] != 'n');

    printf("\nItem-2 Details:\n");               //second
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

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    printf("%3d  %5d    %5c    %11.2lf\n", 1, prior[0], fin[0], cost[0]);
    printf("%3d  %5d    %5c    %11.2lf\n", 2, prior[1], fin[1], cost[1]);
    printf("%3d  %5d    %5c    %11.2lf\n", 3, prior[2], fin[2], cost[2]);
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", cost[0] + cost[1] + cost[2]);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}