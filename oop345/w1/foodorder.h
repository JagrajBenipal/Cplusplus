///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: MAY 22, 2022
//  I have done all the workshop by myself and have only copied the code provided
//  by professor.
//*

#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{

    class FoodOrder
    {
        char customerName[11];
        char *description;
        double price;
        bool specialOrNot;

    public:
        FoodOrder();
        FoodOrder(const FoodOrder &other);
        FoodOrder &operator=(const FoodOrder &other);
        ~FoodOrder();
        void read(std::istream &istr);
        void display() const;
    };
}
#endif