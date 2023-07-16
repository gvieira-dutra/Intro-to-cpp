//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {

	class Perishable : public Item{

		Date my_Date;

	public:

		char itemType() const override;

		std::istream& read(std::istream& is) override;

		std::ostream& write(std::ostream& os) const override;

		std::ifstream& load(std::ifstream& ifstr) override;

		std::ofstream& save(std::ofstream& sv) const override;


	};


}

#endif