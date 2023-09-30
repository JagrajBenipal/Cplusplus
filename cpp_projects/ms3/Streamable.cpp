/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.cpp
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

#include <iostream>
#include "Streamable.h"

namespace sdds
{
    std::ostream &operator<<(std::ostream &ostr, const Streamable &m)
    {
        if (m)
            m.write(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream &is, Streamable &RO)
    {
        return RO.read(is);
    }

}
