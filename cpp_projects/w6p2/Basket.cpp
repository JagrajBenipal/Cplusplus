/*********************************************************************
                        Workshop 6 part 2
 Name      : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
I have done all the coding by myself and only copied the code that my
the professor provided to complete my workshops and assignments.
**********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Basket.h"
using namespace std;
namespace sdds
{

    Basket::Basket()
    {
        setEmpty();
    }

    Basket::Basket(Fruit *fruit, int arrSize, double price)
    {
        setEmpty();
        Fruit *temp = nullptr;
        temp = new Fruit[arrSize + 1];
        if (arrSize > 0 && fruit != nullptr)
        {
            for (int i = 0; i < arrSize; i++)
            {
                temp[i] = fruit[i];
            }
            m_fruits = temp;
            m_cnt = arrSize;
            m_price = price;
        }
    }

    Basket::Basket(const Basket &toCopy)
    {
        if (toCopy.m_fruits != nullptr)
        {
            if (*this != toCopy)
            {
                Fruit *temp = nullptr;
                temp = new Fruit[toCopy.m_cnt + 1];
                if (toCopy.m_cnt > 0 && toCopy.m_fruits != nullptr)
                {
                    for (int i = 0; i < toCopy.m_cnt; i++)
                    {
                        temp[i] = toCopy.m_fruits[i];
                    }
                    m_fruits = temp;
                    m_cnt = toCopy.m_cnt;
                    m_price = toCopy.m_price;
                }
            }
        }
    }

    Basket &Basket::operator=(const Basket &toAssign)
    {
        Fruit *temp = nullptr;
        temp = new Fruit[toAssign.m_cnt + 1];
        if (*this != toAssign)
        {
            if (toAssign.m_cnt > 0 && toAssign.m_fruits != nullptr)
            {
                for (int i = 0; i < toAssign.m_cnt; i++)
                {
                    temp[i] = toAssign.m_fruits[i];
                }
                delete[] m_fruits;
                m_fruits = nullptr;
                m_fruits = new Fruit[toAssign.m_cnt + 1];
                for (int i = 0; i < toAssign.m_cnt; i++)
                {
                    m_fruits[i] = temp[i];
                }
                m_cnt = toAssign.m_cnt;
                m_price = toAssign.m_price;
            }
            else
            {
                setEmpty();
            }
        }
        delete[] temp;
        temp = nullptr;
        return *this;
    }

    Basket::~Basket()
    {
        setEmpty();
    }

    void Basket::setPrice(double price)
    {
        m_price = price;
    }

    Basket::operator bool() const
    {
        return m_fruits != nullptr;
    }

    Basket &Basket::operator+=(const Fruit ro)
    {
        Fruit *temp = nullptr;
        temp = new Fruit[m_cnt + 1];
        for (int i = 0; i < m_cnt; i++)
        {
            temp[i] = m_fruits[i];
        }
        m_cnt++;
        temp[m_cnt - 1] = ro;
        delete[] m_fruits;
        m_fruits = nullptr;
        m_fruits = temp;
        return *this;
    }

    std::ostream &Basket::display(std::ostream &ostr) const
    {

        if (m_fruits && m_cnt > 0)
        {
            cout << "Basket Content:" << endl;
            for (int i = 0; i < m_cnt; i++)
            {
                cout.width(10);
                cout.setf(ios::right);
                cout << m_fruits[i].m_name << ": ";
                cout.setf(ios::fixed);
                cout.precision(2);
                cout << m_fruits[i].m_qty << "kg" << endl;
            }
            cout << "Price: " << m_price << endl;
        }
        else
        {
            cout << "The basket is empty!" << endl;
        }
        return ostr;
    }

    void Basket::setEmpty()
    {
        delete[] m_fruits;
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0.0;
    }

    std::ostream &operator<<(std::ostream &ostr, const Basket &B)
    {
        return B.display(ostr);
    }

}