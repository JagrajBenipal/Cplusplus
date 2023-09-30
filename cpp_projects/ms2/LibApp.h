/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
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
#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_
#include "Menu.h"
#include <iostream>
namespace sdds
{
    class LibApp
    {
        bool m_changed;
        Menu m_mainMenu{};
        Menu m_exitMenu{};
        bool confirm(const char *message);
        void load();   // prints: "Loading Data"<NEWLINE>
        void save();   // prints: "Saving Data"<NEWLINE>
        void search(); // prints: "Searching for publication"<NEWLINE>

        void returnPub(); /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
    public:
        void newPublication();
        void removePublication();
        void checkOutPub();
        LibApp();
        void run();
    };
}
#endif