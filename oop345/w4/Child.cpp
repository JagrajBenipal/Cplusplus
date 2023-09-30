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
#include "Child.h"

namespace sdds
{
    Child::Child(std::string name, int age, const Toy *toys[], size_t count)
    {
        m_name = name;
        m_age = age;
        toyNum = count;
        m_toyArray = new const Toy *[count];
        for (size_t i = 0; i < count; i++)
        {
            m_toyArray[i] = new Toy(*toys[i]);
        }
        // std::cout << *m_toyArray[0] << std::endl;
    }

    Child::Child(const Child &child)
    {
        *this = child;
    }

    void Child::operator=(const Child &child)
    {
        if (this != &child)
        {
            if (toyNum)
            {
                for (size_t i = 0; i < toyNum; i++)
                {
                    delete m_toyArray[i];
                }
                delete[] m_toyArray;
            }
            m_name = child.m_name;
            m_age = child.m_age;
            toyNum = child.toyNum;
            m_toyArray = new const Toy *[toyNum];
            for (size_t i = 0; i < toyNum; i++)
            {
                m_toyArray[i] = new Toy(*child.m_toyArray[i]);
            }
        }
    }

    Child::Child(Child &&child) noexcept
    {
        m_name = child.m_name;
        m_age = child.m_age;
        toyNum = child.toyNum;
        m_toyArray = new const Toy *[toyNum];
        for (size_t i = 0; i < toyNum; i++)
        {
            m_toyArray[i] = child.m_toyArray[i];
            child.m_toyArray[i] = nullptr;
        }
        delete[] child.m_toyArray;
        child.m_toyArray = nullptr;
        child.m_age = 0;
        child.toyNum = 0;
        child.m_name.erase();
    }

    void Child::operator=(Child &&child) noexcept
    {
        if (this != &child)
        {
            if (toyNum)
            {
                for (size_t i = 0; i < toyNum; i++)
                {
                    delete m_toyArray[i];
                    m_toyArray[i] = nullptr;
                }
                delete[] m_toyArray;
            }
            m_name = child.m_name;
            m_age = child.m_age;
            toyNum = child.toyNum;
            m_toyArray = new const Toy *[toyNum];
            for (size_t i = 0; i < toyNum; i++)
            {
                m_toyArray[i] = child.m_toyArray[i];
                child.m_toyArray[i] = nullptr;
            }
            delete[] child.m_toyArray;
            child.m_toyArray = nullptr;
            child.m_age = 0;
            child.toyNum = 0;
            child.m_name.erase();
        }
    }

    size_t Child::size() const
    {
        return toyNum;
    }

    std::ostream &operator<<(std::ostream &ostr, const Child &child)
    {
        static int call_cnt{};
        size_t totalRec = child.size();
        ostr << "--------------------------" << std::endl;
        ostr << "Child " << ++call_cnt << ": " << child.m_name << " "
             << child.m_age << " years old:" << std::endl;
        ostr << "--------------------------" << std::endl;
        // ostr <<"size is: " << child.size() <<std::endl;
        if (totalRec)
        {
            for (size_t i = 0; i < totalRec; i++)
            {
                ostr << *child.m_toyArray[i];
            }
        }
        else
        {
            ostr << "This child has no toys!" << std::endl;
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    Child::~Child()
    {
        for (size_t i = 0; i < toyNum; i++)
        {
            delete m_toyArray[i];
            m_toyArray[i] = nullptr;
        }
        delete[] m_toyArray;
        m_toyArray = nullptr;
    }
}