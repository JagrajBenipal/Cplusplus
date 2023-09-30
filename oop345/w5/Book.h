/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
namespace sdds
{

    class Book
    {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_description{};

    public:
        Book() = default;
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double &price();
        Book(const std::string &strBook);
        std::ostream &display(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &ostr, const Book &other);

        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_description);
        }
    };
}
#endif