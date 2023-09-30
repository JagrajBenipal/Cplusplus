/*
*********************************************************************
Name : Jagraj Singh Benipal
Student ID: 156374217
Email: jbenipal1@myseneca.ca
Date: May 27, 2022
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*********************************************************************
*/
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

namespace sdds
{

    struct Student
    {
        char *m_name;
        int m_studentNumber;
        char m_grade;
    };

    void sort();
    bool load(const char filename[]);
    bool load(Student &std);
    void display(Student &std);
    void display();
    void deallocateMemory();

}
#endif