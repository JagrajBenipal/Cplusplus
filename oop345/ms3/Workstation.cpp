/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Workstation.h"

using namespace std;
namespace sdds
{
    deque<CustomerOrder> g_pending{};
    deque<CustomerOrder> g_completed{};
    deque<CustomerOrder> g_incomplete{};

    void Workstation::fill(std::ostream &os)
    {
        // fills the order at the front of the queue if there are CustomerOrders in the queue
        if (m_orders.size() > 0)
        {
            m_orders.front().fillItem(*this, os);
        }
    }
    bool Workstation::attemptToMoveOrder()
    {
        // move the order order at the front of the queue to the next station
        bool result = false;

        if (m_orders.size() > 0)
        {
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0)
            // cannot be filled - Item filled || not enough inventory - quantity == 0
            {
                // move it to the next station
                if (m_pNextStation)
                {
                    *m_pNextStation += move(m_orders.front());
                    m_orders.pop_front();
                    result = true;
                }
                else // no next station
                {
                    // then the order is moved into g_completed or g_incomplete queue
                    if (m_orders.front().isOrderFilled())
                    {
                        g_completed.push_back(move(m_orders.front()));
                    }
                    else
                    {
                        g_incomplete.push_back(move(m_orders.front()));
                    }

                    // remove the moved space in deque
                    m_orders.pop_front();
                    // if an order has been moved, return true
                    result = true;
                }
            }
        }
        return result;
    }

    void Workstation::setNextStation(Workstation *station)
    {
        m_pNextStation = station;
    }

    Workstation *Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream &os) const
    {
        if (m_pNextStation)
        {
            os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
        }
        else
        {
            os << getItemName() << " --> "
               << "End of Line" << endl;
        }
    }

    Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
    {
        m_orders.push_back(move(newOrder));
        return *this;
    }

}