#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include <iostream>
#include "Video.h"


namespace sdds {

	class Animation: public Video {

	private:
		int m_dimension = 0;

	public:
		Animation();
		Animation(int len, int dmnsion);
		

		void load(std::istream& is)override;
		std::ostream& play(std::ostream& os) const override;


	};
}

#endif