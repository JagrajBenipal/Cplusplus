/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    size_t Station::m_widthField = 0u;
    size_t Station::id_generator = 0u;

    Station::Station(const string &str)
    {
        // uses a Utilities object(defined locally)
        Utilities util;

        // id
        m_id = ++Station::id_generator;

        // prepare for extractToken
        bool more = false; // random T/F as function will modify afterward
        size_t pos = 0u;   // 0 = at begining

        try
        {
            // -- ORDER --
            // name of the item
            // starting serial number
            // quantity in stock
            // description
            // 1. str no change, 2. pos change each time, 3. more no effect
            // name
            m_name = util.extractToken(str, pos, more);
            // serial (int)
            m_serial = stoi(util.extractToken(str, pos, more));
            // number in stock (int)
            m_numInStock = stoi(util.extractToken(str, pos, more));

            if (Station::m_widthField < util.getFieldWidth())
            {
                Station::m_widthField = util.getFieldWidth();
            }

            // description
            m_desc = util.extractToken(str, pos, more);
        }
        catch (const char *err)
        {
            cout << err;
        }
    }
    const std::string &Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_serial++;
    }

    size_t Station::getQuantity() const
    {
        return m_numInStock;
    }

    void Station::updateQuantity()
    {
        if (m_numInStock < 0)
        {
            m_numInStock = 0;
        }
        else
        {
            --m_numInStock;
            ;
        }
    }

    void Station::display(std::ostream &os, bool full) const
    {
        os << right << setw(3) << setfill('0') << m_id << " | ";
        os << left << setw(Station::m_widthField) << setfill(' ') << m_name << "  | ";
        os << right << setw(6) << setfill('0') << m_serial << " | ";

        if (full)
        {
            os << right << setw(4) << setfill(' ') << m_numInStock << " | ";
            os << m_desc;
        }

        os << endl;
    }

}