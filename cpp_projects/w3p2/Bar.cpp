/********************************************************************
                        Workshop 3 part 2
Full Name  : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Bar.h"

using namespace std;

namespace sdds
{

    void Bar::set(const char *title, const char bar, int length)
    {
        strcpy(m_Title, title);
        m_fillCh = bar;
        m_sample = length;
        m_valid = validBar();
    }

    void Bar::draw() const
    {
        if (m_valid)
        {
            cout.width(MAX_TITLE_CHAR);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_Title << "|";
            for (int i = 0; i < m_sample / 2; i++)
            {
                cout << m_fillCh;
            }
            cout << endl;
        }
    }

    bool Bar::validBar()
    {
        if (m_sample > 0 && m_sample <= 100 && m_Title != nullptr && m_Title[0])
        {
            m_valid = true;
            return m_valid;
        }
        else
        {
            emptyBar();
            return false;
        }
    }

    void Bar::emptyBar()
    {
        *m_Title = {};
        m_fillCh = '\0';
        m_sample = 0;
        m_valid = false;
    }

}