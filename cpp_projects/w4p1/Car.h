/**********************************************************************
                        Workshop 4 part 1
Full Name   :Jagraj Singh Benipal
Student ID# :156374217
Email       :jbenipal1@myseneca.ca
Section     : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
**********************************************************************/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

namespace sdds
{
    class Car
    {
        char *m_type;
        char *m_brand;
        char *m_model;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();
        void deallocate();

    public:
        Car();

        Car(const char *type,
            const char *brand,
            const char *model,
            int year = 2022,
            int code = 100,
            double price = 1);

        Car &setInfo(const char *type,
                     const char *brand,
                     const char *model,
                     int year,
                     int code,
                     double price);

        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car &car) const;
        ~Car();
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}

#endif // !SDDS_CAR_H_