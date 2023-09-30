/*
*****************************************************************************
                          Workshop - #9 (P1)
Full Name  : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FULLNAME_H_
#define SDDS_FULLNAME_H_
#include <iostream>
#include "Name.h"
#define MAX_FNAME_LEN 255

namespace sdds
{
    class FullName : public Name
    {
        char *m_value{};

    public:
        FullName();
        FullName(const char *name, const char *lastName);
        // Rule of three goes here:
        FullName(const FullName &toCopy);
        FullName &operator=(const FullName &toAssign);
        ~FullName();

        void cpyFName(const char *cstr);
        operator const char *() const;
        virtual operator bool() const;
        virtual std::ostream &display(std::ostream &ostr = std::cout) const;
        virtual std::istream &read(std::istream &istr = std::cin);
    };
    std::istream &operator>>(std::istream &istr, FullName &S);
    std::ostream &operator<<(std::ostream &ostr, const FullName &S);
}

#endif