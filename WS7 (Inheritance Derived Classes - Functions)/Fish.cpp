#include <iostream>
#include <cstring>
#include "Fish.h"
using namespace std;

namespace sdds {
	//Constructor
	Fish::Fish(const char* name, int initAge, double cost) : Pet(name, initAge, cost)
	{
	}

	//This function will feed the fish
	void Fish::feed()
	{
		Pet::feed();

		if (isAlive())
			addCharge(FISH_COST_BASE);
	}

	//This function will close the fish, if they die.
	void Fish::reSpawn()
	{
		Pet::reSpawn();
		addCharge(FISH_COST_REVIVE);
	}

	//This function will increment the number of days
	Fish& Fish::operator++(int num)
	{
		if (isAlive())
		{
			double healthDelta = 0;
			healthDelta += 0.20 * (getFeeds() - 1);
			applyHealthDelta(healthDelta);
			Pet::operator++(1);
		}

		return *this;
	}

	//This function will create a clone of this fish
	Fish& Fish::operator=(const Fish& right)
	{
		Pet::operator=(right);
		addCharge(FISH_COST_BASE * 2);

		return *this;
	}

	//This function will output some text to the screen
	ostream& operator<<(ostream& ostr, Fish& rhs)
	{
		ostr << "** Generic Fish **";
		ostr << endl;
		rhs.outputData(ostr);

		return ostr;
	}
}

