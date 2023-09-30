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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>
#include "iAccount.h"
namespace sdds
{
    class Account : public iAccount
    {
        double m_currBal;

    public:
        Account();
        Account(double initBal);
        bool credit(double cre);
        bool debit(double deb);

    protected:
        double balance() const;
    };
}
#endif