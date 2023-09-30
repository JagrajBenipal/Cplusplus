/*
*********
                        Assignment 1 - Milestone 2
Full Name  : jagraj singh benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*********
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "core.h"

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
int inputInt(void)
{
    int num = 0;
    char new_line = 0;
    while (new_line != '\n')
    {
        scanf("%d%c", &num, &new_line);
        if (new_line != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return num;
}
int inputIntPositive(void)
{
    int count = 1;
    int int_pos = 0;
    while (count)
    {
        int_pos = inputInt();
        if (int_pos <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            count = 0;
        }
    }
    return int_pos;
}
int inputIntRange(int lower_bound, int upper_bound)
{
    int rng = 0;
    int count = 1;
    while (count)
    {
        rng = inputInt();
        if (rng < lower_bound || rng > upper_bound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
        }
        else
        {
            count = 0;
        }
    }
    return rng;
}
char inputCharOption(const char valid_char[])
{
    char chr1;
    int i = 0;
    int count = 1;
    int values = 0;
    char chr2;
    for (i = 0; valid_char[i] != '\0'; i++)
    {
        values++;
    }
    while (count)
    {
        scanf("%c%c", &chr1, &chr2);
        if (chr2 == '\n')
        {
            for (i = 0; i < values && count; i++)
            {
                if (chr1 == valid_char[i])
                {
                    count = 0;
                }
            }
            if (count)
            {
                printf("ERROR: Character must be one of [%s]: ", valid_char);
            }
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", valid_char);
            clearInputBuffer();
        }
    }
    return chr1;
}
void inputCString(char chr_pointer[], int min_chr, int max_chr)
{
    int i = 0, j = 0;
    int val = 0;
    int count = 1;
    char cstring[500];
    do
    {
        scanf("%500[^\n]", cstring);
        clearInputBuffer();
        val = 0;
        for (i = 0; cstring[i] != '\0'; i++)
        {
            val++;
        }
        if (val < min_chr && (min_chr != max_chr))
        {
            printf("ERROR: String length must be between %d and %d chars: ", min_chr, max_chr);
        }
        else if (val > max_chr && (min_chr != max_chr))
        {
            printf("ERROR: String length must be no more than %d chars: ", max_chr);
        }
        else if ((val < min_chr || val > max_chr) && min_chr == max_chr)
        {
            printf("ERROR: String length must be exactly %d chars: ", max_chr);
        }
        else
        {
            for (j = 0; j < val + 1; j++)
            {
                chr_pointer[j] = cstring[j];
            }
            count = 0;
        }
    } while (count);
}
void displayFormattedPhone(const char *phone)
{
    int isValid = 1;
    int i = 0;
    if (phone != NULL)
    {
        for (i = 0; phone[i] && isValid; i++)
        {

            if (phone[i] < 48 || phone[i] > 57)
            {
                isValid = 0;
            }
        }
    }
    if (isValid && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", phone[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", phone[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", phone[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}