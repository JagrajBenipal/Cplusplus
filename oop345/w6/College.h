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
#include <list>
#include "Person.h"
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

using namespace std;
namespace sdds
{
    class College
    {
        std::vector<Person *> m_persons{};

    public:
        College(){};
        College(const College &src) = delete;
        College &operator=(const College &src) = delete;
        College &operator+=(Person *thePerson);
        void display(std::ostream &out) const;
        ~College();

        template <typename T>
        void select(const T &test, std::list<const Person *> &persons)
        {
            for (auto element : m_persons)
            {
                if (test(element))
                {
                    persons.push_back(element);
                }
            }
        }
    };
}
#endif