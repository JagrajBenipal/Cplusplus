/********************************************************************
Workshop 5 Part 1
Name: Jagraj Singh Benipal
Student ID :156374217
Email: jbenipal1@myseneca.ca
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds
{
    void Chapter::init_chapter()
    {
        m_title[0] = '\0';
        m_num_pages = 0;
        m_num_words = 0;
        m_chapter_number = 0;
    }
    Chapter::Chapter()
    {
        init_chapter();
    }

    Chapter::Chapter(const char *title_)
    {
        init_chapter();
        strcpy(m_title, title_);
    }
    Chapter::Chapter(const char *title_, int chapter_num, int n_pages, int n_words)
    {
        strcpy(m_title, title_);
        m_chapter_number = chapter_num;
        m_num_pages = n_pages;
        m_num_words = n_words;
    }
    ostream &Chapter::display(std::ostream &os) const
    {
        cout.setf(std::ios::left);
        os << "| Chapter ";
        os.width(2);
        os << m_chapter_number << " | ";
        os.width(MAX_CHAPTER_TITLE);
        os << m_title << " |" << endl;
        return os;
    }

    Chapter::operator int()
    {
        return m_num_pages;
    }

    Chapter::operator double()
    {
        return (double)m_num_words / m_num_pages;
    }

    Chapter::operator const char *() const
    {
        return (const char *)m_title;
    }

    Chapter &Chapter::operator=(const Chapter &toAssign)
    {
        m_chapter_number = toAssign.m_chapter_number;
        m_num_pages = toAssign.m_num_pages;
        m_num_words = toAssign.m_num_words;
        strcpy(m_title, toAssign.m_title);
        return *this;
    }

    Chapter &Chapter::operator++()
    {
        if (this)
            m_num_pages++;
        return *this;
    }

    Chapter &Chapter::operator--()
    {
        if (this)
            m_num_pages--;
        return *this;
    }

    std::ostream &operator<<(std::ostream &ostr, const Chapter &chap)
    {
        return chap.display(ostr);
    }

}
