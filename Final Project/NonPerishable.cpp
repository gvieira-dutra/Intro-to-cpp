//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#include "NonPerishable.h"

namespace sdds {

	char NonPerishable::itemType() const
	{
		return 'N';
	}

	std::ostream& NonPerishable::write(std::ostream& os) const
	{
		Item::write(os);

		if (this)
		{
			if (diaplayType == POS_LIST && !errorState.operator bool())
			{
				os << "     N / A   |";
			}
			else if (diaplayType == POS_FORM && !errorState.operator bool())
			{
				os << "=============^";
				os << std::endl;
			}
		}
		return os;
	}
}