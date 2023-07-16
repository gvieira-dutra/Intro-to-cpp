#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bus.h"
#include <iomanip>
using namespace std;

namespace sdds {
	//default constructor
	Bus::Bus()
	{
		seatNum = 20;
		passengNum = 0;
	}
	
	//1 argument constructor
	Bus::Bus(int passengers)
	{
		seatNum = 20;
		passengNum = passengers;
		if (passengNum > seatNum)
		{
			seatNum = -1;
			passengNum = -1;
		}
	}
	

	//2 arguments constructor
	Bus::Bus(int seats = 20, int pNum = 0)
	{
		if (seats % 2 == 0 && seats > 9 && seats < 41 && pNum >= 0 && pNum <= seats)
		{
			seatNum = seats;
			passengNum = pNum;
		}
		else
		{
			seatNum = -1;
			passengNum = -1;
		}
	}

	std::ostream& Bus::display(std::ostream& ostr) const
	{
		if (seatNum > 0)
		{

		displayBus(passengNum, seatNum, ostr);
		cout << "Total Fare Price: " << fixed << setprecision(2) << passengNum * ticketP;
		cout << endl;
		}
		else
		{
			cout << "Out of service!";
			cout << endl;
		}
		return ostr;
	}

	

	//Print int bus in the screen
	void Bus::displayBus(int pNum, int seats, std::ostream& ostr) const
	{
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < pNum ? '2' : ((p == pNum) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}

	//read user input for passenger number and seats
	istream& Bus::read(istream& istr)
	{
		int seats;
		int pNum;

		cin >> seats;
		cin.ignore();
		cin >> pNum;

		if (seats % 2 == 0 && seats > 9 && seats < 41 && pNum >= 0 && pNum <= seats)
		{
			setBus(seats, pNum);
		}
		else
		{
			setEmpty();
		}

		return istr;
	}

	//Will initialize bus to values given
	void Bus::setBus(int seats, int pNum)
	{
		seatNum = seats;
		passengNum = pNum;
	}

	//Will initialize bus to empty
	void Bus::setEmpty()
	{
		seatNum = 0;
		passengNum = -1;
	}

	//boolean converter operator
	Bus::operator bool() const
	{
		return (seatNum > 0 ? true : false);
	}

	//integer conversion operator 
	Bus::operator int() const
	{
		return (seatNum >= 0 ? passengNum : -1);
	}

	//double conversion operator
	Bus::operator double() const
	{
		return (seatNum > 0 ? passengNum * ticketP : -1.0);
	}

	//prefix operator--
	bool Bus::operator--()
	{
		bool check = true;
		if (*this && passengNum == 0)
		{
			check = false;
		}
		else
		{
			passengNum--;
		}

		return check;
	}

	//prefix operator++
	bool Bus::operator++()
	{
		bool check = true;
		if (*this && passengNum >= seatNum)
		{
			check = false;
		}
		else
		{
			passengNum++;
		}

		return check;
	}

	//postfix operator--
	bool Bus::operator--(int)
	{
		bool check = true;
		if (*this && passengNum == 0)
		{
			check = false;
		}
		else
		{
			passengNum--;
		}

		return check;
	}

	//postfix operator++
	bool Bus::operator++(int)
	{
		bool check = true;
		if (*this && passengNum >= seatNum)
		{
			check = false;
		}
		else
		{
			passengNum++;
		}

		return check;

		return check;
	}

	//Binary Member Operators 
	//Assigning A bus object to an integer value.
	Bus& Bus::operator=(int pNum)
	{
		passengNum = pNum;

		if (passengNum > seatNum)
		{
			passengNum = -1;
			seatNum = 0;
		}

		return *this;
	}

	Bus& Bus::operator+=(int pNum)
	{
		passengNum += pNum;
		if (passengNum > seatNum)
		{
			seatNum = -1;
		}

		return *this;
	}

	Bus& Bus::operator+=(Bus& right)
	{
		int emptySpots;

		if (*this && right)
		{
			emptySpots = seatNum - passengNum;

			if (emptySpots > 0)
			{
				if (right.passengNum > emptySpots) {
					*this += emptySpots;
					right.passengNum -= emptySpots;
				}
				else if (right.passengNum <= emptySpots)
				{
					*this = +right.passengNum;
					right.passengNum = 0;
				}
			}
		}

		return *this;
	}

	bool Bus::operator==(const Bus& right) const
	{
		bool check = false;

		if (*this && right && (this->passengNum == right.passengNum))
		{
			check = true;
		}

		return check;
	}

	int Bus::fetchpassnum() const
	{
		return this->passengNum;
	}


	int operator+(int left, const Bus& right)
	{
		int num = left;

		if (right)
		{
			num += right.fetchpassnum();
		}
		return 0;
	}

	std::ostream& operator<<(std::ostream& ostr, const Bus& right)
	{
		right.display(ostr);

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Bus& right)
	{
		right.read(istr);

		return istr;
	}

} 