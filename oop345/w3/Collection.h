///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 5, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds
{
    template <typename T, unsigned int m_capacity>
    class Collection
    {
    protected:
        T m_obj[m_capacity]{};
        unsigned int m_numOfElements{};

    public:
        Collection() = default;

        size_t size() const
        {
            return m_numOfElements;
        }

        virtual ~Collection()
        {
        }

        void display(std::ostream &ostr = std::cout) const
        {
            ostr << "----------------------\n";
            ostr << "| Collection Content |\n";
            ostr << "----------------------\n";
            for (unsigned int i = 0; i < m_numOfElements; ++i)
            {
                ostr << m_obj[i] << std::endl;
            }
            ostr << "----------------------\n";
        }

        virtual bool add(const T &item)
        {
            bool flag = false;
            if (m_numOfElements < m_capacity)
            {
                m_obj[m_numOfElements++] = item;
                flag = true;
            }
            return flag;
        }

        T operator[](unsigned int idx)
        {
            T tmp{};
            if (idx >= 0 && idx <= m_numOfElements)
            {
                tmp = m_obj[idx];
            }
            return tmp;
        }
    };

    template <>
    Pair Collection<Pair, 100>::operator[](unsigned int idx)
    {
        Pair tmp{};
        if (idx >= 0 && idx <= m_numOfElements)
        {
            tmp = m_obj[idx];
        }
        else
        {
            Pair m_dummy("No Key", "No Value");
            tmp = m_dummy;
        }
        return tmp;
    }

}
#endif