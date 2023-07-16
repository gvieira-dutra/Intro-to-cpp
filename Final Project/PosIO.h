//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <fstream>
#include <iostream>

namespace sdds {
	class PosIO
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::ofstream& save(std::ofstream& sv) const = 0;

		virtual std::istream& read(std::istream& is) = 0;
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
	};

	std::ostream& operator<<(std::ostream& os, const PosIO& writeMe);
	std::ofstream& operator<<(std::ofstream& sv, const PosIO& saveMe);

	std::istream& operator>>(std::istream& is, PosIO& read);
	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& read);
}

#endif