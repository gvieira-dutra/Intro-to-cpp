//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include "Item.h"
#include "POS.h"
#include "Bill.h"
#include "Date.h"
#include "Perishable.h"
#include "NonPerishable.h"


namespace sdds {
	class PosApp
	{
		char filename[128] = { 0 };
		Item* Iptr[MAX_NO_ITEMS] = { '\0' };
		int nptr = 0;

	public:

		PosApp(const char* name);

		PosApp(const PosApp& source) = delete;
		PosApp& operator=(const PosApp& source) = delete;

		void run();

		void menu(int& usrInput);

		void addItem();
		void removeItem();
		void stockItem();
		void listItems(bool listTotal);
		void POS();
		void saveRecs();
		void loadRecs();
		int selectItem();
		int search(const char* Lsku);
	};

	std::ostream& operator<<(std::ostream& os, const PosApp p);
	std::istream& operator>>(std::istream& is, const PosApp p);
}

#endif