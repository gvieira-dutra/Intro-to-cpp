#include <iomanip>
#include <string>
#include "Contact.h"

using namespace std;

namespace sdds {
	
	Contact::Contact() :Person() {}
	Contact::Contact(const Contact& copyFrom)
	{
		if (this)
			operator=(copyFrom);
	}

	Contact& Contact::operator=(const Contact& RightOperand)
	{
		if (this != &RightOperand)
		{
			Person::operator=(RightOperand);
			delAlloCopy(Address, RightOperand.Address);
			delAlloCopy(City, RightOperand.City);
			strCpy(Province, RightOperand.Province);
			strCpy(Postal, RightOperand.Postal);
		}
		return *this;
	}

	Contact::~Contact()
	{
		~*this;
	}

	std::istream& Contact::read(std::istream& istr)
	{
		string input;

		Person::read(istr);
		Address = dynRead(istr, ',');
		City = dynRead(istr, ',');
		
		getline(istr, input, ',');
		if (input.length() > 2) {
			istr.setstate(ios::failbit);
		}
		else
		{
			int size = input.length();
			for (int i = 0; i < size; i++)
			{
				Province[i] = input[i];
			}
			Province[3] = '\0';
		}

		getline(istr, input);
		if (input.length() > 6) {
			//istr.setstate(ios::failbit);
		}
		else
		{
			int size = input.length();
			for (int i = 0; i < size; i++)
			{
				Postal[i] = input[i];
			}
			Postal[7] = '\0';
		}

		if (istr.fail()) ~*this;
		return istr;

	}

	std::ostream& Contact::write(std::ostream& ostr) const
	{
		if (*this) {
			Person::write(ostr);
			ostr << endl;
			ostr << Address;
			ostr << endl;
			ostr << City << ' ' << Province;
			ostr << endl;
			for (int i = 0; i < strLen(Postal); i++)
			{
				if (i == 3)
				{

					ostr << ' ';
					ostr << Postal[i];
				}
				else
					ostr << Postal[i];
			}
			ostr << endl;

		}
		return ostr;

	}

	Contact::operator bool() const
	{
		return Person::operator bool() && Address && Address[0] && City && City[0] && Province && Province[0] && Postal && Postal[0];
	}

	void Contact::operator~() 
	{
		Person::operator~();
		delete[] Address;
		delete[] City;
		Address = City = nullptr;
	}

}
