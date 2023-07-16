#ifndef _SDDS_BUS_H
#define _SDDS_BUS_H
#include "iostream"

namespace sdds {

	const double ticketP = 125.34;


	class Bus {
		int seatNum;
		int passengNum;

	public:

		//default constructor
		Bus();

		//1 argument constructor 
		Bus(int passengers);
		

		//2 arguments constructor 
		Bus(int seats, int passengers);

		//passes the arguments to display function
		std::ostream& display(std::ostream& ostr = std::cout) const;

		//Print int bus in the screen
		void displayBus(int pNum, int seats, std::ostream& ostr) const;

		//read user input for passenger number and seats
		std::istream& read(std::istream& istr);

		//Will initialize bus to values given
		void setBus(int seats, int passengers);

		//Will initialize bus to empty
		void setEmpty();

		//boolean conversion operator 
		operator bool() const;

		//integer conversion operator 
		operator int() const;

		//double conversion operator 
		operator double() const;

		//prefix operator--
		bool operator--();

		//prefix operator++
		bool operator++();

		//postfix operator--
		bool operator--(int);

		//postfix operator++
		bool operator++(int);

		//Binary Member Operators
		//Assigning A bus object to an integer value.
		Bus& operator=(int pNum);

		//Adding an integer to a Bus object using += operator
		Bus& operator+=(int pNum);

		//Adding a bus object to another bus object using += operator.
		Bus& operator+=(Bus& right);

		// Comparing two buses using the == operator
		bool operator==(const Bus& right) const;

		//fetch number of passengers
		int fetchpassnum() const;
	};

	//sum of an integer number(at left) and a bus(at right)
	int operator+(int left, const Bus& right);


	std::ostream& operator<<(std::ostream& ostr, const Bus& right);

	std::istream& operator>>(std::istream& istr, Bus& right);


}

#endif