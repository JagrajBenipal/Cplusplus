/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
#include "Utils.h"
namespace sdds
{
    MenuItem::MenuItem()
    {
        setEmpty();
    }

    MenuItem::~MenuItem()
    {
        delete[] m_content;
        m_content = nullptr;
        m_length = 0;
    }

    void MenuItem::setEmpty()
    {
        delete[] m_content;
        m_content = nullptr;
        m_length = 0;
    }

    MenuItem::operator bool() const
    {
        return m_content != nullptr;
    }

    MenuItem::operator const char *() const
    {
        return (const char *)m_content;
    }

    Menu::Menu()
    {
        setMenuEmpty();
    }

    Menu::Menu(const char *cStr)
    {
        m_title.m_length = strlen(cStr);
        m_title.m_content = new char[m_title.m_length + 1];
        strcpy(m_title.m_content, cStr);
    }

    Menu::~Menu()
    {
        for (int i = 0; i < m_arrSize; i++)
        {
            delete[] m_array;
            m_array = nullptr;
        }
    }

    void Menu::setMenuEmpty()
    {
        m_title.setEmpty();
        delete[] m_array;
        m_arrSize = 0;
    }

    Menu::operator bool() const
    {
        return m_title != nullptr;
    }

    std::ostream &Menu::mDisplay(std::ostream &ostr) const
    {
        if (m_title != nullptr)
        {
            cout << m_title.m_content << ":" << endl;
            for (int i = 0; i < m_arrSize; i++)
            {
                cout << setw(2);
                cout << right << i + 1;
                cout << "- ";
                cout << m_array[i].m_content << endl;
            }
            cout << setw(2);
            cout << right << 0;
            cout << "- Exit" << endl;
            cout << "> ";
        }
        else
        {
            cout << setw(2);
            cout << right << 1;
            cout << "- ";
            cout << m_array[0].m_content << endl;
            cout << setw(2);
            cout << right << 0;
            cout << "- Exit" << endl;
            cout << "> ";
        }
        return ostr;
    }

    std::ostream &Menu::disTitle(std::ostream &ostr) const
    {
        if (m_title != nullptr)
            cout << m_title.m_content;
        return ostr;
    }

    int Menu::run()
    {
        mDisplay();
        return readInt(0, m_arrSize);
    }

    int Menu::operator~()
    {
        return run();
    }

    Menu &Menu::operator<<(const char *menuitemContent)
    {
        if (m_arrSize + 1 < MAX_MENU_ITEMS)
        {
            if (m_arrSize == 0)
            {
                delete[] m_array;
                m_array = nullptr;
                m_array = new MenuItem[MAX_MENU_ITEMS];
                m_array[0].m_content = new char[strlen(menuitemContent) + 1];
                strcpy(m_array[0].m_content, menuitemContent);
                m_array[0].m_length = strlen(menuitemContent);
                m_arrSize++;
            }
            else
            {
                m_arrSize++;
                m_array[m_arrSize - 1].m_content = new char[strlen(menuitemContent) + 1];
                strcpy(m_array[m_arrSize - 1].m_content, menuitemContent);
            }
        }
        return *this;
    }

    Menu::operator int() const
    {
        return m_arrSize;
    }

    Menu::operator unsigned int() const
    {
        return m_arrSize;
    }

    const char *Menu::operator[](int index) const
    {
        return m_array[index].m_content;
    }

    std::ostream &operator<<(std::ostream &ostr, const Menu &m)
    {
        return m.disTitle(ostr);
    }
}