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
#ifndef SDDS_CHEQUINGACCOUNT_H_
#define SDDS_CHEQUINGACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds
{
    class ChequingAccount : public Account
    {
        double m_tranFee;
        double m_monFee;

    public:
        ChequingAccount(double initBal, double tranFee, double monFee);
        bool credit(double cre);
        bool debit(double deb);
        void monthEnd();
        void display(std::ostream &ostr) const;
    };
}
#endif