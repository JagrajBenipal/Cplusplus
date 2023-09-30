/*
*********************************************************************
Name : Jagraj Singh Benipal
Student ID: 156374217
Email: jbenipal1@myseneca.ca
Date: May 27, 2022
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"

using namespace std;

namespace sdds
{

    int noOfStudents{};
    Student *students = nullptr;

    bool load(const char filename[])
    {
        int i = 0;
        sdds::openFile(filename);
        noOfStudents = sdds::noOfRecords();
        students = new Student[noOfStudents];

        bool ok = true;
        for (i = 0; i < noOfStudents && ok; i++)
        {
            ok = load(students[i]);
        }
        if (i != noOfStudents)
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            return false;
        }
        sdds::closeFile();
        return true;
    }

    bool load(Student &std)
    {
        char tmp[128] = {};
        if (sdds::read(tmp))
        {
            std.m_name = new char[strlen(tmp) + 1];
            strcpy(std.m_name, tmp);
            if (sdds::read(std.m_studentNumber))
            {
                if (sdds::read(std.m_grade))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    void sort()
    {
        int i, j;
        Student tmp;
        for (i = noOfStudents - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (students[j].m_grade > students[j + 1].m_grade)
                {
                    tmp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = tmp;
                }
            }
        }
    }

    void display()
    {
        sort();
        for (int i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
            // cout << endl;
        }
    }

    void display(Student &std)
    {
        cout << std.m_name << ", " << std.m_studentNumber << ": " << std.m_grade << endl;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
        }
        delete[] students;
    }

}