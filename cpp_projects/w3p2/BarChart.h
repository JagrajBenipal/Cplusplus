/********************************************************************
                        Workshop 3 part 2
Full Name  : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
********************************************************************/

#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_

namespace sdds
{
    class Bar;
    class BarChart
    {
        char *m_charTitle = nullptr;
        Bar *bar = nullptr;
        char m_fillChar{};
        int m_sizeOfBars{}, m_numOfSample{};

    public:
        void init(const char *title, int noOfSampels, char fill);
        void add(const char *bar_title, int value);
        void draw() const;
        void deallocate();
    };
}

#endif // !SDDS_BARCHART_H_