/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds
{

    const std::string &Book::title() const
    {
        return m_title;
    }

    const std::string &Book::country() const
    {
        return m_country;
    }

    const size_t &Book::year() const
    {
        return m_year;
    }

    double &Book::price()
    {
        return m_price;
    }

    Book::Book(const std::string &strBook)
    {

        string tmp{};
        string str = strBook;

        m_author = (str.substr(0, (str.find(","))));
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        tmp = str.substr(0, (str.find(",")));

        while (tmp[tmp.length() - 1] == ' ')
        {
            tmp.erase(tmp.end() - 1);
        }
        m_title = tmp;
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        tmp = str.substr(0, (str.find(",")));
        while (tmp[tmp.length() - 1] == ' ')
        {
            tmp.erase(tmp.end() - 1);
        }
        m_country = tmp;
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        tmp = str.substr(0, (str.find(",")));
        m_price = stod(tmp);
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        tmp = str.substr(0, (str.find(",")));
        while (tmp[tmp.length() - 1] == ' ')
        {
            tmp.erase(tmp.end() - 1);
        }
        tmp = str.substr(0, (str.find(",")));

        m_year = stoi(tmp);
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        m_description = str;
    }

    std::ostream &Book::display(std::ostream &ostr) const
    {
        ostr << std::setw(20) << std::right << m_author << " | ";
        ostr << std::setw(22) << std::right << m_title << " | ";
        ostr << std::setw(5) << std::right << m_country << " | ";
        ostr << std::setw(4) << m_year << " | ";
        ostr << std::setw(6) << fixed << setprecision(2) << std::right << m_price << " | ";
        ostr << m_description << endl;
        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const Book &other)
    {
        return other.display(ostr);
    }
}