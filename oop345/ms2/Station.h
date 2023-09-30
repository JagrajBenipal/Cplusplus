/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 25, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

using namespace std;
namespace sdds
{
    class Station
    {
        // Instance Variables
        int m_id{};
        string m_name{};
        string m_desc{};
        unsigned m_serial{};
        unsigned m_numInStock{};

        // Class Variables
        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(){};
        Station(const string &str);
        const std::string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream &os, bool full) const;
    };
}
#endif