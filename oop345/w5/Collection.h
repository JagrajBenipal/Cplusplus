/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: February 19, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"
#include "Movie.h"

namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string m_nameOfCollection{};
        T *m_arrayItem{};
        size_t m_cnt{};

    public:
        void (*observer_f)(const Collection<T> &, const T &){};
        Collection(const std::string &name) : m_nameOfCollection{name}
        {
        }

        Collection(const Collection &other) = delete;
        Collection &operator=(const Collection &other) = delete;
        ~Collection()
        {
            delete[] m_arrayItem;
        }

        const std::string &name() const
        {
            return m_nameOfCollection;
        }

        size_t size() const
        {
            return m_cnt;
        }
        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            observer_f = observer;
        }

        Collection<T> &operator+=(const T &item)
        {
            bool exit = false;
            for (auto i = 0u; i < m_cnt; ++i)
            {
                if (m_arrayItem[i].title() == item.title())
                    exit = true;
            }

            if (!exit)
            {
                if (m_cnt == 0)
                {
                    m_arrayItem = new T[++m_cnt];
                    m_arrayItem[0] = item;
                }
                else
                {
                    T *tmp = new T[m_cnt];
                    for (auto i = 0u; i < m_cnt; ++i)
                    {
                        tmp[i] = m_arrayItem[i];
                    }
                    delete[] m_arrayItem;
                    m_arrayItem = new T[m_cnt + 1];
                    for (auto i = 0u; i < m_cnt; ++i)
                    {
                        m_arrayItem[i] = tmp[i];
                    }
                    m_arrayItem[m_cnt++] = item;
                    delete[] tmp;
                }
                if (observer_f != nullptr)
                    observer_f(*this, item);
            }

            return *this;
        }

        T &operator[](size_t idx) const
        {
            /*try {
                if (idx > m_cnt || idx < m_cnt)
                    throw std::out_of_range;
            }
            catch (std::out_of_range)
            {
                std::cout << "Bad index[" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_cnt) + "] items.";

            }*/
            if (idx >= m_cnt || idx < 0)
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_cnt) + "] items.");
            else
                return m_arrayItem[idx];
        }
        T *operator[](const std::string &title) const
        {
            for (auto i = 0u; i < m_cnt; ++i)
            {
                if (m_arrayItem[i].title() == title)
                    return &m_arrayItem[i];
            }
            return nullptr;
        }

        std::ostream &display(std::ostream &ostr) const
        {
            for (auto i = 0u; i < size(); ++i)
                ostr << m_arrayItem[i];

            return ostr;
        }

        friend std::ostream &operator<<(std::ostream &ostr, const Collection &other)
        {
            return other.display(ostr);
        }
    };
}

#endif