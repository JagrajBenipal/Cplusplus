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
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"

using namespace std;
namespace sdds
{
    Person *buildInstance(std::istream &in)
    {
        string str = "";
        char type = '\0';
        char comma = '\0';

        getline(in, str);
        str.erase(0, str.find_first_not_of(' '));

        stringstream strs;
        strs << str;
        strs >> type >> comma;

        if (strs)
        {
            if (type == 'e' || type == 'E')
            {
                return new Employee(strs);
            }
            else if (type == 's' || type == 'S')
            {
                return new Student(strs);
            }
            else if (type == 'p' || type == 'P')
            {
                return new Professor(strs);
            }
        }

        return nullptr;
    }

    string &removeSpace(string &str)
    {
        bool valid = false;

        while (!valid)
        {
            if (str[0] == ' ')
            {
                str.erase(0, str.find_first_not_of(' '));
            }
            else if (str[str.length() - 1] == ' ')
            {
                str.erase(str.find_last_not_of(' ') + 1);
            }
            else
            {
                valid = true;
            }
        }
        return str;
    }

}