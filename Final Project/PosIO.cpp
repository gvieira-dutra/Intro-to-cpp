//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#define CRT_SECURE_NO_WARNINGS
#include "PosIO.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const PosIO& writeMe)
	{
		writeMe.write(os);
		return os;
	}

	std::ofstream& operator<<(std::ofstream& sv, const PosIO& saveMe)
	{
		saveMe.save(sv);
		return sv;
	}

	std::istream& operator>>(std::istream& is, PosIO& read)
	{
		read.read(is);
		return is;
	}

	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& read)
	{
		read.load(ifstr);
		return ifstr;
	}
}