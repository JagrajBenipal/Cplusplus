#include <stdio.h>
#include "core.h"

int my_strlen(const char *s)
{
    int counting = 0;
    while (*s != '\0')
    {
        counting++;
        s++;
    }
    return counting;
}
char *my_strcpy(char *strDest, const char *strSrc)
{
    char *temp = strDest;
    while ((*strDest++ = *strSrc++) != '\0')
        ;
    return temp;
}
void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
int inputInt(void)
{
    char newline = 'x';
    int value;
    while (newline != '\n')
    {
        scanf("%d%c", &value, &newline);
        if (newline == '\n')
        {
            break;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }

    return value;
}

int inputIntPositive(void)
{

    int value = inputInt();

    while (value <= 0)
    {
        printf("ERROR! Value must be > 0: ");
        value = inputInt();
    }

    return value;
}

int inputIntRange(int low, int high)
{
    int value = inputInt();

    while (value < low || value > high)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ", low, high);
        value = inputInt();
    }

    return value;
}

char inputCharOption(const char *valid_characters)
{
    int len = my_strlen(valid_characters);
    int i;
    char option;
    while (1)
    {
        scanf(" %c", &option);
        int flag = 0;

        for (i = 0; i < len; i++)
        {
            if (option == valid_characters[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            break;
        }

        else
        {
            printf("ERROR: Character must be one of [%s]: ", valid_characters);
        }
    }

    return option;
}

void inputCString(char *inputString, int min, int max)
{
    char tempString[100];
    while (1)
    {

        clearInputBuffer();
        scanf("%[^\n]", tempString);
        if (min == max)
        {

            if (my_strlen(tempString) != min)
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }

            else
            {
                break;
            }
        }
        else
        {

            if (my_strlen(tempString) > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }

            else if (my_strlen(tempString) < min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }

            else
            {
                break;
            }
        }
    }

    my_strcpy(inputString, tempString);
}

void displayFormattedPhone(const char *phone_no)
{

    if (phone_no == NULL)
    {
        printf("(___)___-____");
        return;
    }
    int i = 0;
    int count = 0;
    int len = my_strlen(phone_no);
    for (i = 0; i < len; i++)
    {
        if (phone_no[i] >= '0' && phone_no[i] <= '9')
        {
            count++;
        }
    }

    if (len != 10 || len != count)
    {
        printf("(___)___-____");
    }
    else
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
               phone_no[0],
               phone_no[1],
               phone_no[2],
               phone_no[3],
               phone_no[4],
               phone_no[5],
               phone_no[6],
               phone_no[7],
               phone_no[8],
               phone_no[9]);
    }
}