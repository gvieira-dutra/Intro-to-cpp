#include <iostream>
#include <cstring>
#include <iomanip>
#include "soccerTeam.h"
using namespace std;

namespace sdds {
	//By default a soccerTeam is set to the empty state (as in setEmpty())
	SoccerTeam::SoccerTeam()
	{
		m_teamName[0] = '\0';
		m_noFouls = 0;
		m_fines = 0;
		m_golas = 0;
	}

	//After checking the validity it will set the team`s name,fine and no of fouls to the appropriate data members or else it will set the team to the empty state. (reuse your setter fucntions)
	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
	{
		if (tname != NULL && tname[0] != '\0' && fines >= 0 && foul >= 0)
		{
			strcpy(m_teamName, tname);
			m_fines = fines;
			m_noFouls = foul;
			m_golas = 0;
		}
		else
		{
			SoccerTeam();
		}
	}

	// It will set the team name, fine and fouls of the team.
	void SoccerTeam::setTeam(const SoccerTeam& team)
	{
		setName(m_teamName);
		setFine(m_fines, m_noFouls);
	}

	//If the received name pointer is valid and not null it will copy the received name to the data member m_teamName
	void SoccerTeam::setName(const char* tname)
	{
		if (tname != NULL && tname[0] != '\0')
		{
			strcpy(m_teamName, tname);
		}
	}

	//It will receive the information about fines and no of foul.After checking the validity it will set the values to the appropriate data members.Fine and foul should be grater than and equal to zero.Otherwise, it will set the soccerTeam object to an empty state.
	void SoccerTeam::setFine(double fines, int foul)
	{
		if (fines >= 0 && foul >= 0 )
		{
			m_fines = fines;
			m_noFouls = foul;
		}
		else
		{
			setEmpty();
		}
	}

	// Sets the soccerTeam object to an Empty State.
	void SoccerTeam::setEmpty()
	{
		m_teamName[0] = '\0';
		m_noFouls = 0;
		m_fines = 0;
		m_golas = 0;
	}

	// Returns true if m_teamName is not null, m_fines and m_noFouls is grater than 0.
	bool SoccerTeam::isEmpty() const
	{
		bool check = false;

		if (m_teamName != NULL && m_teamName[0] != '\0' && m_fines > 0 && m_noFouls > 0)
		{
			check = true;
		}

		return check;
	}

	// If this function is called it will increases the fine by 20% of the old fine value.
	void SoccerTeam::calFines()
	{
		m_fines *= 1.2;
	}

	//It will return the m_noFoul
	int SoccerTeam::fouls() const
	{
		return m_noFouls;
	}

	//It will double the number of fouls;
	void SoccerTeam::foulsD()
	{
		m_noFouls *= 2;
	}

	void sdds::SoccerTeam::increaseGoals()
	{
		m_golas++;
	}

	/*If a soccerTeam object is valid
	a) prints m_teamName with width 30, left justified and fill with empty spaces.
	b) prints m_fines with width 6 and after the decimal point 2 digits.
	c) prints m_noFoul with width 6
	d) prints m_fines with width 6
	e) prints m_golas with width 10. If number of goals are greater than zero then it will print "w" besides the number.
	otherwise prints, "Invalid Team".
	At the end return the reference of the ostream object.*/

	ostream& SoccerTeam::display() const
	{
		if (m_teamName != NULL && m_teamName[0] != '\0' && m_fines > 0 && m_noFouls > 0)
		{
			cout << setfill(' ') << left << setw(30) << m_teamName;
			cout << setw(6) << fixed << setprecision(2) << m_fines;
			cout << setfill(' ') << setw(6) << m_noFouls;
			if (m_golas > 0)
			{
				cout << setfill(' ') << setw(10) << m_golas << "w";
			}
			else
			{
				cout << setfill(' ') << setw(10) << m_golas;
			}
		}
	}
}