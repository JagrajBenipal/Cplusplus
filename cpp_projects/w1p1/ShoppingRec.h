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

#ifndef SHOPPINGREC_H_
#define SHOPPINGREC_H_

const int MAX_TITLE_LENGTH = 50;

namespace sdds {

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}







#endif
