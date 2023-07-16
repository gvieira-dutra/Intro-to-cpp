#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {
	VRVideo::VRVideo()
	{
		m_equipment = nullptr;
	}

	VRVideo::VRVideo(int len, const char* name) : Video(len)
	{
		if (len > 0 && name != nullptr && name[0] != '\0')
		{
			m_equipment = new char [strlen(name) + 1];
			strcpy(m_equipment, name);
		}
		else
		{
			m_equipment = nullptr;
		}
	}

	VRVideo::~VRVideo()
	{
		delete[] m_equipment;
		m_equipment = nullptr;
	}

	void VRVideo::load(std::istream& is)
	{
		string input = { '\0' };

		Video::load(is);
		
		getline(is, input, '\n');


		if ( input[0] != '\0')
		{
			if (m_equipment != nullptr)
				delete[] m_equipment;

			m_equipment = new char[input.length() + 1];
			strcpy(m_equipment, input.c_str());
		}
		else
		{
			m_equipment = nullptr;
		}

	}
	
	std::ostream& VRVideo::play(std::ostream& os) const
	{
		if (m_equipment != nullptr && m_equipment[0] != '\0')
		{
			os << "VRVideo requires ";
			os << m_equipment;
			os << endl;
			os << "Video Length = ";
			os << Video::get();
		}
		return os;
	}
}