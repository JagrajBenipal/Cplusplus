/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 25, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds
{
    char Utilities::m_delimiter = ',';

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
    {
        // a copy of the extracted token found
        string token = "";
        // change next_pos as start location
        size_t start_pos = next_pos;

        // delimiter position
        next_pos = str.find(m_delimiter, start_pos);

        // lambda expression to remove space
        auto removeSpace = [](string &src) -> string &
        {
            bool valid = false;

            while (!valid)
            {
                if (src[0] == ' ')
                {
                    src.erase(0, src.find_first_not_of(' '));
                }
                else if (src[src.length() - 1] == ' ')
                {
                    src.erase(src.find_last_not_of(' ') + 1);
                }
                else
                {
                    valid = true;
                }
            }
            return src;
        };

        if (start_pos == next_pos)
        {
            more = false;
            // reports an exception if a delimiter is found at next_pos
            throw "   ERROR: No token.";
        }
        else if (next_pos == string::npos) // pos is end of string
        {
            // from the provided character till end
            token = str.substr(start_pos);
            // without spaces at the beginning/end
            removeSpace(token);
            // string ended, no more token left
            more = false;
            // update m_widthField if its current value is less than the size of the token
            if (m_widthField < token.length())
            {
                m_widthField = token.length();
            }
        }
        else
        {
            // from the provided character with length (next_pos - start_pos)
            token = str.substr(start_pos, next_pos - start_pos);
            // without spaces at the beginning/end
            removeSpace(token);
            // have another delimiter, have more token
            more = true;
            // update m_widthField if its current value is less than the size of the token
            if (m_widthField < token.length())
            {
                m_widthField = token.length();
            }
        }
        // update next_pos with the position of the next token ( delimiter + 1 )
        next_pos++;
        // return a copy of the extracted token found
        return token;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

}