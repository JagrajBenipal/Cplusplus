/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 12, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    Student::Student(istream &in)
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

        if (tempId[0] == 'S')
        {
            m_id = tempId;
        }
        else
        {
            throw m_name + "++Invalid record!";
        }

        // Num of courses
        string tempNum = "";
        getline(in, tempNum, ',');
        m_count = stoi(removeSpace(tempNum));

        // course
        m_course = new string[m_count];
        for (size_t i = 0; i < m_count; i++)
        {
            string tempCourse = "";
            getline(in, tempCourse, ',');
            m_course[i] = removeSpace(tempCourse);
        }
    }

    std::string Student::status() const
    {
        return "Student";
    }

    std::string Student::name() const
    {
        return m_name;
    }

    std::string Student::age() const
    {
        return m_age;
    }

    std::string Student::id() const
    {
        return m_id;
    }

    void Student::display(std::ostream &out) const
    {
        out << "| " << left << setw(10) << status();
        out << "| " << left << setw(10) << m_id;
        out << "| " << left << setw(20) << m_name;
        out << " | " << left << setw(3) << m_age;
        out << " |";
        for (size_t i = 0; i < m_count; i++)
        {
            if (i != m_count - 1)
            {
                out << m_course[i] << ", ";
            }
            else
            {
                out << m_course[i];
            }
        }
    }
    Student::~Student()
    {
        delete[] m_course;
    }
}