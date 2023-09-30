/********************************************************************
                        Workshop 3 part 2
Full Name  : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
********************************************************************/

#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_
#define MAX_TITLE_CHAR 20

namespace sdds
{
    class Bar
    {
        char m_Title[MAX_TITLE_CHAR + 1]{};
        char m_fillCh{};
        int m_sample{};
        bool m_valid = false;

    public:
        void set(const char *title, const char bar, int length);
        void draw() const;
        bool validBar();
        void emptyBar();
    };
}

#endif // !SDDS_BAR_H_