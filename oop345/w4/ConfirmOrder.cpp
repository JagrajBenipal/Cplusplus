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
#include "Toy.h"
#include "ConfirmOrder.h"

namespace sdds
{
    ConfirmOrder::ConfirmOrder(const ConfirmOrder &co)
    {
        *this = co;
    }

    void ConfirmOrder::operator=(const ConfirmOrder &co)
    {
        if (this != &co)
        {
            if (counter)
            {
                for (int i = 0; i < counter; i++)
                {
                    m_toyArray[i] = nullptr;
                }
                delete[] m_toyArray;
            }
            counter = co.counter;
            m_toyArray = new const Toy *[counter];
            for (int i = 0; i < counter; i++)
            {
                m_toyArray[i] = co.m_toyArray[i];
            }
        }
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder &&co) noexcept
    {
        counter = co.counter;
        m_toyArray = new const Toy *[counter];
        for (int i = 0; i < counter; i++)
        {
            m_toyArray[i] = co.m_toyArray[i];
            co.m_toyArray[i] = nullptr;
        }
        delete[] co.m_toyArray;
        co.m_toyArray = nullptr;
        co.counter = 0;
    }

    void ConfirmOrder::operator=(ConfirmOrder &&co) noexcept
    {
        if (this != &co)
        {
            if (counter)
            {
                for (int i = 0; i < counter; i++)
                {
                    m_toyArray[i] = nullptr;
                }
                delete[] m_toyArray;
            }
            counter = co.counter;
            m_toyArray = new const Toy *[counter];
            for (int i = 0; i < counter; i++)
            {
                m_toyArray[i] = co.m_toyArray[i];
                co.m_toyArray[i] = nullptr;
            }
            delete[] co.m_toyArray;
            co.m_toyArray = nullptr;
            co.counter = 0;
        }
    }
    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {
        bool outArray = true;
        for (int i = 0; i < counter; i++)
        {
            if (&toy == m_toyArray[i])
            {
                outArray = false;
            }
        }
        if (outArray)
        {
            // put to the temp array
            counter += 1;
            const Toy **temp = new const Toy *[counter];
            for (int i = 0; i < counter - 1; i++)
            {
                temp[i] = m_toyArray[i];
                m_toyArray[i] = nullptr;
            }
            temp[counter - 1] = &toy;
            delete[] m_toyArray;
            // put back to the old array
            m_toyArray = temp;
            temp = nullptr;
        }
        return *this;
    }

    ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
    {
        bool outArray = true;
        for (int i = 0; i < counter; i++)
        {
            if (&toy == m_toyArray[i])
            {
                outArray = false;
                m_toyArray[i] = nullptr;
            }
        }
        if (!outArray)
        {
            // put to temp array
            counter -= 1;
            int track{};
            const Toy **temp = new const Toy *[counter];
            for (int i = 0; i < counter + 1; i++)
            {
                if (m_toyArray[i] != nullptr)
                {
                    temp[track++] = m_toyArray[i];
                    m_toyArray[i] = nullptr;
                }
            }
            delete[] m_toyArray;
            // put back to the old array
            m_toyArray = temp;
            temp = nullptr;
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &ostr, const ConfirmOrder &co)
    {
        ostr << "--------------------------" << std::endl;
        ostr << "Confirmations to Send" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (!co.counter)
        {
            ostr << "There are no confirmations to send!" << std::endl;
        }
        else
        {
            for (int i = 0; i < co.counter; i++)
            {
                ostr << *co.m_toyArray[i];
            }
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    ConfirmOrder::~ConfirmOrder()
    {
        for (int i = 0; i < counter; i++)
        {
            m_toyArray[i] = nullptr;
        }
        delete[] m_toyArray;
        m_toyArray = nullptr;
    }
}