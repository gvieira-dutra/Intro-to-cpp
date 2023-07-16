#include <iostream>
#include "Animation.h"

using namespace std;

namespace sdds {

	Animation::Animation()
	{
		m_dimension = 0;
	}

	Animation::Animation(int len, int dmnsion): Video(len)
	{
		if (dmnsion == 2 || dmnsion == 3)
		{
			m_dimension = dmnsion;
		}
		else
		{
			m_dimension = 0;
		}
	}



	void Animation::load(istream& is)
	{
		int entry;
		Video::load(is);

		is >> entry;
		is.clear();

		if (entry == 2 || entry == 3)
		{
			m_dimension = entry;
		}
		else
		{
			m_dimension = 0;
		}

		

	}

	ostream& Animation::play(ostream& os) const
	{
		int num = Video::get();
		if ((m_dimension == 2 || m_dimension == 3) && num > 0)
		{
			os << "Animation is in ";
			os << m_dimension;
			os << "-D";
			os << endl;
			os << "Video Length = ";
			os << Video::get();

		}
		return os;
	}

}
