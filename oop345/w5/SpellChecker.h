/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
#include "Book.h"
#include "Movie.h"

namespace sdds
{
    class SpellChecker
    {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        unsigned int m_fixedCnt[6]{};
        size_t cnt{};

    public:
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
        void fixCnt(unsigned int &idx);
    };

}

#endif
