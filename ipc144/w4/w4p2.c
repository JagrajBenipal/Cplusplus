/******************************************************************************
<assessment name example: Workshop - #4 (Part-2)>
Full Name : Jagraj Singh Benipal
Student ID#: 156374217
Email : jbenipal1@myseneca.ca
Section : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
    int
    main()
{

    int apples, oranges, pears, tomatoes, cabbages;
    int APPLES, PEARS, CABBAGES, ORANGES, TOMATOES;
    int again, no;

    
    printf("Grocery Shopping\n");
    printf("================\n");

    do{
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
         
         if (apples <0){
             printf("ERROR: Value must be 0 or more.\n");
         }
    }while (apples < 0);


    printf("\n");
    do{
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        if (oranges < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    }while (oranges < 0);


    printf("\n");
    do{
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        if (pears<0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    }while (pears < 0);


    printf("\n");
    do{
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        if (tomatoes <0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    }while (tomatoes < 0);


    printf("\n");
    do
    {
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        if (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (cabbages < 0);

    printf("\n--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    do
    {
        printf("Pick some APPLES... how many did you pick? : "); 
        scanf("%d", &APPLES);                                    
        if (APPLES > apples)                                          
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
        }
        else if (APPLES < 1) 
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if (APPLES < apples) 
        {
            printf("Looks like we still need some APPLES...\n");
            apples -= APPLES;
        }
        else
        {
            printf("Great, that's the apples done!\n\n"); 
            apples -= APPLES;
        }
    } while (apples > 0);



    do
    {
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d", &PEARS);
        if (PEARS > pears)
        {
            printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
        }
        else if (PEARS < 1)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if (PEARS < pears)
        {
            printf("Looks like we still need some PEARS...\n");
            pears -= PEARS;
        }
        else    
        {
            printf("Great, that's the pears done!\n\n");
            pears -= PEARS;
        }
    } while (pears > 0);

    do
    {
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf("%d", &CABBAGES);
        if (CABBAGES > cabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
        }
        else if (CABBAGES < 1)
        {
            printf("ERROR: You must pick at least 1!\n");
        }
        else if (CABBAGES < cabbages)
        {
            printf("Looks like we still need some CABBAGES...\n");
            cabbages -= CABBAGES;
        }
        else
        {
            printf("Great, that's the cabbages done!\n\n");
            cabbages -= CABBAGES;
        }
    } while (cabbages > 0);

    printf("All the items are picked!\n\n");

    printf("Do another shopping? (0=NO): ");
    scanf("%d", &again);
    if (again == 0){
        printf("Your tasks are done for today - enjoy your free time!\n");
    }
    else{

        do
        {
            printf("\nGrocery Shopping\n");
            printf("================\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);

        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);

        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);

        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);

        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        do
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &ORANGES);
            if (ORANGES > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
            else if (ORANGES < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (ORANGES < oranges)
            {
                printf("Looks like we still need some ORANGES...\n");
                oranges -= ORANGES;
            }
            else
            {
                printf("Great, that's the oranges done!\n\n");
                oranges -= ORANGES;
            }
        } while (oranges > 0);



        do
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &TOMATOES);
            if (TOMATOES > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            }
            else if (TOMATOES < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (TOMATOES < tomatoes)
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoes -= TOMATOES;
            }
            else
            {
                printf("Great, that's the tomatoes done!\n\n");
                tomatoes -= TOMATOES;
            }
        } while (tomatoes > 0);

        printf("All the items are picked!\n\n");
    }
    printf("Do another shopping? (0=NO): ");
    scanf("%d", &no);

    printf("\nYour tasks are done for today - enjoy your free time!\n");
        return 0;
}