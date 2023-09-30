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
#include <stdio.h>

// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lower_bound, int upper_bound);
char inputCharOption(const char valid_char[]);
void inputCString(char chr_pointer[], int min_chr, int max_chr);
void displayFormattedPhone(const char *phone);