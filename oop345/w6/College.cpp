/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>

#include "College.h"

using namespace std;
namespace sdds
{
    College &College::operator+=(Person *thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }
    void College::display(std::ostream &out) const
    {
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #1 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); it++)
        {
            (*it)->display(out);
            out << endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        out << "|                                        Test #2 Persons in the college!                                               |" << endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
        for (auto itr = m_persons.begin(); itr != m_persons.end(); itr++)
        {
            out << "| " << left << setw(10) << (*itr)->status();
            out << "| " << left << setw(10) << (*itr)->id();
            out << "| " << left << setw(20) << (*itr)->name();
            out << " | " << left << setw(3) << (*itr)->age();
            out << " |" << endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    College::~College()
    {
        for (Person *element : m_persons)
        {
            delete element;
        }
    }
}
