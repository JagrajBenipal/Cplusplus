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
#include "ChequingAccount.h"
#include "Account.h"

using namespace std;
namespace sdds
{
    ChequingAccount::ChequingAccount(double initBal, double tranFee, double monFee) : Account(initBal)
    {
        if (tranFee > 0 && monFee > 0)
        {
            m_tranFee = tranFee;
            m_monFee = monFee;
        }
        else
        {
            m_tranFee = 0;
            m_monFee = 0;
        }
    }
    bool ChequingAccount::credit(double cre)
    {
        if (Account::credit(cre))
        {
            Account::debit(m_tranFee);
            return true;
        }
        return false;
    }
    bool ChequingAccount::debit(double deb)
    {
        if (Account::debit(deb))
        {
            Account::debit(m_tranFee);
            return true;
        }
        return false;
    }
    void ChequingAccount::monthEnd()
    {
        Account::debit(m_monFee);
    }
    void ChequingAccount::display(std::ostream &ostr) const
    {
        ostr << "Account type: Chequing" << endl;
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << "Balance: $" << balance() << endl;
        ostr << "Per Transaction Fee: " << m_tranFee << endl;
        ostr << "Monthly Fee: " << m_monFee << endl;
    }
}