#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Video.h"

using namespace std;

namespace sdds {
	int Video::get() const
	{
		return m_length;
	}

	Video::Video()
	{
		m_length = 0;
	}

	Video::Video(int val)
	{
		if (val > 0)
			m_length = val;
		else
			m_length = 0;
	}

	Video::~Video()
	{
	}

	void Video::load(istream& is) 
	{
		is >> m_length;
		is.ignore();
	}

	bool Video::isValid() const
	{
		return m_length > 0? true: false;
	}

	istream& operator>>(istream& is, Video& rhs)
	{
		rhs.load(is);
		return is;
	}
}