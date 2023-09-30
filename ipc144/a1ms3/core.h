
// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #2 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//checking for an positive integer input
int inputIntPositive(void);

//checking the input integer is within range
int inputIntRange(int lowerBound, int upperBound);

//check a single character is entered within the list of valid characters
char inputCharOption(const char validChar[]);

//Cstring value is entered containing the number of characters within the range specified
void inputCString(char checkCString[], int minNumOfChar, int maxNumOfChar);

//Display the formatted phone number
void displayFormattedPhone(const char displayPhone[]);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////




// !!! DO NOT DELETE THE BELOW LINE !!!
#endif //