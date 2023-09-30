/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>

#include "Employee.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    Employee::Employee(istream &in)
    {
        // name
        string tempName = "";
        getline(in, tempName, ',');
        m_name = removeSpace(tempName);

        // age
        string tempAge = "";
        getline(in, tempAge, ',');
        removeSpace(tempAge);
        try
        {
            m_age = to_string(stoi(tempAge));
        }
        catch (...)
        {
            throw m_name + "++Invalid record!";
        }

        // id
        string tempId = "";
        getline(in, tempId, ',');
        tempId = removeSpace(tempId);

        if (tempId[0] == 'E')
        {
            m_id = tempId;
        }
        else
        {
            throw m_name + "++Invalid record!";
        }
    }

    std::string Employee::status() const
    {
        return "Employee";
    }

    std::string Employee::name() const
    {
        return m_name;
    }

    std::string Employee::id() const
    {
        return m_id;
    }

    std::string Employee::age() const
    {
        return m_age;
    }

    void Employee::display(std::ostream &out) const
    {
        out << "| " << left << setw(10) << "Employee";
        out << "| " << left << setw(10) << m_id;
        out << "| " << left << setw(20) << m_name;
        out << " | " << left << setw(3) << m_age;
        out << " |";
    }

}