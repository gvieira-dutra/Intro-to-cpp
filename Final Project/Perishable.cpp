//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#include <iostream>
#include "Perishable.h"
#include "Date.h"

using namespace std;

namespace sdds {

	
	
	char Perishable::itemType() const 
	{
		return 'P';
	}



	std::istream& Perishable::read(std::istream& is)
	{
		Item::read(is);

		if ((!errorState) && is)
		{
			Date localDate;
			localDate.dateOnly(true);

			cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";

			localDate.read(is);

			if (localDate.operator bool()) {
				my_Date = localDate;
			}
		}

		return is;
	}

	std::ostream& Perishable::write(std::ostream& os) const
	{
		Item::write(os);

		if (this)
		{
			if (diaplayType == POS_LIST && !errorState.operator bool())
			{
				os << "  ";
				my_Date.display(os);
				os << " ";
				os << '|';
			}
			else if (diaplayType == POS_FORM && !errorState.operator bool())
			{
				os << "Expiry date: ";
				my_Date.display(os);
				os << endl;
				os << "=============^" << endl ;
			}
		}
		return os;
	}

	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		Item::load(ifstr);

		if (this && ifstr)
		{
			Date localDate;
			localDate.dateOnly(true);

			ifstr.ignore();

			ifstr >> localDate;

			if (localDate.operator bool())
			{
				my_Date = localDate;
			}
			else
			{
				errorState.setMsg(localDate.getDateErrorMsg());
			}
		}
		return ifstr;
	}

	std::ofstream& Perishable::save(std::ofstream& sv) const
	{
		Item::save(sv);

		if (this)
		{
			sv << ',';
			sv << my_Date.getYear();

			sv << '/';

			if(my_Date.getMonth() > 9)
			sv << my_Date.getMonth();
			else 
				sv << '0' << my_Date.getMonth();

			sv << '/';

			if (my_Date.getDay() > 9)
				sv << my_Date.getDay();
			else
				sv << '0' << my_Date.getDay();
		}
		return sv;
	}


}