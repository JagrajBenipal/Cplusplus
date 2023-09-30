/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include "CustomerOrder.h"

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

using namespace std;
namespace sdds
{
    extern deque<CustomerOrder> g_pending;
    extern deque<CustomerOrder> g_completed;
    extern deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        // Instance Variables
        deque<CustomerOrder> m_orders{};
        Workstation *m_pNextStation{nullptr};

    public:
        Workstation(const string &str) : Station(str){};

        // the object cannot be copied or moved
        Workstation(const Workstation &src) = delete;
        Workstation(Workstation &&src) = delete;
        Workstation &operator=(const Workstation &src) = delete;
        Workstation &operator=(Workstation &&src) = delete;

        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station);
        Workstation *getNextStation() const;
        void display(std::ostream &os) const;
        Workstation &operator+=(CustomerOrder &&newOrder);
    };

}
#endif