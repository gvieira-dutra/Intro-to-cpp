#ifndef _SDDS_EGGCARTON_H
#define _SDDS_EGGCARTON_H
#include "iostream"


namespace sdds {
	
	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

	class EggCarton {
		int cartoonSz;
		int eggsNum;
		bool isJumbo;

	public:
		
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false); //Default constructor 

		void setBroken();

		int getEggsNum() const; 

		std::ostream& display(std::ostream& ostr = std::cout) const; //Displays cartoon to screen

		std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const; // also display cartoon to screen 

		std::istream& read(std::istream& istr = std::cin); // 

		operator bool() const;

		operator int() const;

		operator double() const;

		EggCarton& operator--(); // prefix operator

		EggCarton& operator--(int); // postfix operator

		EggCarton& operator++(); // prefix operator

		EggCarton& operator++(int); //postfix operator 

		EggCarton& operator=(int eggsNum);

		EggCarton& operator+=(int eggsNum);

		EggCarton& operator+=(EggCarton& right);

		bool operator==(const EggCarton& right) const;


	};

		// Helper Binary Operator Overload
		int operator+(int left, const EggCarton& right);

		std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);

		std::istream& operator>>(std::istream& istr, EggCarton& right);


}



#endif // !_SDDS_EGGCARTON_H
