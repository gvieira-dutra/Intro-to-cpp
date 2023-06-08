#include <iostream>
#include "Tournament.h"
#include "soccerTeam.h"
//using namespace std;

namespace sdds {
	//By default a Tournament is initiated by setting all the member variable values to default values.You can do this by setting m_name, m_soccer to nullptr and m_num to a value like 0.
	Tournament::Tournament()
	{
		m_name = nullptr;
		m_soccer = 0;
	}

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer)
	{
		if (m_name != nullptr && m_name[0] != '\0' && m_num > 0)
		{
			m_num = noOfteam;

			m_name = new char[strlen(name + 1)];
			strcpy(m_name, name);

			m_soccer = new SoccerTeam[m_num];

			for (int i = 0; i < m_num; i++)
			{
				m_soccer[i].setTeam(*soccer);
			}
		}
		else
		{
			Tournament();
		}
	}

	Tournament::~Tournament()
	{
	}

	/*First, it will check the validity of all the received arguments. Tournament name should be valid and non-empty Cstring. Number of teams should be greater than zero.
It will set m_num to the corresponding argument value.
Then it will dynamically allocate memory for tournament name in the tournament name pointer attribute and then copies the content of the tournament name argument into the newly allocated memory.
It will dynamically allocate an array of soccer team pointed by m_soccer member variable. The length of this array will be m_num.
Lastly, add all the teams to the dynamically allocated array of m_soccer.
If any of the arguments are not valid it will set the Tournament to an empty state.*/
	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer)
	{
		if (m_name != nullptr && m_name[0] != '\0' && m_num > 0)
		{
			m_num = noOfteam;

			m_name = new char[strlen(name + 1)];
			strcpy(m_name, name);

			m_soccer = new SoccerTeam[m_num];

			for (int i = 0; i < m_num; i++)
			{
				m_soccer[i].setTeam(*soccer);
			}
		}
		else
		{
			Tournament();
		}
	}

	// Sets the Tournament object to an Empty State. Do this by setting the m_name and m_soccer to null and m_num to 0.
	void Tournament::setEmpty()
	{
		m_name = NULL;
		m_soccer = NULL;
		m_num = 0;
	}

	//Returns true if m_name and m_soccer is not null and m_num is grater than 0.
	bool Tournament::isEmpty() const
	{
		bool check = false;
		if (m_name != NULL && m_soccer != NULL && m_num > 0)
		{
			check = true;
		}
		return check;
	}

	/*This function will find out the winner between 2 soccer teams by having matches.It will loop through all the teams.

	  First it will check which team is having more no of fouls.
		  If first team is having less fouls then second team then, second team`s no of foul will increase by double and fine will be increased by 20 %
		  First team`s goal will be increased by 1.
		  If seconds team`s no of foul exceed the MAX_FOUL then this team will become a invalid team.You can do this by setting the number to foul to an invalid value.
		  At the end it will return the reference of the current object.*/
	Tournament& Tournament::match(const SoccerTeam* ls)
	{
		if (ls[0].fouls() < ls[1].fouls())
		{
			m_soccer[1].foulsD();
			m_soccer[1].calFines();
			m_soccer[0].increaseGoals();
		}
	}

	/*If Tournament object is valid

a) prints "Tournament name: " then tournament name

b) prints "list of the teams" after that a newline

c) prints "Fines" with width 45 and fill with empty spaces.

d) prints "Fouls" with width 10 and fill with empty spaces.

e) prints "Goals" with width 10 and fill with empty spaces.

e) prints all the soccer teams information. For details see the sample output.

otherwise prints, "Invalid Tournament".

At the end return the reference of the ostream object.*/
	std::ostream& Tournament::display() const
	{
	}
}