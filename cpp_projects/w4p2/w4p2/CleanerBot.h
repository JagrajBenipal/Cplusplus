/********************************************************************
Workshop 4 Part 2
Name: Jagraj Singh Benipal
Student ID :156374217
Email:  I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************/

#ifndef SDDS_CLEANERBOT_H_
#define SDDS_CLEANERBOT_H_

namespace sdds
{
    class CleanerBot
    {
        char *m_location;
        double m_battery;
        int m_brush;
        bool m_active;
        void resetInfo();
        void deallocate();

    public:
        CleanerBot();
        CleanerBot(const char *Location, double Battery, int Brush, bool Active);

        CleanerBot &set(const char *location,
                        double battery,
                        int brush,
                        bool active);

        char *setLocation(const char *Location);
        bool setActive(bool Active);

        char *getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;

        ~CleanerBot();
    };

    int report(CleanerBot *bot, short num_bots);
}

#endif // !SDDS_CLEANERBOT_H_