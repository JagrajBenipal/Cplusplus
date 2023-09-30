/* Citation and Sources...
Final Project Milestone 5
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
#include "Publication.h"
#include "PublicationSelector.h"
#include <iostream>
#define MAX_PUB_FILE_NAME 255

namespace sdds
{
    class LibApp
    {
        char m_filename[MAX_PUB_FILE_NAME + 1]{};
        Publication *m_ppa[SDDS_LIBRARY_CAPACITY]{};
        int m_nolp{};
        int m_llrn{};
        bool m_changed;
        Menu m_mainMenu{};
        Menu m_exitMenu{};
        Menu m_chooseMenu{};
        bool confirm(const char *message);
        void load();                // prints: "Loading Data"<NEWLINE>
        void save();                // prints: "Saving Data"<NEWLINE>
        int search(int searchMode); // prints: "Searching for publication"<NEWLINE>

        void returnPub(); /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
    public:
        void newPublication();
        void removePublication();
        void checkOutPub();
        LibApp(const char *fileName);
        ~LibApp();
        void run();
        Publication *getPub(int libRef) const;
    };
}
#endif