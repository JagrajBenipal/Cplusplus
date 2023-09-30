// Workshop 1:
// Version: 1.0
// Date: 2021/05/21
// Author: Fardad Soleimanloo
// Description:
// w1p1.cpp
//
///////////////////////////////////////////////////

// Name           : Jagraj Singh Benipal
// Student Number : 156374217
// Studentmail id : jbenipal1@myseneca.ca
// Section        : ZBB
// Workshop       : Workshop1
// Date completed : 20 MAY 2022
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef FILE_H_
#define FILE_H_
#include "ShoppingRec.h"

namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}


#endif
