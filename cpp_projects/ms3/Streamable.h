/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Jagraj Singh Benipal
Student ID: 156374217
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
-----------------------------------------------------------*/
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>
#include "Date.h"
namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable(){};
    };

    std::ostream &operator<<(std::ostream &ostr, const Streamable &m);
    std::istream &operator>>(std::istream &is, Streamable &RO);

}
#endif