///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 5, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>
namespace sdds
{
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        Pair() = default;
        const std::string &getKey() const { return m_key; }
        const std::string &getValue() const { return m_value; }
        Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};
        std::ostream &display(std::ostream &ostr = std::cout) const;
        // TODO: Add here the missing prototypes for the members
        //           that are necessary if this class is to be used
        //           with the template classes described below.
        //       Implement them in the Pair.cpp file.
        bool operator==(const Pair &p) const;
    };
    std::ostream &operator<<(std::ostream &ostr, const Pair &P);

}
#endif