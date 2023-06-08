#define _CRT_SECURE_NO_WARNINGS
#include "NameTag.h"
#include "string.h"
#include "string"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
	NameTag::NameTag()
	{
		name = nullptr;
		extension = 0;
	}

	NameTag::NameTag(const char* nametag)
	{
		if (nametag != nullptr && nametag[0] != '\0')
		{
			name = new char[strlen(nametag) + 1];

			strcpy(name, nametag);
		}
		else
		{
			name = nullptr;
			extension = 0;
		}

		extension = 0;
	}

	NameTag::NameTag(const char* nametag, int extNum)
	{
		if (nametag != nullptr && nametag[0] != '\0' && extNum > 9999 && extNum < 100000)
		{
			name = new char[strlen(nametag) + 1];

			strcpy(name, nametag);

			extension = extNum;
		}
		else
		{
			name = nullptr;
			extension = 0;
		}
	}

	NameTag::~NameTag()
	{

		cout << "SOMETHING WAS JUST DEALLOCATED" << endl;
		delete[] name;
		name = nullptr;
	}

	void clearInputBuffer(void)
	{
		// Discard all remaining char's from the standard input buffer:
		while (getchar() != '\n')
		{
			; // do nothing!
		}
	}

	void NameTag::print() const
	{
		int size = 0;

		if (name != nullptr && name[0] != '\0')
		{
			size = strlen(name);

			if (size >= 40)
			{
				size = 42;
			}
			else
			{
				size = 22;
			}

			cout << "+";
			for (int i = 0; i < size; i++)
			{
				cout << '-';
			}
			cout << "+";
			cout << endl;

			cout << "|";
			for (int i = 0; i < size; i++)
			{
				cout << ' ';
			}
			cout << "|";
			cout << endl;

			cout << "| ";

			if (size == 42)
			{
				for (int i = 0; i < size - 2; i++)
				{
					putchar(name[i]);
				}
				cout << " |";
			}
			else
			{
				cout << setw(size - 1) << left << name << setfill(' ') << left << '|';
			}
			cout << endl;
			cout << "|";

			for (int i = 0; i < size; i++)
			{
				cout << ' ';
			}
			cout << "|";
			cout << endl;

			if (extension != 0)
			{
				cout << left << "| Extension: " << extension;
				cout << "     |";
			}
			else
			{
				cout << setw(size + 1) << setfill(' ') << left << "| Extension: N/A";
				cout << "|";
			}
			cout << endl;

			cout << "|";
			for (int i = 0; i < size; i++)
			{
				cout << ' ';
			}

			cout << "|";
			cout << endl;
			cout << "+";
			for (int i = 0; i < size; i++)
			{
				cout << '-';
			}
			cout << "+";
			cout << endl;
		}
		else
		{
			cout << "EMPTY NAMETAG!";
			cout << endl;
		}
	}

	NameTag& NameTag::read()
	{
		string input;
		int inputSize;
		char extensionC[8];
		bool check = true;

		cout << "Please enter the name: ";
		getline(cin, input);

		inputSize = input.length();

		if (name != nullptr && name[0] != '\0') {
			delete[] name;
		}

		if (inputSize > 40)
		{
			input = input.substr(0, 40);
			name = new char[41];

			for (size_t i = 0; i < 40; i++)
			{
				name[i] = input[i];
			}
			name[40] = '\0';
		}
		else
		{
			name = new char[inputSize + 1];

			for (size_t i = 0; i < input.length(); i++)
			{
				name[i] = input[i];
			}

			name[inputSize] = '\0';
		}

		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		do {
			cin >> extensionC;
			if (extensionC[0] != 'N' && extensionC[0] != 'n' && extensionC[0] != 'y' && extensionC[0] != 'Y')
			{
				cout << "Only (Y) or (N) are acceptable, try agin: ";
				check = false;
			}
			else
			{
				check = true;
			}
		} while (check == false);

		if (extensionC[0] == 'y' || extensionC[0] == 'Y')
		{
			cout << "Please enter a 5 digit phone extension: ";
			do {
				check = true;
				cin >> extensionC;
				clearInputBuffer();

				if (strlen(extensionC) != 5)
				{
					for (size_t i = 0; i < strlen(extensionC); i++)
					{
						if (!isdigit(extensionC[i]))
						{
							check = false;
						}
					}
					if (check == false)
					{
						cout << "Bad integer value, try again: ";
					}
					else
					{
						cout << "Invalid value [10000<=value<=99999]: ";
						check = false;
					}
				}
				else {
					for (size_t i = 0; i < strlen(extensionC); i++)
					{
						if (!isdigit(extensionC[i]))
						{
							check = false;
						}
					}
					if (check == false)
					{
						cout << "Bad integer value, try again: ";
						check = false;
					}
					else
					{
						extension = atoi(extensionC);
						check = true;
					}
				}
			} while (check == false);
		}
		else
		{
			extension = 0;
			clearInputBuffer();
		}

		return *this;
	}
}