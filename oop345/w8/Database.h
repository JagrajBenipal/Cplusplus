/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: March 26, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    template <typename T>
    class Database
    {
        // Private Class Member
        static std::shared_ptr<Database> m_database;
        // Private Members
        size_t m_size{0u};
        std::string m_key[20]{};
        T m_value[20];
        std::string m_filename{};
        // Private Constructor
        Database(const std::string &filename)
        {
            std::cout << "[" << this << "] Database(const std::string&)" << std::endl;

            std::ifstream file(filename);
            std::string tempKey{};
            T tempValue{};
            if (file)
            {
                // Get Key
                while (file >> tempKey)
                {
                    // replace _ to ' '
                    replace_if(
                        tempKey.begin(), tempKey.end(), [](char c)
                        { return c == '_'; },
                        ' ');
                    // Get Value
                    file >> tempValue;
                    encryptDecrypt(tempValue);
                    m_key[m_size] = tempKey;
                    m_value[m_size] = tempValue;
                    m_size++;
                }
                m_filename = filename;
            }
        }
        void encryptDecrypt(T &value) {}

    public:
        // Public Class Function
        static std::shared_ptr<Database> getInstance(const std::string &filename)
        {
            if (!m_database)
            {
                m_database = std::shared_ptr<Database>(new Database(filename));
            }
            return m_database;
        }
        // Public Members
        Err_Status GetValue(const std::string &key, T &value)
        {
            for (size_t i = 0; i < m_size; i++)
            {
                if (m_key[i] == key)
                {
                    value = m_value[i];
                    return Err_Status::Err_Success;
                }
            }
            return Err_Status::Err_NotFound;
        }
        Err_Status SetValue(const std::string &key, const T &value)
        {
            if (m_size < 20)
            {
                m_key[m_size] = key;
                m_value[m_size] = value;
                m_size++;
                return Err_Status::Err_Success;
            }
            return Err_Status::Err_OutOfMemory;
        }
        ~Database()
        {
            std::cout << "[" << this << "] ~Database()" << std::endl;
            // write a new file for output
            std::string outFilename = m_filename + ".bkp.txt";
            std::ofstream outFile(outFilename);
            for (size_t i = 0; i < m_size; i++)
            {
                encryptDecrypt(m_value[i]);
                outFile << std::left << std::setw(25) << m_key[i] << " -> " << m_value[i] << std::endl;
            }
        }
    };
    // Declare static
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::m_database = nullptr;

    // Specialization
    template <>
    void Database<std::string>::encryptDecrypt(std::string &str)
    {
        const char secret[]{"secret encryption key"};

        for (size_t i = 0; i < str.size(); i++)
        {
            for (size_t j = 0; j < strlen(secret); j++)
            {
                str[i] = str[i] ^ secret[j];
            }
        }
    }
    template <>
    void Database<long long>::encryptDecrypt(long long &num)
    {
        const char secret[]{"super secret encryption key"};

        for (size_t i = 0; i < sizeof(num); i++)
        {
            for (size_t j = 0; j < strlen(secret); j++)
            {
                reinterpret_cast<char *>(&num)[i] = reinterpret_cast<char *>(&num)[i] ^ secret[j];
            }
        }
    }
}
#endif