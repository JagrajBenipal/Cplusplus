/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

using namespace std;
namespace sdds
{
    class Utilities
    {
        // Instance Variable
        size_t m_widthField{1u};

        // Class Variable
        static char m_delimiter;

    public:
        // Member Functions//
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string &str, size_t &next_pos, bool &more);

        // Class Functions
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}
#endif