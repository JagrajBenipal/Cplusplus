// Workshop 10:
// Write.h
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
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds
{
    class ReadWrite
    {
    public:
        virtual std::ostream &display(std::ostream &os) const = 0;
        virtual ~ReadWrite()
        {
        }
    };
    std::ostream &operator<<(std::ostream &os, const ReadWrite &c);
}
#endif // !SDDS_READWRITE_H_
