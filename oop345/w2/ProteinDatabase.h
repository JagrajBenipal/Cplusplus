///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: JAN 29, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef PROTEINDATABASE_H
#define PROTEINDATABASE_H
#include <iostream>
#include <string>

namespace sdds
{
    class ProteinDatabase
    {
        std::string *m_string{};
        unsigned int m_numOfStrings{};

    public:
        ProteinDatabase();
        ProteinDatabase(const char *fileName);
        ProteinDatabase(const ProteinDatabase &other);
        ProteinDatabase(ProteinDatabase &&other) noexcept;
        ProteinDatabase &operator=(const ProteinDatabase &other);
        ProteinDatabase &operator=(ProteinDatabase &&other) noexcept;
        ~ProteinDatabase();
        size_t size() const;
        std::string operator[](size_t idx) const;
    };
}
#endif