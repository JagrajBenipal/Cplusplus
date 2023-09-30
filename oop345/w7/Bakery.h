/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

using namespace std;
namespace sdds
{

    enum class BakedType
    {
        BREAD,
        PASTERY
    };

    struct BakedGood
    {
        BakedType m_type{};
        string m_desc{};
        size_t m_shelfDay{};
        size_t m_amount{};
        double m_price{};
    };

    class Bakery
    {
        vector<BakedGood> c_items{};

    public:
        Bakery(){};
        Bakery(const char *filename);
        void showGoods(std::ostream &os) const;
        void sortBakery(string str);
        std::vector<BakedGood> combine(Bakery &b);
        bool inStock(const string &str, const BakedType &bt) const;
        std::list<BakedGood> outOfStock(const BakedType &bt) const;
    };

    std::ostream &operator<<(std::ostream &out, const BakedGood &b);
}
#endif