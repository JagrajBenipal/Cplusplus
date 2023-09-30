/* Citation and Sources...
Final Project Milestone 2
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
#include <iostream>
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
}