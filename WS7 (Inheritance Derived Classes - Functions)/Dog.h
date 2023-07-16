#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include "Pet.h"

namespace sdds {
	class Dog : public Pet {

		const double DOG_COST_BASE = 4.00;		// Fee: Initial purchase
		const double DOG_COST_FEED = 0.25;		// Fee: For each feeding
		const double DOG_COST_REVIVE = 1.00;	// Fee: Respawn if perished

		int m_numWalks = 0;

	public:
		//Dog Constructor
		Dog(const char* name, int initAge = 0, double cost = 0);

		//This ++ overload will increment day by one, and calculate dog's health status
		Dog& operator++(int num);

		//This = operator overload should clone a dog
		Dog& operator=(const Dog& rhs);

		//This function will feed the dog
		void feed();

		//This function will bring back the dog, if they die.
		void reSpawn();

		//This function will increment by one the number of walks
		void walk();

		//This function will return the number of walks.
		int walkNum() const;

	};

	//HELPER
	// This << insertion operator overload 

	std::ostream& operator<<(std::ostream& ostr, Dog& rhs);


}
#endif