//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include <iostream>
#include "Item.h"

namespace sdds {

class NonPerishable : public Item {


public:

	
	char itemType() const override;

	std::ostream& write(std::ostream& os) const override;
};

}

#endif

