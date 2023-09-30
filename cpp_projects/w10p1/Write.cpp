// Workshop 10:
// Write.cpp
// 2022-02-25
// Version: 1.0
// Author: Nathan Misener
// Revised by:
/////////////////////////////////////////////

// Name: Jagraj Singh Benipal
// ID: 156374217
// Email: jbenipal1@myseneca.ca
//  Date: Aug 5 2022
// Section: ZBB
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds
{
    ostream &operator<<(ostream &os, const ReadWrite &c)
    {
        return c.display(os);
    }
}