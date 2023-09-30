/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds
{
    SpellChecker::SpellChecker(const char *filename)
    {

        ifstream fin(filename);

        if (!fin.is_open())
            throw "Bad file name!";

        else
        {
            string str{};

            while (!fin.eof())
            {
                getline(fin, str);
                if (str != "")
                {
                    m_badWords[cnt] = str.substr(0, str.find(" "));
                    str.erase(0, str.find(" "));
                    str.erase(0, str.find_first_not_of(" "));
                    m_goodWords[cnt++] = str;
                }
            }
        }
        fin.close();
    }

    void SpellChecker::operator()(std::string &text)
    {
        for (auto i = 0u; i < cnt; ++i)
        {
            while ((text.find(m_badWords[i]) != std::string::npos))
            {
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
                m_fixedCnt[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream &out) const
    {
        cout << "Spellchecker Statistics\n";
        for (auto i = 0u; i < cnt; ++i)
            cout << setw(15) << right << m_badWords[i] << ": " << m_fixedCnt[i] << " "
                 << "replacements" << endl;
    }

    void SpellChecker::fixCnt(unsigned int &idx)
    {
        m_fixedCnt[idx]++;
    }

}
