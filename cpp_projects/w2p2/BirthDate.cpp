/*--------------------------------------------------------------------
Name: Jagraj Singh Benipal
Student ID: 156374217
Email: jbenipal1@myseneca.ca
Date: May 30th, 2022
I have done all the coding by myself and only copied the code that
 my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "BirthDate.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#define NAME_SIZE 200
using namespace std;

namespace sdds
{
        FILE *fptr;
        int numRecords = 0, match = 0;
        Birthday *birthday = nullptr;
        Birthday *temp = nullptr;

        bool beginSearch(const char filename[])
        {
                fptr = fopen(filename, "r");
                if (fptr != NULL)
                {
                        cout << "Birthdate search program" << endl;
                        return true;
                }
                else
                {
                        cout << "Data file " << filename << " not found!" << endl;
                        return false;
                }
        }

        int noOfRecords()
        {
                int noOfRecs = 0;
                char ch;
                while (fscanf(fptr, "%c", &ch) == 1)
                {
                        noOfRecs += (ch == '\n');
                }
                rewind(fptr);
                return noOfRecs;
        }

        bool read(char *name, int index)
        {
                if (fptr)
                {
                        if (fscanf(fptr, "%[^,],", name))
                        {
                        }
                        return true;
                }
                else
                {
                        return false;
                }
        }

        bool read(int *month, int i)
        {
                if (fptr)
                {
                        if (fscanf(fptr, "%d/", month))
                        {
                        }
                        return true;
                }
                else
                {
                        return false;
                }
        }

        bool read(char flag, int *day)
        {
                if (fptr)
                {
                        if (fscanf(fptr, "%d/", day))
                        {
                        }
                        return true;
                }
                else
                {
                        return false;
                }
        }

        bool read(int *year, bool check)
        {
                if (fptr)
                {
                        if (fscanf(fptr, "%d\n", year))
                        {
                        }
                        return true;
                }
                else
                {
                        return false;
                }
        }

        bool readBirthDate(int month)
        {
                match = 0;
                int goodRecord = 0;
                numRecords = noOfRecords();
                temp = new Birthday[numRecords];
                birthday = new Birthday[numRecords];
                char tempName[NAME_SIZE] = {};

                for (int i = 0; i < numRecords; i++)
                {
                        bool nameRead = false, mnthRead = false, dayRead = false, yrRead = false;
                        nameRead = read(tempName, i);
                        if (nameRead)
                        {
                                int nameLength = strlen(tempName);
                                birthday[i].m_name = new char[nameLength + 1];
                                strcpy(birthday[i].m_name, tempName);
                        }
                        mnthRead = read(&temp[i].month, i);
                        birthday[i].month = temp[i].month;
                        dayRead = read('c', &temp[i].day);
                        birthday[i].day = temp[i].day;
                        if (birthday[i].month == month)
                        {
                                birthday[i].matchRecord = true;
                                match++;
                        }
                        else
                                birthday[i].matchRecord = false;
                        yrRead = read(&temp[i].year, true);
                        birthday[i].year = temp[i].year;
                        if ((nameRead == true) && (mnthRead == true) && (dayRead == true) && (yrRead == true))
                        {
                                goodRecord++;
                        }

                        /*if (birthday[i].matchRecord == true) {
                                cout << birthday[i].m_name << birthday[i].month << birthday[i].day << birthday[i].year << endl;
                        }*/
                }
                if (match > 0)
                {
                        delete[] temp;
                        temp = nullptr;
                        return true;
                }
                return false;
        }

        void sort()
        {
                int i, j;
                Birthday temp;
                for (i = numRecords - 1; i > 0; i--)
                {
                        for (j = 0; j < i; j++)
                        {
                                if (birthday[j].year > birthday[j + 1].year)
                                {
                                        temp = birthday[j];
                                        birthday[j] = birthday[j + 1];
                                        birthday[j + 1] = temp;
                                }
                        }
                }
        }

        void displayBirthdays()
        {
                int j = 1;
                sort();
                cout << match << " birthdates found:" << endl;
                for (int i = 0; i < numRecords; i++)
                {
                        if (birthday[i].matchRecord == true)
                        {
                                cout << j << ") " << birthday[i].m_name << ":" << endl;
                                cout << birthday[i].year << "-" << birthday[i].month << "-" << birthday[i].day << endl;
                                cout << "===================================" << endl;
                                j++;
                        }
                        delete[] birthday[i].m_name;
                }
        }

        void deallocate()
        {
                delete[] birthday;
                birthday = nullptr;
        }

        void endSearch()
        {
                if (fptr)
                {
                        cout << "Birthdate Search Program Closed." << endl;
                        fclose(fptr);
                }
        }

}