/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.h
Version 1.0
Author	Jagraj Singh Benipal
Student ID: 156374217
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    void flush();
    int readInt(int min, int max);
    void cpStr(char *&out, const char *in);
    void readChar(std::istream &is);
    void readChar(std::istream &is, char ch);
    char *getInput(std::istream &is, char deli = '\n');
}
#endif
