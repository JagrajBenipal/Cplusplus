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

#ifndef SDDS_NAME_H_
#define SDDS_NAME_H_
#include <iostream>
#define MAX_NAME_LEN 255

namespace sdds
{
    class Name
    {
        char *m_value{};

    public:
        Name();
        Name(const char *name);
        // Rule of three goes here:
        Name(const Name &toCopy);
        Name &operator=(const Name &toAssign);
        ~Name();

        void cpyName(const char *cstr);
        operator const char *() const;
        virtual operator bool() const;
        virtual std::ostream &display(std::ostream &ostr = std::cout) const;
        virtual std::istream &read(std::istream &istr = std::cin);
    };
}

#endif