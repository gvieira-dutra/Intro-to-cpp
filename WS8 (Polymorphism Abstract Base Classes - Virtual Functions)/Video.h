#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include <iostream>
#include "Media.h"

namespace sdds {
	class Video: public Media {
	private:

		int m_length = 0;

	protected:
		int get() const;

	public:
		Video();
		explicit Video(int val);
		~Video();

		Video(const Video& source) = delete;
		Video& operator=(const Video& source) = delete;

		void load(std::istream& is) override;
		bool isValid() const;
	};

	std::istream& operator>>(std::istream& is, Video& rhs);
}

#endif