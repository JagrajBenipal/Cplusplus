///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: JAN 29, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#include "ProteinDatabase.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
namespace sdds
{
    ProteinDatabase::ProteinDatabase()
    {
    }
    ProteinDatabase::ProteinDatabase(const char *fileName)
    {
        string str{};
        unsigned int cnt{};
        ifstream file(fileName);
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, str, '\n');
                if (str[0] == '>')
                    cnt++;
            }
            m_numOfStrings = cnt;
            file.close();
        }
        m_string = new string[m_numOfStrings];

        file.open(fileName);
        for (unsigned int i = 0; i < m_numOfStrings; ++i)
        {
            if (file.is_open())
            {
                getline(file, str, '\n');
                if (str[0] == '>')
                {
                    while (getline(file, str, '\n'))
                    {
                        m_string[i] += str;
                        if (file.peek() == '>')
                            break;
                    }
                }
            }
        }
        file.close();
    }
    ProteinDatabase::ProteinDatabase(const ProteinDatabase &other)
    {
        *this = other;
    }
    ProteinDatabase::ProteinDatabase(ProteinDatabase &&other) noexcept
    {
        *this = move(other);
    }
    ProteinDatabase &ProteinDatabase::operator=(const ProteinDatabase &other)
    {
        if (this != &other)
        {
            m_numOfStrings = other.m_numOfStrings;
            delete[] m_string;
            m_string = new string[m_numOfStrings];
            for (unsigned int i = 0u; i < m_numOfStrings; ++i)
                m_string[i] = other.m_string[i];
        }
        return *this;
    }
    ProteinDatabase &ProteinDatabase::operator=(ProteinDatabase &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_string;
            m_string = other.m_string;
            other.m_string = nullptr;
            m_numOfStrings = other.m_numOfStrings;
            other.m_numOfStrings = 0;
        }
        return *this;
    }
    ProteinDatabase::~ProteinDatabase()
    {
        delete[] m_string;
    }
    size_t ProteinDatabase::size() const
    {
        return m_numOfStrings;
    }
    std::string ProteinDatabase::operator[](size_t idx) const
    {

        string str;
        if (idx > m_numOfStrings - 1 || idx < 0 || !m_string)
        {
            str = "";
        }
        else
        {
            str = m_string[idx];
        }
        return str;
    }
}