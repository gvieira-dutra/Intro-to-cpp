#include <iostream>

namespace sdds {
	const int MAX_FOUL = 4; //maximum number of fouls

	struct SoccerTeam {
		char m_teamName[41];
		int m_noFouls; // Cannot be negative
		double m_fines; // Can be zero or more
		int m_golas;//can be zero or more
	public:
		//By default a soccerTeam is set to the empty state (as in setEmpty())
		SoccerTeam();

		//After checking the validity it will set the team`s name,fine and no of fouls to the appropriate data members or else it will set the team to the empty state. (reuse your setter functions)
		SoccerTeam(const char* tname, double fines, int foul);

		// It will set the team name, fine and fouls of the team.
		void setTeam(const SoccerTeam& team);

		//If the received name pointer is valid and not null it will copy the received name to the data member m_teamName
		void setName(const char* tname);

		//It will receive the information about fines and no of foul.After checking the validity it will set the values to the appropriate data members.Fineand foul should be grater than and equal to zero.Otherwise, it will set the soccerTeam object to an empty state.
		void setFine(double fines, int foul);

		// Sets the soccerTeam object to an Empty State.
		void setEmpty();

		//
		bool isEmpty() const;

		// If this function is called it will increases the fine by 20% of the old fine value.
		void calFines();

		//It will return the m_noFoul
		int fouls() const;

		//It will double the number of fouls;
		void foulsD();

		//Increase num of goals by one
		void increaseGoals();

		std::ostream& display()const;
	};
}