/**********************************************************************
                        Workshop 4 part 1
Full Name   :Jagraj Singh Benipal
Student ID# :156374217
Email       :jbenipal1@myseneca.ca
Section     : ZBB
I have done all the coding by myself and only copied the code that my
 professor provided to complete my workshops and assignments.
**********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Car.h"

using namespace std;

namespace sdds {
    void Car::resetInfo(){
        m_type = nullptr; m_brand = nullptr; m_model = nullptr;
        m_year = 0; m_code = 0; m_price = 0;
    }

    Car::Car(){
        resetInfo();
    }

    Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price){
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);

            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);

            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
 
            m_year = year;
            m_code = code;
            m_price = price;
           
    }

    Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price){
        deallocate();
        if (type && brand && model && year >= 1990 && code >= 100 && price > 0) {

            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);

            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);

            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);

            m_year = year;
            m_code = code;
            m_price = price;


        } else resetInfo();

        return *this;
    }

    void Car::printInfo() const{
        cout << "| ";
        cout.width(10);
        cout.setf(ios::left);
        cout << m_type;
        cout << " | ";
        cout.width(16);
        cout.setf(ios::left);
        cout << m_brand;
        cout << " | ";
        cout.width(16);
        cout.setf(ios::left);
        cout << m_model;
        cout << " | ";
        cout.width(4);
        cout.setf(ios::left);
        cout << m_year;
        cout << " |  ";
        cout.width(3);
        cout.setf(ios::left);
        cout << m_code;
        cout << " |";
        cout.width(10);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << m_price;
        cout << " |";
        cout << endl;
        cout.unsetf(ios::right);
        cout.unsetf(ios::left);
    }

    bool Car::isValid() const{
        if (m_type!=nullptr&&m_type[0]!='\0' && m_brand != nullptr && m_brand[0] != '\0' && m_model != nullptr && m_model[0] != '\0' && m_year >= 1990 && m_code >= 100 && m_code<1000 && m_price > 0) {
                return true;
        }
        return false;
    }

    bool Car::isSimilarTo(const Car& car) const{

        if (isValid() && car.isValid()) {
            if (strcmp(m_brand, car.m_brand) || strcmp(car.m_type, m_type) || strcmp(car.m_model, m_model) || car.m_year == m_year || car.m_price == m_price || car.m_code == m_code)
                return true;

        }
        return false;

    }

    Car::~Car(){
        deallocate();
    }

    bool has_similar(const Car car[], const int num_cars){
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return true;
                }
            }
        }return false;
    }    

    bool has_invalid(const Car car[], const int num_cars){
        int counter = 0;
        for (int i = 0; i < num_cars; i++) {
            if (!car[i].isValid())
                counter++;
        }
        if (counter > 0) return true;
        return false;
    }

    void print(const Car car[], const int num_cars){
        for (int i = 0; i < num_cars; i++) {
            if(car[i].isValid())
            car[i].printInfo();
        }

    }

    void Car::deallocate(){
        delete[] m_type;
        m_type = nullptr;
        delete[] m_brand;
        m_brand = nullptr;
        delete[] m_model;
        m_model = nullptr;
    }

}