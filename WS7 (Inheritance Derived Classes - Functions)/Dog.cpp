#include <iostream>
#include <cstring>
#include "Dog.h"

using namespace std;

namespace sdds {

	Dog::Dog(const char* name, int initAge, double cost) : Pet(name, initAge, cost)
	{
		m_numWalks = 0;
	}

	//This function will increment day by one, and calculate dog's health status
	Dog& Dog::operator++(int num)
	{
		if(isAlive())
		{
			double healthDelta = 0;
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			m_numWalks = 0;
			applyHealthDelta(healthDelta);
			Pet::operator++(1);
		}

		return *this;
	}

	//This = operator overload should clone a dog
	Dog& Dog::operator=(const Dog& rhs)
	{
		Pet::operator=(rhs);
		m_numWalks = rhs.m_numWalks;
		addCharge(DOG_COST_BASE * 2);

		return *this;
	}

	//This function will feed the dog
	void Dog::feed()
	{
		Pet::feed();

		if (isAlive())
			addCharge(DOG_COST_FEED);
	}

	//This function will bring back the dog, if they die.
	void Dog::reSpawn()
	{
		Pet::reSpawn();
		m_numWalks = 0;
		addCharge(DOG_COST_REVIVE);
	}

	//This function will increment by one the number of walks
	void Dog::walk()
	{
		if (isAlive())
		{
			m_numWalks++;
		}
	}

	//This function will return the number of walks.
	int Dog::walkNum() const
	{
		return m_numWalks;
	}


	// This << insertion operator overload 
	ostream& operator<<(ostream& ostr, Dog& rhs)
	{
		ostr << "** Generic Dog **";
		ostr << endl;
		ostr << "   Walks: " << rhs.walkNum();
		ostr << endl;
		
		rhs.outputData(ostr);

		return ostr;
	}

}