/*********************************************************************
                        Workshop 6 part 2
 Name      : Jagraj Singh Benipal
Student ID#: 156374217
Email      : jbenipal1@myseneca.ca
Section    : ZBB
I have done all the coding by myself and only copied the code that my
the professor provided to complete my workshops and assignments.
**********************************************************************/

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
    namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1];
        double m_qty;        
    };
    class Basket
    {
        Fruit *m_fruits{nullptr};
        int m_cnt{0};
        double m_price{0.0};

    public:
        Basket();
        Basket(Fruit *fruit, int arrSize, double price);
        Basket(const Basket &toCopy);
        Basket &operator=(const Basket &toAssign);
        ~Basket();
        void setPrice(double price);
        operator bool() const;
        Basket &operator+=(const Fruit ro);
        std::ostream &display(std::ostream &ostr = std::cout) const;
        void setEmpty();
    };
    std::ostream &operator<<(std::ostream &ostr, const Basket &B);

}
#endif // !SDDS_BASKET_H_