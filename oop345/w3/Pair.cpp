///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 5, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#include <iostream>
#include <iomanip>
#include "Pair.h"
using namespace std;

namespace sdds
{

    ostream &Pair::display(ostream &ostr) const
    {
        ostr << setw(20) << right << m_key << ": ";
        ostr << left << m_value;
        return ostr;
    }

    bool Pair::operator==(const Pair &p) const
    {
        bool flag = false;
        if (this == &p)
            flag = true;
        else if (this->getKey() == p.getKey())
            flag = true;
        return flag;
    }

    ostream &operator<<(ostream &ostr, const Pair &P)
    {

        return P.display(ostr);
    }

}