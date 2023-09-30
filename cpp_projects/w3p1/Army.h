/***********************************************************************
Full Name  :  Jagraj Singh Benipal
Student ID#:  156374217
Email      :  jbenipal1@myseneca.ca
Section    :  ZBB
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
************************************************************************/

#ifndef SDDS_ARMY_H_
#define SDDS_ARMY_H_
#define MAX_NAME_LEN 50
namespace sdds {

    class Army {
    private:
        char m_nationality[MAX_NAME_LEN+1] = {};
        int m_noUnits = 0;
        double m_power = 0.00;
    public:
        void setEmpty();
        void createArmy(const char* country, double pow, int troops);
        void updateUnits(int troops);
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army& army)const;
    };
    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}


#endif // !SDDS_ARMY_H_