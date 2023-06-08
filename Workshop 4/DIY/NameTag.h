#pragma once
#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds {

	class NameTag {
		char* name; // will dynamically store the name
		int extension;

	public:
	NameTag();
	NameTag(const char* nametag);
	NameTag(const char* nametag, int extNum);
	~NameTag();


	void print() const;
	NameTag& read();
	
	};

	void clearInputBuffer(void);

}

#endif // !SDDS_NAMETAG_H
