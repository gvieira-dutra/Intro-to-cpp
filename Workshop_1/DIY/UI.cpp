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
#include "UI.h"
#include <iostream>
using namespace std; 

// flushes the keyboard
void flushkeys() {
	while (cin.get() != '\n');
}

namespace sdds {

	char readUserInput(char* op) {

		do {
			cout << "? ";
			
			scanf("%s", op);
			flushkeys();		

			if (op[0] != '<' && op[0] != '>' &&
				op[0] != '!' && op[0] != '~')

				cout << "Syntax error: ? [Op][value]<ENTER>" << endl 
					<< "Op: [>,<,~,!]"<< endl << "value: GPA value" 
					<< endl << endl;

		} while (op[0] != '<' && op[0] != '>' &&
			op[0] != '!' && op[0] != '~');
		
		return op[0];
		
	}
}
