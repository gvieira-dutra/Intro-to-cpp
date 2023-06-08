/*****************************************************************************
							 Workshop - #1
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <iostream>
using namespace sdds;


namespace sdds {

	FILE* fptr;

	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

	void closeFile() {
		if (fptr) fclose(fptr);
	}

	bool readStdName(char name[]) {
		return (fscanf(fptr, "%[^,],", name)) == 1;
	}

	bool readStdNum(int* stno) {
		return fscanf(fptr, "%d,", stno) == 1;
	}

	bool readStdGPA(double* GPA) {
		return fscanf(fptr, "%lf\n", GPA) == 1;
	}
}