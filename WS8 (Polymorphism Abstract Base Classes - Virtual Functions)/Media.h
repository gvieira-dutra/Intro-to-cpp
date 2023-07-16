#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>

namespace sdds {
	class Media {
	public:
		virtual std::ostream& play(std::ostream& os) const = 0;
		virtual void load(std::istream& is) = 0;
		virtual ~Media();
	};

	//Helper Functions
	// << Output overload operator
	std::ostream& operator<<(std::ostream& os, Media& rhs);
	// >> Input Overload operator
	std::istream& operator>>(std::istream& is, Media& rhs);
}

#endif