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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
    FILE *fptr;
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
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
    void closeFile()
    {
        if (fptr)
            fclose(fptr);
    }

    bool read(char *stdName)
    {
        bool ok = fscanf(fptr, "%[^,],", stdName);
        return ok;
    }

    bool read(int &stdNumber)
    {
        bool ok = fscanf(fptr, "%d,", &stdNumber);
        return ok;
    }

    bool read(char &gd)
    {
        bool ok = fscanf(fptr, "%c\n", &gd);
        return ok;
    }
}