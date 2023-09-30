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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char *stdName);
	bool read(int &stdNumber);
	bool read(char &gd);
}
#endif // !SDDS_FILE_H_