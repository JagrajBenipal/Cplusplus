/* Citation and Sources...
Final Project Milestone 3
Module: Utils
Filename: Utils.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
using namespace std;
#include "Utils.h"
namespace sdds
{
    void flush()
    {
        while (cin.get() != '\n')
            ;
    }
    int readInt(int min, int max)
    {
        int value = 0;
        bool done = false;
        while (!done)
        {
            cin >> value;
            if (!cin)
            {
                cin.clear();
                cout << "Invalid Selection, try again: ";
            }
            else
            {
                if (value >= min && value <= max)
                {
                    done = true;
                }
                else
                {
                    cout << "Invalid Selection, try again: ";
                }
            }
            flush();
        }
        return value;
    }

    void cpStr(char *&out, const char *in)
    {
        delete[] out;
        out = new char[strlen(in) + 1];
        strcpy(out, in);
    }

    void readChar(istream &is)
    {
        if (isdigit(is.peek()))
        {
            is.setstate(std::ios::failbit);
        }
        else
        {
            is.get();
        }
    }

    void readChar(istream &is, char ch)
    {
        if (is.peek() == ch)
            is.get();
    }

    char *getInput(istream &is, char deli)
    {
        string tmpRead;
        char *tempC{};
        getline(is, tmpRead, deli);
        if (is)
        {
            tempC = new char[strlen(tmpRead.c_str()) + 1];
            strcpy(tempC, tmpRead.c_str());
        }
        return tempC;
    }
}