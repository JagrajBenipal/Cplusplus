/***********************************************************************
                        Workshop 5 part 2
 Name      : Jagraj Singh Benipal
Student ID#: 156374217
Email      : benipal2003@gmail.com
Section    : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_HERO_H_
#define SDDS_HERO_H_
#include "Power.h"

namespace sdds
{
    class Hero
    {
        char m_hero_name[MAX_NAME_LENGTH + 1];
        Power *m_hero_power;
        int m_num_power = 0;
        int m_power_lvl = 0;

    public:
        Hero();
        Hero(const char *name, Power *pwrHero, int count);
        ~Hero();
        int calPwrLvl();
        void initHero();
        std::ostream &display(std::ostream &os = std::cout) const;
        Hero &operator+=(Power &addPower);
        Hero &operator-=(int minusLvl);
    };
    std::ostream &operator<<(std::ostream &ostr, const Hero &hero);
    bool operator<(Hero &fh, Hero &sh);
    bool operator>(Hero &fh, Hero &sh);
    Hero &operator>>(Power &lp, Hero &rh);
    Hero &operator<<(Hero &lh, Power &rp);
}

#endif