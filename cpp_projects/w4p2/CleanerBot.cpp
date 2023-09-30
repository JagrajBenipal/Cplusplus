/********************************************************************
Workshop 4 Part 2
Name: Jagraj Singh Benipal
Student ID :156374217
Email:  I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <iomanip>
#include "CleanerBot.h"

using namespace std;

namespace sdds
{
    void CleanerBot::resetInfo()
    {

        m_location = nullptr;
        m_battery = 0.0;
        m_brush = 0;
        m_active = false;
    }

    void CleanerBot::deallocate()
    {

        delete[] m_location;
        m_location = nullptr;
        m_battery = 0;
        m_brush = 0;
        m_active = false;
    }

    CleanerBot::CleanerBot()
    {
        resetInfo();
    }

    CleanerBot::CleanerBot(const char *Location, double Battery, int Brush, bool Active)
    {

        set(Location, Battery, Brush, Active);
    }

    CleanerBot &CleanerBot::set(const char *location, double battery, int brush, bool active)
    {
        if (location != nullptr && location[0] != '\0' && battery > 0.0 && brush > 0)
        {
            m_location = setLocation(location);
            m_battery = battery;
            m_brush = brush;
            m_active = setActive(active);
        }
        else
            resetInfo();
        return *this;
    }

    char *CleanerBot::setLocation(const char *Location)
    {
        char *temp = nullptr;
        temp = new char[strlen(Location) + 1];
        strcpy(temp, Location);
        return temp;
    }

    bool CleanerBot::setActive(bool Active)
    {
        bool tmpAct = false;
        tmpAct = Active;
        return tmpAct;
    }

    char *CleanerBot::getLocation() const
    {
        return m_location;
    }

    double CleanerBot::getBattery() const
    {
        return m_battery;
    }

    int CleanerBot::getBrush() const
    {
        return m_brush;
    }

    bool CleanerBot::isActive() const
    {
        return m_active;
    }

    bool CleanerBot::isValid() const
    {
        if (m_location != nullptr && m_location[0] != '\0' && m_battery > 0.0 && m_brush > 0)
        {
            return true;
        }
        return false;
    }

    void CleanerBot::display() const
    {
        cout << "| ";
        cout.width(10);
        cout.setf(ios::left);
        cout << getLocation();
        cout << " | ";
        cout.width(7);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << getBattery();
        cout << " | ";
        cout.width(18);
        cout << getBrush();
        cout << " | ";
        cout.width(6);
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        if (isActive())
        {
            cout << "YES";
        }
        else
            cout << "NO";
        cout << " |";
        cout << endl;
    }

    CleanerBot::~CleanerBot()
    {
        deallocate();
    }

    int report(CleanerBot *bot, short num_bots)
    {

        int counter = 0;
        CleanerBot temp;
        cout << setw(41) << "------ Cleaner Bots Report -----" << endl;
        cout << setw(44) << "---------------------------------------" << endl;
        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;

        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                bot[i].display();
                if (bot[i].getBattery() < 30)
                {
                    counter++;
                }
            }
        }

        cout << endl;
        cout << setw(52) << "|====================================================|" << endl;
        cout << setw(52) << "| LOW BATTERY WARNING:                               |" << endl;
        cout << setw(52) << "|====================================================|" << endl;
        cout << "| Number of robots to be charged: " << counter << "                  |" << endl;
        cout << "| Sorting robots based on their available power:     |" << endl;

        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;

        for (int i = 0; i < num_bots; i++)
        {
            for (int j = i + 1; j < num_bots; j++)
            {
                if (bot[i].getBattery() < bot[j].getBattery())
                {
                    temp = bot[i];
                    bot[i] = bot[j];
                    bot[j] = temp;
                }
            }
            if (bot[i].isValid())
            {
                bot[i].display();
            }
        }
        cout << setw(52) << "|====================================================|" << endl;
        return 0;
    }

}