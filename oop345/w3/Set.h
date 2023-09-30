///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 5, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <string>
#include <cmath>
#include "Collection.h"
// #include "Pair.h"
namespace sdds
{
    template <typename T>
    class Set : public Collection<T, 100>
    {
    public:
        bool add(const T &item) override
        {
            for (unsigned int i = 0; i < this->m_numOfElements; i++)
            {
                if (item == this->m_obj[i])
                    return false;
            }
            return Collection<T, 100>::add(item);
        }
    };
    template <>
    bool Set<double>::add(const double &item)
    {
        for (unsigned int i = 0; i < m_numOfElements; i++)
        {
            if (std::fabs(item - m_obj[i]) <= 0.01)
                return false;
        }

        return Collection<double, 100>::add(item);
    }

}
#endif