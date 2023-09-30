/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>

namespace sdds
{
    class Movie
    {
        std::string m_title{};
        unsigned int m_year_released{};
        std::string m_description{};

    public:
        Movie() = default;
        const std::string &title() const;
        Movie(const std::string &strMovie);

        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description);
        }
        std::ostream &display(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &ostr, const Movie &other);
    };

}

#endif
