/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Workstation.h"

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

using namespace std;
namespace sdds
{
    class LineManager
    {
        // Instance Variables
        vector<Workstation *> m_activeLine{};
        size_t m_cntCustomerOrder{};
        Workstation *m_firstStation{};

    public:
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);
        void reorderStations();
        bool run(std::ostream &os);
        void display(std::ostream &os) const;
    };
}
#endif