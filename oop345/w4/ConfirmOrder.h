///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: FEB 12, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef CONFIRM_ORDER_H
#define CONFIRM_ORDER_H
namespace sdds
{
    class ConfirmOrder
    {
        const sdds::Toy **m_toyArray{};
        int counter{};

    public:
        ConfirmOrder(){};
        ConfirmOrder(const ConfirmOrder &co);
        void operator=(const ConfirmOrder &co);
        ConfirmOrder(ConfirmOrder &&co) noexcept;
        void operator=(ConfirmOrder &&co) noexcept;
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        friend std::ostream &operator<<(std::ostream &ostr, const ConfirmOrder &co);
        ~ConfirmOrder();
    };

}
#endif // !CONFIRM_ORDER_H