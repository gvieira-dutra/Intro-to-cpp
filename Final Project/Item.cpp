//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <string.h>
#include <stdexcept>
#include "Item.h"

//testint testing

using namespace std;

namespace sdds
{
	Item::Item()
	{
		SKU[0] = { '\0' };
		Name = nullptr;
		Price = 0;
		Taxed = false;
		Quantity = 0;
	}

	Item::Item(const Item& rhs)
	{
		if (rhs.Name != nullptr)
		{
			*this = rhs;
		}
	}

	Item::~Item()
	{
		delete[] Name;
	}

	Item& Item::operator=(const Item& rhs)
	{
		if (this != &rhs)
		{
			if (this->Name != nullptr && this->Name[0] != '\0')
				delete[] Name;

			if (rhs.Name != nullptr && rhs.Name[0] != '\0')
			{
				Name = new char[strlen(rhs.Name) + 1];
				strcpy(Name, rhs.Name);

				int i = 0;
				for (i = 0; rhs.SKU[i] != '\0'; i++)
				{
					SKU[i] = rhs.SKU[i];
				}
				SKU[i] = '\0';

				Price = rhs.Price;
				Taxed = rhs.Taxed;
				Quantity = rhs.Quantity;

			
			}
		}
		return *this;
	}

	const char* Item::getSKU() const
	{
		return SKU;
	}

	bool Item::operator>(Item& rhs) const
	{
		bool flag = true;

		if (strcmp(this->Name, rhs.Name) <= 0)
		{
			flag = false;
		}

		return flag;
	}

	int Item::operator+=(int rhs)
	{
		if (rhs + Quantity > MAX_STOCK_NUMBER)
		{
			Quantity = MAX_STOCK_NUMBER;
			errorState.setMsg(ERROR_POS_QTY);
		}
		else
			Quantity += rhs;

		return Quantity;
	}

	int Item::operator-=(int rhs)
	{
		if (rhs > Quantity)
		{
			Quantity = 0;
			errorState.setMsg(ERROR_POS_STOCK);
		}
		else
			Quantity -= rhs;

		return Quantity;
	}

	Item::operator bool() const
	{
		return (errorState == nullptr ? true : false);
	}

	bool Item::operator!=(const Item& rhs) const
	{
				return !(*this == rhs);
	}


	Item& Item::displayType(int pos)
	{
		this->diaplayType = pos;
		return *this;
	}


	int Item::quantity() const
	{
		return Quantity;
	}

	Item& Item::clear()
	{
		errorState.clear();
		return *this;
	}

	 ofstream& Item::save( ofstream& sv) const
	{
		if (this)
		{
			sv << itemType();
			sv << ',';
			sv << SKU;
			sv << ',';
			sv << Name;
			sv << ',';
			sv <<  fixed <<  setprecision(2) << Price;
			sv << ',';
			sv << Taxed;
			sv << ',';
			sv << Quantity;
		}
		else
		{
			 cerr << itemType();
			 cerr << ',';
			 cerr << SKU;
			 cerr << ',';
			 cerr << Name;
			 cerr << ',';
			 cerr <<  fixed <<  setprecision(2) << Price;
			 cerr << ',';
			 cerr << Taxed;
			 cerr << ',';
			 cerr << Quantity;
		}

		return sv;
	}

	 ostream& Item::write( ostream& os) const
	{
		if (diaplayType == POS_LIST && (!errorState.operator bool()))
		{
			os <<  setw(7) <<  left << SKU;

			os << '|' ;

			if (strlen(Name) < 20)
			{
				os <<  setw(20) <<  left << Name;
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					os << Name[i];
				}
			}

			os << '|' ;

			os <<  setw(7) <<  right <<  fixed <<  setprecision(2) << Price << '|';


			if (Taxed)
				os << " X ";
			else
				os << "   ";

			os << '|' ;

			os <<  setw(4) <<  right << Quantity;

			os << '|';

			if (Taxed)
				os <<  setw(9) <<  right << (Quantity * Price) + (Quantity * Price * TAX) << '|';
			else
				os <<  setw(9) <<  right << (Quantity * Price) << '|';
		}
		else if (diaplayType == POS_FORM && (!errorState.operator bool()))
		{
			os << "=============v";

			os << endl;

			os <<  setw(13) <<  left << "Name:" << Name <<  endl;

			os <<  setw(13) <<  left << "Sku:" << SKU <<  endl;

			os <<  setw(13) <<  left << "Price:" << fixed <<  setprecision(2) << Price <<  endl;

			os <<  setw(13) <<  left << "Price + tax:";
			if (Taxed)
				os << ( Price) + (Price * TAX) <<  endl;
			else
				os << "N/A" <<  endl;

			os <<  setw(13) <<  left << "Stock Qty:" << Quantity <<  endl;
		}
		else
		{
			os << errorState;
		}

		os.unsetf(ios::right);

		return os;
	}

	 istream& Item::read( istream& is)
	{
		 string lName;
		 string lTax;
		 string lQty;

		 cout << "Sku" <<  endl << "> ";
		do {
			is >> SKU;
			if ( strlen(SKU) > MAX_SKU_LEN)
				 cout << ERROR_POS_SKU <<  endl << "> ";
		} while ( strlen(SKU) > MAX_SKU_LEN);
		
		is.ignore();

		 cout << "Name" <<  endl << "> ";

		do {
			 getline(is, lName, '\n');

			int len = lName.length();

			if (Name)
			{
				delete[] Name;
			}

			Name = new char[len + 1];
			for (int i = 0; i < len; i++)
			{
				Name[i] = lName[i];
			}
			Name[len] = '\0';

			if ( strlen(Name) > MAX_NAME_LEN)
				 cout << ERROR_POS_NAME <<  endl << "> ";
		} while ( strlen(Name) > MAX_NAME_LEN);

		 cout << "Price" <<  endl << "> ";
		do {
			 string sPrice;
			is >> sPrice;

			try {
				Price = stod(sPrice);
				if (Price <= 0) {
					 cout << ERROR_POS_PRICE <<  endl << "> ";
				}
			}
			catch (const  invalid_argument&) {
				 cout << ERROR_POS_PRICE <<  endl << "> ";
				is.clear();
				is.ignore(1000, '\n');
				continue;
			}
			catch (const  out_of_range&) {
				 cout << ERROR_POS_PRICE <<  endl << "> ";
				continue;
			}
		} while (Price <= 0);

		cout << "Taxed?" << endl << "(Y)es/(N)o: ";
		do
		{
			is >> lTax;
			if ((lTax[0] != 'Y' && lTax[0] != 'y' && lTax[0] != 'N' && lTax[0] != 'n') || (lTax.length() > 1))
				 cout << "Only 'y' and 'n' are acceptable: ";

		} while ((lTax[0] != 'Y' && lTax[0] != 'y' && lTax[0] != 'N' && lTax[0] != 'n') || (lTax.length() > 1));

		if (lTax[0] == 'y' || lTax[0] == 'Y')
			Taxed = true;
		else
			Taxed = false;

		 cout << "Quantity" <<  endl << "> ";
		do {
			is >> lQty;
			try {
				Quantity = stoi(lQty);
				if (Quantity <= 0 || Quantity > 99) {
					 cout << ERROR_POS_QTY <<  endl << "> ";
				}
			}
			catch (const  invalid_argument&) {
				 cout << ERROR_POS_QTY <<  endl << "> ";
				is.clear();
				is.ignore(1000, '\n');
				continue;
			}
			catch (const  out_of_range&) {
				 cout << ERROR_POS_QTY <<  endl << "> ";
				continue;
			}
		} while (Quantity <= 0 || Quantity > 99);

		return is;
	}

  	 ifstream& Item::load( ifstream& ifstr) 
	 {
		errorState.clear();

		 string lSKU; 
		 string lName;
		 string lPrice;
		double DblPrice = 0;
		 string lTax;
		 //string lQty;
		int IntQty;
		bool flag = true;

		
		getline(ifstr, lSKU, ',');
		getline(ifstr, lName, ',');
		getline(ifstr, lPrice, ',');
		getline(ifstr, lTax, ',');
		//getline(ifstr, lQty, ',');
		ifstr >> IntQty;

		if (!lPrice.empty())
		{
			DblPrice =  stod(lPrice);
			//Price = DblPrice;
		}

		//if (!lQty.empty())
		//IntQty =  stod(lQty);

		if (ifstr)
		{
			if (lSKU.length() > MAX_SKU_LEN)
			{
				errorState.setMsg(ERROR_POS_SKU);
				flag = false;
			}
			else if (lName.empty() || (lName.length() > MAX_NAME_LEN))
			{
				errorState.setMsg(ERROR_POS_NAME);
				flag = false;
			}
			else if (DblPrice <= 0)
			{
				errorState.setMsg(ERROR_POS_PRICE);
				flag = false;
			}
			else if (lTax.empty() )
			{
				errorState.setMsg(ERROR_POS_TAX);
				flag = false;
			}
			else if (IntQty < 0 || IntQty > 99)
			{
				errorState.setMsg(ERROR_POS_QTY);
				flag = false;
			}

			if (flag)
			{
				int length = lSKU.length();

				for (int i = 0; i < length; i++)
				{
					SKU[i] = lSKU[i];
				}
				
				length = lName.length();

				if (Name != nullptr && Name[0] != '\0')
					delete[] Name;

				Name = new char [length+1];

				int j = 0;
				for (int i = 0; i < length; i++)
				{
					
					Name[i] = lName[i];
					j++; 
				}
				Name[j] = '\0';


				Price = DblPrice;

				if (lTax[0] == '0')
					Taxed = false;
				else
					Taxed = true;

				Quantity = IntQty;

			}
		}
		return ifstr;
	 }

	 ostream& Item::bprint( ostream& os) const
	{
		os << "| ";
		
		int len = strlen(Name);

		if (len > 20) {
			for (int i = 0; i < 20; i++)
			{
				os << Name[i];
			}
		}
		else
		{
			os <<  setw(20) <<  left << Name;
		}

		os << '|';

		if (Taxed)
		{
		os <<  setw(10) <<  right <<  fixed <<  setprecision(2) << Price + (Price * TAX) ;

		}
		else
		{
		os <<  setw(10) <<  right <<  fixed <<  setprecision(2) << Price;

		}

		os << " |  ";

		if (Taxed)
			os << 'T';
		else
			os << ' ';

		os << "  |" <<  endl;

		return os;
	}


	bool operator==(const Item& it1, const char* str)
	{
		bool flag = true;
		 string lSKU;

		lSKU = it1.getSKU();

		int len = lSKU.length();

		for (int i = 0; i < len; i++)
		{
			if (lSKU[i] != str[i])
				flag = false;
		}

		return flag;
	}

	double operator+=(double& lhs, const Item& rhs)
	{
		lhs += (rhs.cost() * rhs.quantity());
		return lhs;
	}

	double Item::cost()const {
		return Price * (1 + Taxed * TAX);
	}

	const char* Item::getErrMsg() const
	{
		return (errorState.getMsg());
	}




}