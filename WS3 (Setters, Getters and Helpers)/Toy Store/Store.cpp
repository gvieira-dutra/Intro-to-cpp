#define _CRT_SECURE_NO_WARNINGS
#include "Store.h"
#include <iostream>
#include<string.h>

using namespace std;

namespace sdds {
	Store::Store() {
		m_addToys = 0;
		m_sName[0] = '\0';
		m_noOfToys = 0;
	}

	void Store::setStore(const char* sName, int no)
	{
		if (sName != nullptr && sName[0] != '\0' && no)
		{
			strcpy(m_sName, sName);
			m_noOfToys = no;
			m_addToys = 0;
		}
		else
		{
			m_sName[0] = '\0';
			m_noOfToys = 0;
			m_addToys = 0;
		}
	};

	void Store::setToys(const char* tname, int sku, double price, int age)
	{
		if (m_noOfToys > m_addToys)
		{
			m_toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}

	void Store::display() const
	{
		if (m_sName != NULL && m_sName[0] != '\0')
		{
			cout << string(60, '*') << endl;
			cout << m_sName << endl;
			cout << string(60, '*') << endl;
			cout << "list of the toys" << endl;
			cout.width(30);
			cout << "SKU";
			cout.width(10);
			cout << "Age";
			cout.width(11);
			cout << "Price";
			cout.width(10);
			cout << "Sale" << endl;

			for (int i = 0; i < m_addToys; i++)
			{
				cout << "Toy[" << i + 1 << "] :";
				m_toy[i].display();
			}
		}
		else
		{
			cout << "Invalid Store" << endl;
		}
	}

	void Store::find(int sku)
	{
		for (int i = 0; i < m_addToys; i++)
		{
			bool check = false;

			if (m_toy[i].findSKUIndex(sku, i) != -1)
			{
				check = true;
				m_toy[i].isSale(check);
				m_toy[i].calSale();
			}
		}
	}

	void Store::setEmpty()
	{
		//Store = NULL;
	}
}