/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Publication.h"

namespace sdds
{
    class Book : public Publication
    {
        char *m_authorName{};

    public:
        Book();
        Book(const Book &toCopy);
        Book &operator=(const Book &toAssign);
        ~Book();
        void setEmpty();
        char type() const;
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &istr);
        void set(int member_id);
        operator bool() const;
        bool conIO(std::ios &io) const;
    };
}
#endif