///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 12, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef TOY_H
#define TOY_H
#include <string>
namespace sdds
{
    class Toy
    {
        unsigned int order_id{};
        std::string name{};
        unsigned int itemNum{};
        double price{};
        unsigned int hst{13};
        void trim(std::string &string);

    public:
        Toy(){};

        Toy(const Toy &toy);

        void update(int numItems) { itemNum = numItems; };

        Toy(const std::string &toy);

        friend std::ostream &operator<<(std::ostream &ostr, const Toy &toy);

        operator bool() const;
    };
}
#endif // !TOY_H