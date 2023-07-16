//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <string.h>
#include "PosApp.h"
using namespace std;

namespace sdds {


	PosApp::PosApp(const char* name)
	{
		if (name != nullptr && name[0] != '\0')
		{
			strcpy(filename, name);
		}
	}

	void PosApp::run()
	{
		int userSelection;
		loadRecs();

		do {
			menu(userSelection);

			switch (userSelection)
			{
			case 1:
				listItems(true);
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				POS();
				break;
			case 0:
				saveRecs();
				break;
			}
		} while (userSelection != 0);
	}

	void PosApp::menu(int& usrSelection)
	{
		string usrInput;
		bool flag = false;

		cout << "The Sene-Store";
		cout << endl;
		cout << "1- List items";
		cout << endl;
		cout << "2- Add item";
		cout << endl;
		cout << "3- Remove item";
		cout << endl;
		cout << "4- Stock item";
		cout << endl;
		cout << "5- POS";
		cout << endl;
		cout << "0- exit program";
		cout << endl;
		cout << "> ";

		do {
			getline(cin, usrInput);

			stringstream ss(usrInput);

			if (ss >> usrSelection)
			{
				if (usrSelection > -1 && usrSelection < 6)
				{
					flag = false;
				}
				else
				{
					cout << "[0<=value<=5], retry: > ";
				}
			}
			else
			{
				cout << "Invalid Integer, try again: ";
				flag = true;
			}
		} while (flag);

	}

	void PosApp::addItem()
	{
		cout << ">>>> Adding Item to the store................................................";
		cout << endl;

		if (nptr >= MAX_NO_ITEMS)
		{
			cout << "Inventory Full!";
		}
		else
		{
			string ch;
			Item* item = { 0 };

			cout << "Is the Item perishable? (Y)es/(N)o: ";
			std::getline(cin, ch);

			if (ch[0] == 'y' || ch[0] == 'Y')
			{
				Perishable per;
				do {
					per.read(cin);

					if (!(cin || item->operator bool()))
					{
						cin.clear();

						char c;
						while ((c = getchar()) != '\n' && c != EOF) {
						}

						cout << item;

						cout << ", try again...\n";

					}
					else
					{
						Iptr[nptr] = new Perishable(per);
					   nptr++;
					}
				}  while (!(cin || item->operator bool()));
			}
			else
			{
				NonPerishable nPer;
				nPer.read(cin);

				if (!(cin || item->operator bool()))
				{
					cin.clear();

					char c;
					while ((c = getchar()) != '\n' && c != EOF) {
					}

					cout << item;

					cout << ", try again...\n";

				}
				else
				{
					Iptr[nptr] = new NonPerishable();
					
					*Iptr[nptr] = nPer;
					nptr++;
				}
			}  
			
		}
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {
		}
		cout << ">>>> DONE!..................................................................." << endl;
	}

	void PosApp::removeItem()
	{
		cout << ">>>> Remove Item............................................................." << endl;
		
		int toDelete = selectItem();

		cout << "Removing...." << endl;

		Iptr[toDelete]->displayType(POS_FORM).write(cout);

		cout << ">>>> DONE!..................................................................." << endl;

		delete Iptr[toDelete];
		Iptr[toDelete] = nullptr;

		for (int i = toDelete; i < nptr - 1; i++)
		{			
			Iptr[i] = Iptr[i + 1];
		}

		nptr--;
		
		
	}

	void PosApp::saveRecs()
	{
		cout << ">>>> Saving Data............................................................." << endl;

		cout << "Goodbye!" << endl;

		ofstream outfile(filename);

		for (int i = 0; i < nptr; i++)
		{
			outfile << *Iptr[i] << endl;
		}

		if (nptr > 0)
		{
			for (int i = 0; i < nptr  ; i++) {
				delete Iptr[i];
				Iptr[i] = nullptr;
			}
			
		}
		
	}

	void PosApp::stockItem()
	{
		cout << ">>>> Select an item to stock.................................................";
		cout << endl;

		int addTo =  selectItem();

		cout << "Selected Item:" << endl;

		Iptr[addTo]->displayType(POS_FORM).write(cout);

		cout << "Enter quantity to add: ";

		string usrInput;
		bool flag = false;
		int usrSelection;

		do {
			getline(cin, usrInput);

			stringstream ss(usrInput);

			if (ss >> usrSelection)
			{
				if (usrSelection > 0 && usrSelection < MAX_STOCK_NUMBER  - Iptr[addTo]->quantity())
				{
					flag = false;
				}
				else
				{
					cout << "[1<=value<=" << MAX_STOCK_NUMBER - Iptr[addTo]->quantity() << "], retry: ";
					cout << "Enter quantity to add: ";
					flag = true;
				}
			}
			else
			{
				cout << "Invalid Integer, try again: ";
				flag = true;
			}
		} while (flag);

		Iptr[addTo]->operator+=(usrSelection);

		cout << ">>>> DONE!..................................................................." << endl;


	}

	void PosApp::POS()
	{
		cout << ">>>> Starting Point of Sale..................................................";
		cout << endl;

		string input;
		char toSell[9] = {'\0'};
		Bill myBill;
		bool stayOnLoop = true;

		do {

			cout << "Enter SKU or <ENTER> only to end sale..." << endl;
			cout << "> ";

			getline(cin, input);

			if (input == "")
			{
				stayOnLoop = false;
			}
			else
			{
				int i;
				int len = input.length();
				for (i = 0; i < len && i < 9 ; i++)
				{
					toSell[i] = input[i];
				}


				if (cin.fail() || strlen(toSell) > MAX_SKU_LEN)
				{	
					cin.clear();
					cin.ignore();
					cout << "SKU too long" << endl;

				}
				else
				{

					int index = search(toSell);

					if (index > -1)
					{

						Iptr[index]->operator-=(1);

						Iptr[index]->displayType(POS_FORM).write(cout);

						if (Iptr[index]->getErrMsg() == nullptr)
						{
							cout << endl <<  ">>>>> Added to bill" << endl;

							myBill.add(Iptr[index]);

							cout << ">>>>> Total: " << myBill.total() << endl;
						
						

						}
						else
						{
							Iptr[index]->clear();
							cout << endl;
						}
					}
					else
					{
						cout << "!!!!! Item Not Found !!!!!" << endl;
					}
				}
			}


		} while (stayOnLoop);

		myBill.print(cout);
	}

	int PosApp::search(const char* Lsku)
	{
		int ret = -1;
		
		for (int i = 0; i < nptr; i++)
		{
			if (!strcmp(Iptr[i]->getSKU(), Lsku))
			{
				ret = i;
			}
		}
		return ret;
	}

	void PosApp::loadRecs()
	{
		cout << ">>>> Loading Items...........................................................";
		cout << endl;
	
		char ch{};

		ifstream input(filename);
		if (!input.is_open()) {
			ofstream output(filename);
			output.close();
		}

		if (nptr > 0)
		{
			for (int i = nptr -1; i > -1; i--) {
				delete Iptr[i];
				Iptr[i] = nullptr;
			}
		}

		nptr = 0;

		while (input.get(ch) && nptr < MAX_NO_ITEMS) {

			if (ch == 'P') {

				Iptr[nptr] = new Perishable();
				
				input.ignore();
				
				Iptr[nptr]->load(input);
				nptr++;
			}
			else if (ch == 'N') {
				Iptr[nptr] = new NonPerishable();
				input.ignore();
				Iptr[nptr]->load(input);
				nptr++;
			}
		}
	}

	int PosApp::selectItem()
	{
		cout << ">>>> Item Selection by row number............................................" << endl;
		cout << "Press <ENTER> to start....";
		cin.ignore();
		listItems(false);

		cout << "Enter the row number: ";

		string usrInput;
		bool flag = false;
		int usrSelection;

		do {
			getline(cin, usrInput);

			stringstream ss(usrInput);

			if (ss >> usrSelection)
			{
				if (usrSelection > 0 && usrSelection < nptr)
				{
					flag = false;
				}
				else
				{
					cout << "[1<=value<=" << nptr << "], retry: ";
					cout << "Enter the row number: ";
					flag = true;
				}
			}
			else
			{
				cout << "Invalid Integer, try again: ";
				flag = true;
			}
		} while (flag);


		return usrSelection - 1;
	}


	
	void PosApp::listItems(bool listTotal)
	{

		double totalAsset = 0;

		cout << ">>>> Listing Items...........................................................";
		cout << endl;

		Item* temp;

		for (int i = nptr - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (*Iptr[j] > *Iptr[j + 1])
				{
					temp = Iptr[j];
					Iptr[j] = Iptr[j + 1];
					Iptr[j + 1] = temp;
				}
			}
		}

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

		for (int i = 0; i < nptr; i++)
		{
			Iptr[i]->displayType(POS_LIST);
			cout << setw(4) << i + 1 << " | ";
			cout << *Iptr[i] << endl;

			totalAsset += (Iptr[i]->cost() * Iptr[i]->quantity());
		}
		
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;

		if (listTotal == true) 
		{

			cout << "                               Total Asset: $  | " << setw(13) << right << totalAsset << "|" << endl;
			cout << "-----------------------------------------------^--------------^" << endl << endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const PosApp p)
	{
		return cout;
	}

	std::istream& operator>>(std::istream& is, const PosApp p)
	{
		return cin;
	}


}




