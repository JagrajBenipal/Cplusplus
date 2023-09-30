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
#ifndef SDDS_MEMBERPARLIAMENT_H_
#define SDDS_MEMBERPARLIAMENT_H_
#include <iostream>
#define ID_LENGTH 32
#define DISTRICT_LENGTH 64
namespace sdds
{
    class MemberParliament
    {
        char m_mpID[ID_LENGTH + 1];
        char m_district[DISTRICT_LENGTH + 1];
        int m_age;

    public:
        MemberParliament();
        MemberParliament(const char *id, int age);
        void NewDistrict(const char *district);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };
    std::ostream &operator<<(std::ostream &os, const MemberParliament &RO);
    std::istream &operator>>(std::istream &is, MemberParliament &RO);
}
#endif