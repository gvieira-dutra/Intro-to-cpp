#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
	class Tournament {
		char* m_name; //points to a dynamically allocated Cstring
		int m_num; //size of the dynamically allocated array of soccer team. It should be more then zero.
		SoccerTeam* m_soccer; //pointer to the dynamically allocated array of soccerTeam

	public:

		Tournament();

		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);

		~Tournament();

		void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);

		void setEmpty();

		bool isEmpty() const;

		Tournament& match(const SoccerTeam* ls);

		ostream& display() const;
	};
}
