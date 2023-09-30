/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_IACCOUNT_H_
#define SDDS_IACCOUNT_H_
#include <iostream>

namespace sdds
{
    class iAccount
    {

    public:
        virtual bool credit(double cre) = 0;
        virtual bool debit(double deb) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream &) const = 0;
        virtual ~iAccount(){};
    };
    iAccount *CreateAccount(const char *, double);
}
#endif