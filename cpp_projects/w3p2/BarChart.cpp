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
#include <string.h>
#include <iostream>
#include "BarChart.h"
#include "Bar.h"

using namespace std;

namespace sdds
{

    void BarChart::init(const char *title, int noOfSampels, char fill)
    {
        if (title)
        {
            m_charTitle = new char[strlen(title) + 1];
            strcpy(m_charTitle, title);
            m_numOfSample = noOfSampels;
            m_fillChar = fill;
            bar = new Bar[m_numOfSample];
        }
        else
        {
            delete[] m_charTitle;
            m_charTitle = nullptr;
        }
    }

    void BarChart::add(const char *bar_title, int value)
    {
        bar[m_sizeOfBars].set(bar_title, m_fillChar, value);
        m_sizeOfBars++;
    }

    void BarChart::draw() const
    {
        if (m_sizeOfBars == m_numOfSample)
        {
            cout << m_charTitle << endl;
            cout.width(71);
            cout.fill('-');
            cout << "-" << endl;
            for (int i = 0; i < m_numOfSample; i++)
            {
                bar[i].draw();
            }
            cout.width(71);
            cout.fill('-');
            cout << "-" << endl;
        }
        else
            cout << "Invalid Chart!" << endl;
    }

    void BarChart::deallocate()
    {
        delete[] bar;
        bar = nullptr;
        delete[] m_charTitle;
        m_charTitle = nullptr;
    }
}