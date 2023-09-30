/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "Movie.h"

using namespace std;
namespace sdds
{
    const std::string &Movie::title() const
    {
        return m_title;
    }

    Movie::Movie(const std::string &strMovie)
    {
        string str = strMovie;
        string trim(str);
        string tmp{};
        tmp = (str.substr(0, (str.find(","))));
        while (tmp[0] == ' ')
        {
            tmp.erase(tmp.begin());
        }
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
        m_year_released = stoi(tmp);
        str.erase(0, str.find(",") + 1);
        while (str[0] == ' ')
        {
            str.erase(str.begin());
        }
        tmp = str.substr(0, (str.find("\n")));
        while (tmp[tmp.length() - 1] == '\n')
        {
            tmp.erase(tmp.end() - 1);
        }
        m_description = tmp;
    }

    std::ostream &Movie::display(std::ostream &ostr) const
    {
        ostr << setw(40) << m_title << " "
             << "| ";
        ostr << setw(4) << m_year_released << " "
             << "| ";
        ostr << m_description << endl;
        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const Movie &other)
    {
        return other.display(ostr);
    }
}
