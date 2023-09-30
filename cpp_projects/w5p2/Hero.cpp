/***********************************************************************
                        Workshop 5 part 2
 Name      : Jagraj Singh Benipal
Student ID#: 156374217
Email      : benipal2003@gmail.com
Section    : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Hero.h"
#include "Power.h"

using namespace std;

namespace sdds
{

    Hero::Hero()
    {
        this->initHero();
    }

    Hero::Hero(const char *name, Power *pwrHero, int count)
    {
        if (name && name[0] != '\0' && count > 0 && pwrHero != nullptr)
        {
            strncpy(this->m_hero_name, name, MAX_NAME_LENGTH);
            m_hero_power = new Power[count];
            for (int i = 0; i < count; i++)
            {
                m_hero_power[i] = pwrHero[i];
            }
            m_num_power = count;
            m_power_lvl = calPwrLvl();
        }
        else
        {
            this->initHero();
        }
    }

    Hero::~Hero()
    {
        this->initHero();
    }

    int Hero::calPwrLvl()
    {
        int total = 0, rarity = 0;
        for (int i = 0; i < m_num_power; i++)
        {
            rarity += m_hero_power[i].checkRarity();
        }
        total = rarity * m_num_power;
        return total;
    }

    void Hero::initHero()
    {
        m_hero_name[0] = '\0';
        delete[] m_hero_power;
        m_hero_power = nullptr;
        m_num_power = 0;
        m_power_lvl = 0;
    }

    std::ostream &Hero::display(std::ostream &os) const
    {
        cout << "Name: " << m_hero_name << endl;
        cout << "List of available powers: " << endl;
        for (int i = 0; i < m_num_power; i++)
        {
            cout << "  Name: " << m_hero_power[i].checkName() << ", Rarity: " << m_hero_power[i].checkRarity() << endl;
        }
        cout << "Power Level: " << m_power_lvl;
        return os;
    }

    Hero &Hero::operator+=(Power &addPower)
    {
        Power *temp = nullptr;
        temp = new Power[m_num_power + 1];
        for (int i = 0; i < m_num_power; i++)
        {
            temp[i] = m_hero_power[i];
        }
        delete[] m_hero_power;
        m_hero_power = nullptr;
        m_hero_power = new Power[++m_num_power];
        for (int i = 0; i < m_num_power; i++)
        {
            m_hero_power[i] = temp[i];
        }
        delete[] temp;
        temp = nullptr;
        m_hero_power[m_num_power - 1] = addPower;
        m_power_lvl = calPwrLvl();
        return *this;
    }

    Hero &Hero::operator-=(int minusLvl)
    {
        this->m_power_lvl = this->m_power_lvl - minusLvl;
        return *this;
    }

    std::ostream &operator<<(std::ostream &ostr, const Hero &hero)
    {
        return hero.display(ostr);
    }

    bool operator<(Hero &fh, Hero &sh)
    {
        if (fh.calPwrLvl() < sh.calPwrLvl())
            return true;
        return false;
    }

    bool operator>(Hero &fh, Hero &sh)
    {
        if (fh.calPwrLvl() > sh.calPwrLvl())
            return true;
        return false;
    }

    Hero &operator>>(Power &lp, Hero &rh)
    {
        rh += lp;
        return rh;
    }

    Hero &operator<<(Hero &lh, Power &rp)
    {
        lh += rp;
        return lh;
    }

}