#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include <iostream>
#include "Video.h"

namespace sdds {
	class VRVideo : public Video {
		char* m_equipment = nullptr;

	public:
		VRVideo();
		VRVideo(int len, const char* name);
		~VRVideo();

		void load(std::istream& is) override;
		std::ostream& play(std::ostream& os) const override;
	};
}

#endif