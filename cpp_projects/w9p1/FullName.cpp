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
#include "FullName.h"

using namespace std;
namespace sdds
{
    FullName::FullName()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    FullName::FullName(const char *name, const char *lastName) : Name(name)
    {
        Name::cpyName(name);
        cpyFName(lastName);
    }

    FullName::FullName(const FullName &toCopy)
    {
        operator=(toCopy);
    }
    FullName &FullName::operator=(const FullName &toAssign)
    {
        if (this != &toAssign && toAssign)
        {
            Name::operator=(toAssign);
            cpyFName(toAssign);
        }
        return *this;
    }
    FullName::~FullName()
    {
        delete[] m_value;
        m_value = nullptr;
    }
    void FullName::cpyFName(const char *cstr)
    {
        int length;
        delete[] m_value;
        length = strlen(cstr);
        m_value = new char[length + 1];
        strcpy(m_value, cstr);
    }
    FullName::operator const char *() const
    {
        return m_value;
    }
    FullName::operator bool() const
    {
        return (m_value && m_value[0] != '\0' && Name::operator bool());
    }
    std::ostream &FullName::display(std::ostream &ostr) const
    {
        if (m_value)
        {
            Name::display(ostr);
            ostr << " ";
            ostr << m_value;
        }
        return ostr;
    }
    std::istream &FullName::read(std::istream &istr)
    {
        Name::read(istr);
        char *tmpData = new char[MAX_FNAME_LEN + 1];
        m_value = tmpData;
        istr.getline(m_value, MAX_FNAME_LEN + 1, '\n');
        m_value = new char[strlen(tmpData) + 1];
        strcpy(m_value, tmpData);
        delete[] tmpData;
        return istr;
    }
    std::istream &operator>>(std::istream &istr, FullName &S)
    {
        return S.read(istr);
    }
    std::ostream &operator<<(std::ostream &ostr, const FullName &FN)
    {
        if (FN)
            FN.display(ostr);
        return ostr;
    }
}