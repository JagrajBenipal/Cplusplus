/***********************************************************************
Full Name  :  Jagraj Singh Benipal
Student ID#:  156374217
Email      :  jbenipal1@myseneca.ca
Section    :  ZBB
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Army.h"

using namespace std;

namespace sdds {


    void Army::setEmpty() {
        *m_nationality = {};
        m_noUnits = 0;
        m_power = 0;

    }

    void Army::createArmy(const char* country, double pow, int troops) {
        int counter = 0;
        if (country != nullptr) {
            if (country[0] != '\0') {
                counter++;
            }
        }
        else setEmpty();

        if (troops > 0) counter++;
        if (counter == 2) {

            strcpy(m_nationality, country);
            Army::m_noUnits = troops;
            Army::m_power = pow;

        }
        
    }
    void Army::updateUnits(int troops) {
            m_noUnits = m_noUnits + troops;
            m_power = m_power+ troops * 0.25;
    }

    const char* Army::checkNationality() const {
        return m_nationality;
    }

    int Army::checkCapacity() const {
        return m_noUnits;
    }

    double Army::checkPower() const {
        return m_power;
    }

    bool Army::isEmpty() const {
        if (m_nationality != nullptr) {
            if (m_nationality[0] != '\0') {
                if (m_noUnits > 0) {
                    return false;
                }

            }
        }return true;
    }

    bool Army::isStrongerThan(const Army& army)const {
        if (m_power > army.m_power) {
            return true;
        }
        return false;
    }

    void battle(Army& arm1, Army& arm2) {

        if (!arm1.isEmpty() && !arm2.isEmpty()) {
            if (arm1.isStrongerThan(arm2)) {
                cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
                cout << ", " << arm1.checkNationality() << " is victorious!" << endl;
                arm2.updateUnits(-(int)(arm2.checkCapacity()/2));
                
            }
            else {
                cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
                cout << ", " << arm2.checkNationality() << " is victorious!" << endl;
                arm1.updateUnits(-(int)(arm1.checkCapacity()/2));

            }
        }

    }
    void displayDetails(const Army* armies, int size) {
        cout << "Armies reporting to battle: " << endl;
        cout.precision(1);
        for (int i = 0; i < size; i++) {
            if (!armies[i].isEmpty()) {
                cout << "Nationality: " << armies[i].checkNationality();
                cout << ", Units Count: " << armies[i].checkCapacity();
                cout <<fixed<< ", Power left: "  << armies[i].checkPower() << endl;
            }
        }
        


    }


}