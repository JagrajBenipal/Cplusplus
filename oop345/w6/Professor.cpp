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

#include "Professor.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    Professor::Professor(istream &in) : Employee(in)
    {
        // department
        string tempDpt = "";
        getline(in, tempDpt, ',');
        m_department = removeSpace(tempDpt);
    }

    void Professor::display(std::ostream &out) const
    {
        Employee::display(out);
        out << m_department << "| " << status();
    }

    std::string Professor::status() const
    {
        return "Professor";
    }

    std::string Professor::department() const
    {
        return m_department;
    }

}