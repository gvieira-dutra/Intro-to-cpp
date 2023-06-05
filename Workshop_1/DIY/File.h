/*****************************************************************************
							 Workshop - #1
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#ifndef SDDS_FILE_H
#define SDDF_FILE_H

namespace sdds {
	bool openFile(const char filename[]);
	bool readStdName(char name[]);
	void closeFile();
	bool readStdNum(int* stno);
	bool readStdGPA(double* gpa);
}

#endif