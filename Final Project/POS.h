//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_POS_H
#define SDDS_POS_H
#define MAX_NAME_LEN 40

#define POS_LIST  1
#define POS_FORM  2

namespace sdds {

	const char* const ERROR_POS_SKU = "SKU too long";
	const char* const ERROR_POS_NAME = "Item name too long";
	const char* const ERROR_POS_PRICE = "Invalid price value";
	const char* const ERROR_POS_TAX = "Invalid tax status";
	const char* const ERROR_POS_QTY = "Invalid quantity value";
	const char* const ERROR_POS_STOCK = "Item out of stock";
	const char* const ERROR_POS_EMPTY = "Invalid Empty Item";

	const double TAX = 0.13;
	const int MAX_SKU_LEN = 7;

	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2030;

	const int MAX_STOCK_NUMBER = 99;
	const int MAX_NO_ITEMS = 200;
}

#endif