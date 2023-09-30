/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include "Bakery.h"

using namespace std;
namespace sdds
{
    Bakery::Bakery(const char *filename)
    {
        BakedGood tempBakeGood{};
        string tempstr{};

        try
        {
            ifstream file(filename);
            // get one line
            while (getline(file, tempstr))
            {
                // BakeType - size 8
                string tempBakeType{};
                tempBakeType = tempstr.substr(0, 8);
                if (tempBakeType[0] == 'B')
                {
                    tempBakeGood.m_type = BakedType::BREAD;
                }
                else if (tempBakeType[0] == 'P')
                {
                    tempBakeGood.m_type = BakedType::PASTERY;
                }
                // remove the first 8 char
                tempstr = tempstr.substr(8);

                // Description - size 20
                string tempDesc{};
                tempDesc = tempstr.substr(0, 20);
                // remove the space
                tempDesc.erase(tempDesc.find_last_not_of(' ') + 1);
                tempBakeGood.m_desc = tempDesc;

                // remove the first 20 char
                tempstr = tempstr.substr(20);

                stringstream sstr;
                sstr << tempstr;

                // ShelfLife - size 14
                sstr >> tempBakeGood.m_shelfDay;
                // Stock - size 8
                sstr >> tempBakeGood.m_amount;
                // Price - size 6
                sstr >> tempBakeGood.m_price;
                // put into the vector
                c_items.push_back(tempBakeGood);
            }
        }
        catch (const std::exception &)
        {
            throw "Error, file cannot open!!!";
        }
    }

    void Bakery::showGoods(std::ostream &os) const
    {
        // for_each(InputIterator start_iter, InputIterator last_iter, Function fnc)
        for_each(c_items.begin(), c_items.end(), [&os](const BakedGood &theBakery)
                 { os << theBakery << endl; });

        // accumulate(first, last, sum, myfun);
        size_t totalStock = accumulate(c_items.begin(), c_items.end(), 0, [](size_t totalS, const BakedGood &theBakery)
                                       { return totalS + theBakery.m_amount; });
        double totalPrice = accumulate(c_items.begin(), c_items.end(), 0.00, [](double totalP, const BakedGood &theBakery)
                                       { return totalP + theBakery.m_price; });
        os << "Total Stock: " << totalStock << endl;
        os << "Total Price: " << totalPrice << endl;
    }

    void Bakery::sortBakery(string str)
    {
        if (str == "Description")
        {
            sort(c_items.begin(), c_items.end(), [](const BakedGood &a, const BakedGood &b)
                 { return a.m_desc < b.m_desc; });
        }
        else if (str == "Shelf")
        {
            sort(c_items.begin(), c_items.end(), [](const BakedGood &a, const BakedGood &b)
                 { return a.m_shelfDay < b.m_shelfDay; });
        }
        else if (str == "Stock")
        {
            sort(c_items.begin(), c_items.end(), [](const BakedGood &a, const BakedGood &b)
                 { return a.m_amount < b.m_amount; });
        }
        else if (str == "Price")
        {
            sort(c_items.begin(), c_items.end(), [](const BakedGood &a, const BakedGood &b)
                 { return a.m_price < b.m_price; });
        }
    }

    std::vector<BakedGood> Bakery::combine(Bakery &b)
    {
        vector<BakedGood> temp(c_items.size() + b.c_items.size());
        sortBakery("Price");
        b.sortBakery("Price");

        // merge(beg1, end1, beg2, end2, res, myfun)
        merge(c_items.begin(), c_items.end(), b.c_items.begin(), b.c_items.end(), temp.begin(), [](const BakedGood &a, const BakedGood &b)
              { return a.m_price < b.m_price; });

        return temp;
    }

    bool Bakery::inStock(const string &str, const BakedType &bt) const
    {
        // bool any_of (start, end, condition_function);
        return any_of(c_items.begin(), c_items.end(), [str, bt](const BakedGood &theBakery)
                      { return str == theBakery.m_desc && bt == theBakery.m_type && theBakery.m_amount > 0; });
    }

    std::list<BakedGood> Bakery::outOfStock(const BakedType &bt) const
    {
        list<BakedGood> temp;

        // copy_if(first - source, last - source, begin - destination, myfun)
        // back_inserter = push_back
        copy_if(c_items.begin(), c_items.end(), back_inserter(temp), [bt](const BakedGood &theBakery)
                { return (theBakery.m_type == bt && theBakery.m_amount == 0); });

        return temp;
    }

    std::ostream &operator<<(std::ostream &out, const BakedGood &b)
    {
        if (b.m_type == BakedType::BREAD)
        {
            out << "* " << left << setw(10) << "Bread";
        }
        else if (b.m_type == BakedType::PASTERY)
        {
            out << "* " << left << setw(10) << "Pastry";
        }
        out << " * " << left << setw(20) << b.m_desc;
        out << " * " << left << setw(5) << b.m_shelfDay;
        out << " * " << left << setw(5) << b.m_amount;
        out << " * " << fixed << setprecision(2) << right << setw(8) << b.m_price << " * ";

        return out;
    }

}