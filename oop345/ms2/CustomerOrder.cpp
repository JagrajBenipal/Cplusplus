/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 25, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    size_t CustomerOrder::m_widthField = 0u;

    CustomerOrder::CustomerOrder(const string &str)
    {
        Utilities util;

        // prepare for extractToken
        bool more = false; // random T/F as function will modify afterward
        size_t pos = 0u;   // 0 = at beginning
        size_t index = 0u;

        m_name = util.extractToken(str, pos, more);
        m_product = util.extractToken(str, pos, more);
        m_cntItem = count(str.begin(), str.end(), util.getDelimiter()) - 1;

        // the list of items making up the order (at least one item)
        m_lstItem = new Item *[m_cntItem];

        // more T/F from extractToken - 1st from above, 2nd from below
        // more TRUE -> not end of line (from extractToken Function)
        while (more)
        {
            // handle the item name in struct for each item
            m_lstItem[index] = new Item(util.extractToken(str, pos, more));
            index++;
        }

        if (CustomerOrder::m_widthField < util.getFieldWidth())
        {
            CustomerOrder::m_widthField = util.getFieldWidth();
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder &src)
    {
        throw 0;
    }

    CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept
    {
        *this = std::move(src);
    }

    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&src) noexcept
    {
        if (this != &src)
        {
            if (m_lstItem)
            {
                for (size_t i = 0; i < m_cntItem; i++)
                {
                    delete m_lstItem[i];
                }
                delete[] m_lstItem;
            }

            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;

            m_lstItem = src.m_lstItem;

            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0u;
            src.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder()
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const
    {
        bool allFilled = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            // keep true, any one not filled = false till end
            if (!m_lstItem[i]->m_isFilled)
            {
                allFilled = false;
            }
        }
        return allFilled;
    }

    bool CustomerOrder::isItemFilled(const std::string &itemName) const
    {
        bool itemFilled = true;

        for (size_t i = 0; i < m_cntItem; i++)
        {
            // Keep true -> returns true if all items specified by itemName have been filled.
            // Keep true -> If the item doesn't exist in the order, this query returns true.
            // False -> when itemName not filled
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
            {
                itemFilled = false;
            }
        }
        return itemFilled;
    }

    void CustomerOrder::fillItem(Station &station, std::ostream &os)
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            // the order contains items handled
            if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
            {
                // Station's inventory contains at least one item
                if (station.getQuantity() > 0)
                {
                    // subtracts 1 from the inventory
                    station.updateQuantity();
                    // updates Item::m_serialNumber and Item::m_isFilled
                    m_lstItem[i]->m_isFilled = true;
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    // prints the message "    Filled NAME, PRODUCT [ITEM_NAME]"
                    os << "    Filled ";
                }
                else // the inventory is empty
                {
                    os << "    Unable to fill ";
                }
                // all messages printed are terminated by an endline
                os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream &os) const
    {
        os << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName;
            os << "   - ";
            if (m_lstItem[i]->m_isFilled)
            {
                os << "FILLED";
            }
            else
            {
                os << "TO BE FILLED";
            }
            os << endl;
        }
    }
}