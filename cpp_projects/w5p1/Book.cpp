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
#include "Book.h"

using namespace std;
namespace sdds
{
    void Book::init_book()
    {
        m_title[0] = '\0';
        m_author[0] = '\0';
        m_num_chapters = 0;
        m_num_pages = 0;
    }

    int Book::add_chapter(Chapter *chapter)
    {
        Chapter temp;
        temp = *chapter;
        m_chapters[m_num_chapters] = temp;
        m_num_pages = m_num_pages + (int)m_chapters[m_num_chapters];
        operator++(m_num_chapters);
        return m_num_chapters;
    }

    Book::Book()
    {
        init_book();
    }

    Book::Book(const char *title_)
    {
        init_book();
        strcpy(m_title, title_);
    }

    Book::Book(const char *title_, const char *author_, double price_)
    {
        init_book();
        strcpy(m_title, title_);
        strcpy(m_author, author_);
        m_price = price_;
    }

    // Print a book summary
    void Book::summary()
    {
        cout.setf(ios::left);
        cout << "| ";
        cout.width(MAX_BOOK_TITEL);
        cout << m_title << " | ";
        cout.width(MAX_AUTHOR_NAME);
        cout << m_author << " | ";
        cout.width(3);
        cout << m_num_chapters << "  ";
        cout.width(4);
        cout << m_num_pages << " | ";
        cout.width(6);
        cout << m_price << " |" << endl;
    }

    Book Book::operator++(int)
    {
        Book temp;
        if (m_num_chapters < MAX_NUM_CHAPTERS)
        {
            m_num_chapters++;
        }
        return temp;
    }

    std::ostream &Book::display(std::ostream &os) const
    {
        cout << "Title:'" << this->m_title << "'" << endl;
        cout << "Author: '" << this->m_author << "'" << endl;
        for (int j = 0; j < m_num_chapters; j++)
        {
            m_chapters[j].display(os);
        }
        return os;
    }

    Book::operator bool()
    {
        if (m_title != nullptr && m_title[0] != '\0' && m_author != nullptr && m_author[0] != '\0' && m_num_chapters > 0)
        {
            for (int i = 0; i < MAX_NUM_CHAPTERS; i++)
            {
                if (int(m_chapters[i]) > 0)
                    return true;
            }
        }
        return false;
    }

    Book::operator int()
    {
        return m_num_chapters;
    }

    Book::operator double()
    {
        double temp = 0;
        if (this)
            temp = m_price;
        return temp;
    }

    Book::operator const char *()
    {
        return (const char *)m_title;
    }

    bool Book::operator!()
    {
        if (*this)
            return bool();
        return !bool();
    }

    Book &Book::operator+=(Chapter &addChap)
    {
        add_chapter(&addChap);
        return *this;
    }

    Book &Book::operator-=(double discount)
    {
        m_price = m_price - discount;
        return *this;
    }

    std::ostream &operator<<(std::ostream &ostr, const Book &book)
    {
        return book.display(ostr);
    }

}