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
#ifndef SDDS_SAVINGSACCOUNT_H_
#define SDDS_SAVINGSACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds
{
    class SavingsAccount : public Account
    {
        double m_interestRate;

    public:
        SavingsAccount(double initBal, double interest);
        void monthEnd();
        void display(std::ostream &ostr) const;
    };
}
#endif