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
#include "Account.h"

using namespace std;
namespace sdds
{
    Account::Account()
    {
        m_currBal = 0;
    }
    Account::Account(double initBal)
    {
        if (initBal > 0)
        {
            m_currBal = initBal;
        }
        else
            m_currBal = 0;
    }
    bool Account::credit(double cre)
    {
        if (cre > 0)
        {
            m_currBal += cre;
            return true;
        }
        return false;
    }
    bool Account::debit(double deb)
    {
        if (deb > 0 && deb <= m_currBal)
        {
            m_currBal -= deb;
            return true;
        }
        return false;
    }
    double Account::balance() const
    {
        return m_currBal;
    }
}