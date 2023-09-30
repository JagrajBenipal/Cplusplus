///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 12, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef CHILD_H
#define CHILD_H
#include "Toy.h"
namespace sdds
{
    class Child
    {
        std::string m_name{};
        unsigned int m_age{};
        size_t toyNum{};
        const sdds::Toy **m_toyArray{};

    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);

        Child(const Child &child);

        void operator=(const Child &child);

        Child(Child &&child) noexcept;

        void operator=(Child &&child) noexcept;

        size_t size() const;

        friend std::ostream &operator<<(std::ostream &ostr, const Child &child);

        ~Child();
    };
}
#endif // !CHILD_H
