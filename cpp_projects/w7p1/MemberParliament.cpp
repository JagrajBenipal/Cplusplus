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
#include "MemberParliament.h"
using namespace std;
namespace sdds
{
    MemberParliament::MemberParliament()
    {
        strcpy(m_mpID, "000000");
        ;
        m_age = 0;
        strcpy(m_district, "Unassigned");
    }
    MemberParliament::MemberParliament(const char *id, int age)
    {
        strcpy(m_mpID, id);
        m_age = age;
        strcpy(m_district, "Unassigned");
    }
    void MemberParliament::NewDistrict(const char *district)
    {
        cout << "|";
        cout.width(8);
        cout.setf(ios::right);
        cout << m_mpID;
        cout << "| |";
        cout.width(20);
        cout.setf(ios::right);
        cout << m_district;
        cout << " ---> ";
        cout.unsetf(ios::right);
        cout.width(23);
        cout.setf(ios::left);
        cout << district;
        cout << "|" << endl;
        strcpy(m_district, district);
    }
    ostream &MemberParliament::write(ostream &os) const
    {
        os << "| ";
        os << m_mpID;
        os << " | ";
        os << m_age;
        os << " | ";
        os << m_district;
        return os;
    }
    istream &MemberParliament::read(istream &in)
    {
        char tempID[ID_LENGTH + 1];
        char tempDistrict[DISTRICT_LENGTH + 1];
        cout << "Age: ";
        in >> m_age;
        cout << "Id: ";
        in >> tempID;
        strcpy(m_mpID, tempID);
        cout << "District: ";
        in >> tempDistrict;
        strcpy(m_district, tempDistrict);
        return in;
    }
    std::ostream &operator<<(std::ostream &os, const MemberParliament &RO)
    {
        return RO.write(os);
    }
    std::istream &operator>>(std::istream &is, MemberParliament &RO)
    {
        return RO.read(is);
    }
}