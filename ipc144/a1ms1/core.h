#ifndef CORE_H_
#define CORE_H_


int my_strlen(const char *s);
char *my_strcpy(char *strDest, const char *strSrc);
// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for the user to input the "enter" key to continue
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lower_limit, int upper_limit);
char inputCharOption(const char *valid_characters);
void inputCString(char *inputString, int minLen, int maxLen);
void displayFormattedPhone(const char *phone_number);

#endif /* CORE_H_ */