#define _CRT_SECURE_NO_WARNINGS
#include "Toys.h"
#include <iostream>
#include<string.h>
#include <iomanip>
using namespace std;

namespace sdds {
	Toys::Toys() {
		m_tname[0] = '\0';
		m_sku = 0;
		m_price = 0;
		m_age = 0;
		m_onSale = 0;
	}

	void Toys::addToys(const char* tname, int sku, double price, int age)
	{
		if (tname != nullptr && tname[0] != '\0' && price && age && sku > 10000000)
		{
			strcpy(m_tname, tname);
			m_sku = sku;
			m_price = price;
			m_age = age;
		}
		else
		{
			m_tname[0] = '\0';
			m_sku = 0;
			m_price = 0;
			m_age = 0;
		}
	}

	void Toys::isSale(bool sale)
	{
		m_onSale = sale;
	}

	void Toys::calSale()
	{
		m_price *= .8;
	}

	void Toys::display() const
	{
		if (m_tname != NULL && m_tname[0] != '\0')
		{
			cout << left << setw(15) << m_tname;
			cout << right << setw(10) << m_sku;
			cout << right << setw(6) << m_age;
			cout << right << setw(12) << fixed << setprecision(2) << m_price;
			if (m_onSale == true)
			{
				cout << right << setw(11) << "On Sale " << endl;
			}
			else
			{
				cout << string(8, ' ') << endl;
			}
		}
		else
		{
			cout << "Invalid Toy" << endl;
		}
	}

	int Toys::findSKUIndex(int SKUNum, int position) const
	{
		int SKUindex = -1;

		if (m_sku == SKUNum)
		{
			SKUindex = position;
		}

		return SKUindex;
	}
}