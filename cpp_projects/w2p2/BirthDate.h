/*--------------------------------------------------------------------
Name: Jagraj Singh Benipal
Student ID: 156374217
Email: jbenipal1@myseneca.ca
Date: May 30th, 2022
I have done all the coding by myself and only copied the code that
 my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------*/

#ifndef SDDS_BIRTHDATE_H_
#define SDDS_BIRTHDATE_H_

namespace sdds
{

        struct Birthday
        {
                char *m_name;
                int month;
                int day;
                int year;
                bool matchRecord;
        };

        bool beginSearch(const char filename[]);
        int noOfRecords();
        bool readBirthDate(int month);
        void sort();
        void displayBirthdays();
        void deallocate();
        void endSearch();
        bool read(char *name, int index);
        bool read(int *month, int i);
        bool read(char flag, int *day);
        bool read(int *year, bool check);
}

#endif // !SDDS_BIRTHDATE_H_