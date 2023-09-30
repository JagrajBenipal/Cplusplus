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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Name.h"

using namespace std;
namespace sdds
{
    Name::Name()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    Name::Name(const char *name)
    {
        cpyName(name);
    }
    void Name::cpyName(const char *cstr)
    {
        int length;
        delete[] m_value;
        length = strlen(cstr);
        m_value = new char[length + 1];
        strcpy(m_value, cstr);
    }
    Name::Name(const Name &toCopy)
    {
        operator=(toCopy);
    }
    Name &Name::operator=(const Name &toAssign)
    {
        if (this != &toAssign && toAssign)
        {
            cpyName((const char *)toAssign);
        }
        return *this;
    }
    Name::~Name()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    Name::operator const char *() const
    {
        return (const char *)m_value;
    }
    Name::operator bool() const
    {
        return m_value != nullptr;
    }
    std::ostream &Name::display(std::ostream &ostr) const
    {
        if (m_value)
            ostr << m_value;
        return ostr;
    }
    std::istream &Name::read(std::istream &istr)
    {
        char *data = new char[MAX_NAME_LEN + 1];
        m_value = data;
        istr.getline(m_value, MAX_NAME_LEN + 1, ' ');
        m_value = new char[strlen(data) + 1];
        strcpy(m_value, data);
        delete[] data;
        return istr;
    }
}
