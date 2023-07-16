//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "POS.h"
#include "Error.h"
#include "PosIO.h"
#include "Date.h"

namespace sdds {
	class Item : public PosIO
	{
	private:
		char SKU[MAX_SKU_LEN] = { 0 };
		char* Name = nullptr;
		double Price = 0;
		bool Taxed = false;
		int Quantity = 0;

	protected:
		int diaplayType;
		Error errorState;

	public:
		Item();
		Item(const Item& rhs);

		virtual ~Item();

		Item& operator=(const Item& rhs);

		const char* getSKU() const;

		bool operator>(Item& rhs) const;
		
		int operator+=(int rhs);
		int operator-=(int rhs);
		operator bool() const;

		// != operator overload, will return true if objects are different
		bool operator!=(const Item& rhs) const;

		virtual char itemType() const = 0;

		Item& displayType(int pos);
		
		int quantity() const;
		Item& clear();

		virtual std::ofstream& save(std::ofstream& sv) const override;

		virtual std::ostream& write(std::ostream& os) const override;

		virtual std::istream& read(std::istream& is) override;

		virtual std::ifstream& load(std::ifstream& ifstr) override;

		virtual std::ostream& bprint(std::ostream& os) const;
		
		double cost()const;

		const char* getErrMsg() const;


	};

	bool operator==(const Item& it1, const char* str);
	double operator+=(double& lhs, const Item& rhs);
}

#endif