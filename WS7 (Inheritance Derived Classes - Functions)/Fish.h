#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"

namespace sdds {
	class Fish : public Pet
	{
		const double FISH_COST_BASE = 2.00;		// Fee: Initial purchase
		const double FISH_COST_FEED = 0.10;		// Fee: For each feeding
		const double FISH_COST_REVIVE = 0.50;	// Fee: Respawn if perished

	public:
		//Constructor
		Fish(const char* name, int initAge = 0, double cost = 0);

		//This function will feed the fish
		void feed();

		//This function will bring back the fish, if they die.
		void reSpawn();

		//This ++ operator overload will increment the number of days
		Fish& operator++(int num);

		//This = operator overload will create a clone of this fish
		Fish& operator=(const Fish& right);
	};

	//HELPER
	//This << overload will output some text to the screen
	std::ostream& operator<<(std::ostream& ostr, Fish& rhs);
}
#endif