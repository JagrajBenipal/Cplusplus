/********************************************************************
Workshop 4 Part 2
Name: Jagraj Singh Benipal
Student ID : 156374217
Email:  I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************/

#include <iostream>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

int main()
{
        const int num_bots = 8;
        CleanerBot bot[num_bots] = {
                {},
                {"library", 82.5, 7, false},
                {"corridor", 75, 3, true},
                {"pantry", 23.6, 12, false},
                {"parking", 30.1, 9, true},
                {"storage", 57, 2, true},
                {"?", -1, 1, false},
                {"basement", 29.9, 1, true}
        };

        report(bot, num_bots);

        return 0;
}