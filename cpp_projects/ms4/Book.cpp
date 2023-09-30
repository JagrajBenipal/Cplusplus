/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.cpp
Version 1.0
Author	Jagraj Singh Benipal
Student ID: 156374217
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
    Book::Book()
    {
        delete[] m_authorName;
        m_authorName = nullptr;
    }
    Book::Book(const Book &toCopy)
    {
        operator=(toCopy);
    }
    Book &Book::operator=(const Book &toAssign)
    {
        if (this != &toAssign && toAssign)
        {
            Publication::operator=(toAssign);
            cpStr(m_authorName, toAssign.m_authorName);
        }
        return *this;
    }
    Book::~Book()
    {
        delete[] m_authorName;
        m_authorName = nullptr;
    }
    void Book::setEmpty()
    {
        delete[] m_authorName;
        m_authorName = nullptr;
        Publication::setEmpty();
    }
    char Book::type() const
    {
        char rtn;
        rtn = 'B';
        return rtn;
    }
    std::ostream &Book::write(std::ostream &os) const
    {
        Publication::write(os);
        if (conIO(os))
        {
            os << " ";
            if (strlen(m_authorName) > SDDS_AUTHOR_WIDTH)
            {
                for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
                {
                    os << m_authorName[i];
                }
            }
            else
            {
                os.width(SDDS_AUTHOR_WIDTH);
                os << m_authorName;
            }
            os << " |";
        }
        else
        {
            os << '\t';
            os << m_authorName;
        }
        return os;
    }
    std::istream &Book::read(std::istream &is)
    {
        char tmpAuthorName[SDDS_AUTHOR_INPUT_WIDTH + 1]{};
        setEmpty();
        Publication::read(is);
        if (conIO(is))
        {
            readChar(is, '\n');
            cout << "Author: ";
            is.getline(tmpAuthorName, SDDS_AUTHOR_INPUT_WIDTH + 1);
        }
        else
        {
            readChar(is, '\t');
            is.get(tmpAuthorName, SDDS_AUTHOR_INPUT_WIDTH + 1);
        }
        if (is)
        {
            cpStr(m_authorName, tmpAuthorName);
        }
        else
        {
            setEmpty();
        }
        return is;
    }
    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }
    Book::operator bool() const
    {
        return (m_authorName && m_authorName[0] != '\0' && Publication::operator bool());
    }
    bool Book::conIO(std::ios &io) const
    {
        return Publication::conIO(io);
    }
}