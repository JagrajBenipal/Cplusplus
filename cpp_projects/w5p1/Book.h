/********************************************************************
Workshop 5 Part 1
Name: Jagraj Singh Benipal
Student ID :156374217
Email: jbenipal1@myseneca.ca
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************/

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds
{
    const int MAX_NUM_CHAPTERS = 10;
    const int MAX_BOOK_TITEL = 40;
    const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL + 1];
        char m_author[MAX_AUTHOR_NAME + 1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];
        void init_book();
        int add_chapter(Chapter *chapter);

    public:
        Book();
        Book(const char *title_);
        Book(const char *title_, const char *author_, double price_);
        void summary();       // Print a book summary
        Book operator++(int); // postfix
        std::ostream &display(std::ostream &) const;
        operator bool();
        operator int();
        operator double();
        operator const char *();
        bool operator!();
        Book &operator+=(Chapter &addChap);
        Book &operator-=(double discount);
    };
    std::ostream &operator<<(std::ostream &ostr, const Book &book);
}
#endif
