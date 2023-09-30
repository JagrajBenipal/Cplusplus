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
#include "Person.h"
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

using namespace std;
namespace sdds
{
    Person *buildInstance(std::istream &in);
    string &removeSpace(string &str);
}
#endif