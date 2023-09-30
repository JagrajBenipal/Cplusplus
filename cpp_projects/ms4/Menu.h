/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
#define MAX_MENU_ITEMS 20
#define MAX_TITLE 200
namespace sdds
{
    class MenuItem
    {
        char *m_content{};
        int m_length{};
        friend class Menu;
        MenuItem();
        //~MenuItem();
        // MenuItem(const MenuItem& toCopy) = delete;
        // MenuItem& operator=(const MenuItem& toAssign) = delete;
        void setEmpty();
        operator bool() const;
        operator const char *() const;
    };
    class Menu
    {
        // MenuItem m_title{};
        char m_title[MAX_TITLE + 1];
        MenuItem *m_array{};
        int m_arrSize{};

    public:
        Menu();
        Menu(const char *cStr);
        ~Menu();
        // Menu(const Menu& toCopy) = delete;
        // Menu& operator=(const Menu& toAssign) = delete;
        void setMenuEmpty();
        operator bool() const;
        std::ostream &mDisplay(std::ostream &ostr = std::cout) const;
        std::ostream &disTitle(std::ostream &ostr = std::cout) const;
        int run();
        int operator~();
        Menu &operator<<(const char *menuitemContent);
        operator int() const;
        operator unsigned int() const;
        const char *operator[](int index) const;
    };
    std::ostream &operator<<(std::ostream &ostr, const Menu &m);
}
#endif