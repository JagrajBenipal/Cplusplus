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
#ifndef SDDS_MINISTER_H_
#define SDDS_MINISTER_H_
#include <iostream>
#include "MemberParliament.h"
#define NAME_LENGTH 50
namespace sdds
{
    class Minister : public MemberParliament
    {
        char m_pmName[NAME_LENGTH + 1];
        int m_year;

    public:
        Minister(const char *idd, int age, int year, const char *name, const char *district);
        void changePM(const char *pm);
        void assumeOffice(double year);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
        using MemberParliament::write;
    };
    std::ostream &operator<<(std::ostream &os, const Minister &RO);
    std::istream &operator>>(std::istream &is, Minister &RO);
}
#endif