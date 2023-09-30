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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "SavingsAccount.h"
#include "Account.h"
using namespace std;
namespace sdds
{
    SavingsAccount::SavingsAccount(double initBal, double interest) : Account(initBal)
    {
        if (interest > 0)
        {
            m_interestRate = interest;
        }
        else
            m_interestRate = 0;
    }
    void SavingsAccount::monthEnd()
    {
        credit(Account::balance() * m_interestRate);
    }
    void SavingsAccount::display(std::ostream &ostr) const
    {
        ostr << "Account type: Savings" << endl;
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << "Balance: $" << balance() << endl;
        ostr << "Interest Rate (%): " << m_interestRate * 100 << endl;
    }
}