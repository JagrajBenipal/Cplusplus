/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Person.h"
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

using namespace std;
namespace sdds
{
    class Student : public Person
    {
        string m_name{};
        string m_age{};
        string m_id{};
        string *m_course{};
        size_t m_count{};

    public:
        Student(){};
        Student(istream &in);
        std::string status() const;
        std::string name() const;
        std::string age() const;
        std::string id() const;
        void display(std::ostream &out) const;

        Student(const Student *src) = delete;
        Student *operator=(const Student *src) = delete;
        ~Student();
    };
}
#endif