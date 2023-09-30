///*
//Name: Jagraj Singh Benipal
//Seneca email: jbenipal1@myseneca.ca
//Student ID: 156374217
//Date: MAY 22, 2022
// I have done all the workshop by myself and have only copied the code provided 
// by professor.
//*

#define _CRT_SECURE_NO_WARNINGS
#include "foodorder.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

double g_taxrate = 0 ;
double g_dailydiscount = 0;


namespace sdds {

	FoodOrder::FoodOrder()
	{
		customerName[0] = 0;
		description = nullptr;
		price = 0.0;
		specialOrNot = false;
	}

	FoodOrder::FoodOrder(const FoodOrder& other) {
		operator=(other);
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& other) {
		if (this != &other) {
			strcpy(customerName, other.customerName);
			price = other.price;
			specialOrNot = other.specialOrNot;
			if (other.description != nullptr)
			{
				description = new char[strlen(other.description) + 1];
				strcpy(description, other.description);
			}
		}
		return *this;
	}

	void FoodOrder::read(std::istream& istr)
	{
		char cString[50];
		string str;
		if (istr.good()) {
			istr.getline(cString, 50, ',');
			strcpy(customerName, cString);
			getline(istr, str, ',');
			delete[] description;
			description = new char[str.length() + 1];
			strcpy(description, str.c_str());
			istr.getline(cString, 50, ',');
			price = atof(cString);
			if (istr.get() == 'Y') {
				specialOrNot = true;
			}
			else {
				specialOrNot = false;
			}
		}
	}

	void sdds::FoodOrder::display()const
	{
		static int cnt = 0;
		cnt++;
		cout.width(2); cout << left << cnt << ". ";
		if (customerName[0] != '\0') {
			cout.width(10); cout << left << customerName;
			cout << "|";
			cout.width(25); cout << left << description;
			cout << "|";
			cout.width(12); cout << left << fixed << setprecision(2) << price + (price * g_taxrate);
			cout << "|";
			if (specialOrNot) {
				cout.width(13); cout << right << (price + (price * g_taxrate)) - g_dailydiscount;
			}
		}
		else {
			cout << "No Order";

		}

		cout << endl;
	}
	FoodOrder::~FoodOrder() {
		delete[] description;
		description = nullptr;
		
	}

}
