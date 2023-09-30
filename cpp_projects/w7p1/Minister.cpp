/*
*****************************************************************************
                          Workshop - #7 (P1)
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
#include "Minister.h"
#include "MemberParliament.h"
using namespace std;
namespace sdds
{

    Minister::Minister(const char *idd, int age, int year, const char *name, const char *district) : MemberParliament(idd, age)
    {
        m_year = year;
        MemberParliament::NewDistrict(district);
        strcpy(m_pmName, name);
    }

    void Minister::changePM(const char *pm)
    {
        strcpy(m_pmName, pm);
    }

    void Minister::assumeOffice(double year)
    {
        m_year = year;
    }

    std::ostream &Minister::write(std::ostream &os) const
    {
        MemberParliament::write(os);
        os << " | ";
        os << m_pmName;
        os << "/";
        os << m_year;
        return os;
    }

    std::istream &Minister::read(std::istream &in)
    {
        char tempPM[NAME_LENGTH + 1];
        MemberParliament::read(in);
        cout << "Reports TO: ";
        cin >> tempPM;
        strcpy(m_pmName, tempPM);
        cout << "Year Assumed Office: ";
        cin >> m_year;
        return in;
    }

    std::ostream &operator<<(std::ostream &os, const Minister &RO)
    {
        return RO.write(os);
    }

    std::istream &operator>>(std::istream &is, Minister &RO)
    {
        return RO.read(is);
    }
}