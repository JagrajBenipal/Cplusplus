/*********************************************************************************
Name: Jagraj Singh Benipal
Student mail : jbenipal1@myseneca.ca
Student id: 156374217
I have done all the coding by myself and only copied
the code that my professor provided to complete my workshops and assignments.
**********************************************************************************/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
    class Numbers
    {
        double *m_numbers;
        char *m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty() const;
        void setEmpty();
        void setFilename(const char *filename);
        void sort();
        void save();

    public:
        Numbers();
        Numbers(const char *filename);
        Numbers(const Numbers &toCopy);
        Numbers &operator=(const Numbers &toAssign);
        Numbers &operator+=(const double &ro);
        double average() const;
        double max() const;
        double min() const;
        int numberCount() const;
        bool load();
        ~Numbers();
        std::ostream &display(std::ostream &ostr = std::cout) const;
    };
    std::ostream &operator<<(std::ostream &os, const Numbers &N);
    std::istream &operator>>(std::istream &istr, Numbers &N);
}
#endif // !SDDS_NUMBERS_H_