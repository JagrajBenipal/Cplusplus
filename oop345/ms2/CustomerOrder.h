/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 25, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Station.h"

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

using namespace std;
namespace sdds
{

    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string &src) : m_itemName(src){};
    };

    class CustomerOrder
    {
        // Instance Variables
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item **m_lstItem{};

        // Class Variable
        static size_t m_widthField;

    public:
        CustomerOrder(){};
        CustomerOrder(const string &str);

        CustomerOrder(const CustomerOrder &src);
        CustomerOrder &operator=(const CustomerOrder &src) = delete;

        CustomerOrder(CustomerOrder &&src) noexcept;
        CustomerOrder &operator=(CustomerOrder &&src) noexcept;

        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string &itemName) const;
        void fillItem(Station &station, std::ostream &os);
        void display(std::ostream &os) const;
    };

}
#endif