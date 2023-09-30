
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

int inputInt(void)
{
    int value = 0;
    char newLine = 'x';

    do
    {
        scanf(" %d%c", &value, &newLine);
        if (newLine == '\n')
        {
            return value;
        }
        else
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (newLine != '\n');
    return value;
}

int inputIntPositive(void)
{
    int value = 0, match;

    do
    {
        match = 0;
        value = inputInt();

        if (value < 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            match = 1;
            return value;
        }

    } while (!match);
    return value;

}

int inputIntRange(int lowerBound, int upperBound)
{
    int value = 0, match;

    do
    {
        match = 0;
        value = inputInt();

        if ((value < lowerBound) || (value > upperBound))
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
        else if ((value >= lowerBound) || (value <= upperBound))
        {
            match = 1;
            return value;
        }
    } while (!match);
    return value;

}

char inputCharOption(const char validChar[])
{
    //int i = 0,
    int match = 0;
    char inputChar[4] = { '\0' };
    char returnChar = '\0';

    do
    {
        scanf(" %s", inputChar);
        if (strlen(inputChar) == 1)
        {
            //printf("%c", inputChar[0]);
            //returnChar == &inputChar[0];
            //printf("%c", returnChar);
            match = 1;
            return inputChar[0];
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", validChar);
            clearInputBuffer();
        }
        /*for (i = 0; validChar[i] != '\0'; i++)
        {
            if (validChar[i] == inputChar)
            {
                //foundIndex = i;
                match = 1;
            }
        }

        if (!match)
        {
            printf("ERROR: Character must be one of [%s]: ", validChar);
            clearInputBuffer();
        }
        else
            return inputChar;*/
    } while (!match);
    return returnChar;
}

void inputCString(char checkCString[], int minNumOfChar, int maxNumOfChar)
{
    int i = 0, counter = 0, match = 0;
    char processString[9999] = { '\0' };

    do
    {
        scanf(" %[^\n]s", processString);
        counter = 0;

        /*for (i = 0; processString[i] != '\0'; i++)
        {
            counter++;
        }*/

        counter = strlen(processString);

        /*if (counter < minNumOfChar)
        {
            if (minNumOfChar == maxNumOfChar)
            {
                printf("ERROR: String length must be exactly %d chars: ", maxNumOfChar);
                clearInputBuffer();
            }
            else if (minNumOfChar != maxNumOfChar)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minNumOfChar, maxNumOfChar);
                clearInputBuffer();
            }
        }*/
        if (counter > maxNumOfChar)
        {
            if (minNumOfChar == maxNumOfChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxNumOfChar);
                clearInputBuffer();
            }
            else if (minNumOfChar != maxNumOfChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxNumOfChar);
                clearInputBuffer();
            }
        }

        //if ((counter >= minNumOfChar) && (counter <= maxNumOfChar))
        if (counter <= maxNumOfChar)
        {

            for (i = 0; i < maxNumOfChar; i++)
            {
                checkCString[i] = processString[i];
            }
            match = 1;
        }

    } while (!match);
}


void displayFormattedPhone(const char displayPhone[])
{
    int i = 0, letters = 0, digits = 0, others = 0;


    if (displayPhone == NULL)
    {
        printf("(___)___-____");
    }
    else
    {
        while (displayPhone[i] != '\0')
        {
            if ((displayPhone[i] >= 'a' && displayPhone[i] <= 'z') || (displayPhone[i] >= 'A' && displayPhone[i] <= 'Z'))
            {
                letters++;
            }
            else if (displayPhone[i] >= '0' && displayPhone[i] <= '9')
            {
                digits++;
            }
            else
            {
                others++;
            }

            i++;
        }

        if (digits == 10)
        {
            printf("(");
            for (i = 0; i < 3; i++)
            {
                printf("%c", displayPhone[i]);
            }
            printf(")");
            for (i = 3; i < 6; i++)
            {
                printf("%c", displayPhone[i]);
            }
            printf("-");
            for (i = 6; i < digits; i++)
            {
                printf("%c", displayPhone[i]);
            }
        }
        else
        {
            printf("(___)___-____");
        }
    }



}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////