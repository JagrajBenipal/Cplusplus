/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H

using namespace std;
namespace sdds
{
    class Professor : public Employee
    {
        string m_department{};

    public:
        Professor(){};
        Professor(istream &in);
        void display(std::ostream &out) const;
        std::string status() const;
        std::string department() const;
    };
}
#endif