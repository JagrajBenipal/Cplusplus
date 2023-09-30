///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 12, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Toy.h"

namespace sdds
{
    void Toy::trim(std::string &string)
    {
        int firstCharLoc{};
        int lastCharLoc{};
        int found = 0;
        // cut from the beginning
        for (int i = 0; i < (int)string.length() && found == 0; i++)
        {
            if (isalnum(string[i]))
            {
                firstCharLoc = i;
                found = 1;
            }
        }
        string.erase(string.begin(), string.begin() + firstCharLoc);

        // cut from the end
        found = 0;
        for (int i = (int)string.length(); i > 0 && found == 0; i--)
        {
            if (isalnum(string[i]))
            {
                lastCharLoc = i;
                found = 1;
            }
        }
        string.erase(lastCharLoc + 1);
    }

    Toy::Toy(const std::string &toy)
    {
        std::string temp{};
        int deliStart{};
        int deliEnd{};
        // order_id
        deliEnd = toy.find(':');
        temp = toy.substr(0, deliEnd);
        trim(temp);
        order_id = std::stoi(temp);
        // std::cout << "order_id is: " << order_id << std::endl;
        // name
        deliStart = deliEnd + 1;
        deliEnd = toy.find(':', deliStart);
        temp = toy.substr(deliStart, deliEnd - deliStart);
        trim(temp);
        name = temp;
        // std::cout << "name is: " << name << std::endl;
        // itemNum
        deliStart = deliEnd + 1;
        deliEnd = toy.find(':', deliStart);
        temp = toy.substr(deliStart, deliEnd - deliStart);
        trim(temp);
        itemNum = std::stoi(temp);
        // std::cout << "itemNum is: " << itemNum << std::endl;
        // price
        deliStart = deliEnd + 1;
        temp = toy.substr(deliStart);
        // std::cout << "temp is: " << temp << std::endl;
        trim(temp);
        // std::cout << "temp is: " << temp << std::endl;
        price = std::stod(temp);
        // std::cout << "price is: " << price << std::endl;
    }

    Toy::Toy(const Toy &toy)
    {
        order_id = toy.order_id;
        name = toy.name;
        itemNum = toy.itemNum;
        price = toy.price;
    }

    std::ostream &operator<<(std::ostream &ostr, const Toy &toy)
    {
        double subTotal{toy.price * toy.itemNum};
        double tax = subTotal * toy.hst / 100;
        ostr << "Toy";
        ostr.width(8);
        ostr << toy.order_id << ":";
        ostr.width(18);
        ostr << std::right << toy.name;
        ostr.width(3);
        ostr << toy.itemNum << " items";
        ostr.width(8);
        ostr << toy.price << "/item  subtotal:";
        ostr.width(7);
        ostr << std::fixed << std::setprecision(2) << subTotal << " tax:";
        ostr.width(6);
        ostr << std::setprecision(2) << tax << " total:";
        ostr.width(7);
        ostr << subTotal + tax << std::endl;
        return ostr;
    }

    Toy::operator bool() const
    {
        return order_id;
    }
}