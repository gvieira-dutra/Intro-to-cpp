//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include <iostream>
#include "POS.h"
#include "Error.h"

namespace sdds {

	class Date {
		int year = 0;
		int month = 0;
		int day = 0;
		int hour = 0;
		int minute = 0;
		bool mDateOnly = false;

		Error m_error;

	public:
		//Default constructor
		Date();
		//Overload constructor for year, month and day only
		Date(int yr, int mth, int dy);

		//Overload constructor for all attributes of data
		Date(int yr, int mth, int dy, int hr, int min = 0);

		//This function will validate the dates after they are set.
		void validate(int yr, int mth, int dy);

		//This overload function will validate the dates after they are set.
		void validate(int yr, int mth, int dy, int hr, int min);

		//This function will determine how the max number of day a month can have 
		int daysOfMonth(int year, int month) const;

		//The following function retrieves the current date and time of the system and returns them through the argument list.
		void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);

		//Comparison Operator Overloads

		// == operator overload, will return true if objects are equal.
		bool operator==(const Date& rhs) const;

		// != operator overload, will return true if objects are different
		bool operator!=(const Date& rhs) const;

		// < operator overload, will return true if the current object's date is older than rhs date
		bool operator<(const Date& rhs) const;

		// > operator overload, will return true if the current object date is more recent than rhs
		bool operator>(const Date& rhs) const;

		// <= operator overload, will return true if this date is more older or equal to rhs
		bool operator<=(const Date& rhs) const;

		// >= operator overload, will return true if this date is older more recent or equal to rhs
		bool operator >=(const Date& rhs) const;

		// This method should set the date-only flag to the value received from the argument of the function.
		Date& dateOnly(bool flag);
	
		// Boolean overload operator will return the opposite of the state of the error attribute.
		operator bool() const;

		// This method will return a const reference to the error object
		 const Error& error() const;

		//This function will return True if the date is date Only, false if not. 
		bool isDateOnly();

		//This function will clear the error object and set all time attributes to 0
		void setEmpty(Date& rhs);

		//Will print the class info in the screen
	    void display(std::ostream& os) const;

		//Will read user input
		void read(std::istream& is);
	
		//This function will set the error message
		void setErrorMessage(Date& rhs, const char* msg);

		// Copy sign overload
		Date& operator=(const Date& rhs);

		const char* getDateErrorMsg() const;

		int getYear() const;
		int getMonth() const;
		int getDay() const;
	
	};

	 //HELPER FUNCTIONS 
	// >> the insertion operator overload will insert Date into the ostream object
	std::ostream& operator<<(std::ostream& os, Date& rhs);
	 
	// << the extraction operator overload will read a date from istream in the same format it is printed
	std::istream& operator>>(std::istream& is, Date& rhs);

}

#endif