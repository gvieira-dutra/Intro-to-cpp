#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include<string.h>
#include "Numbers.h"
#include <iomanip>
using namespace std;
namespace sdds {
	void Numbers::sort(double* nums, unsigned int size) {
		unsigned int i, j;
		double temp;
		for (i = size - 1; size && i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (nums[j] > nums[j + 1]) {
					temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}
	}

	//One argument constructor
	Numbers::Numbers(const char* fName)
	{
		setEmpty();
		strcpy(fileName, fName);
		load();
	}

	//Default constructor
	Numbers::Numbers()
	{
		collection = nullptr;
		fileName[0] = '\0';
		collectionSize = 0;
		originalFlag = false;
		addedFlag = false;
	}

	//Destructor
	Numbers::~Numbers()
	{
		save();
		delete[] collection;
	}

	//Copy Constructor
	Numbers::Numbers(const Numbers& right)
	{
		if (right.collection != nullptr)
		{
			*this = right;
		}
		
	}

	//Copy Assignment Operator
	Numbers& Numbers::operator=(const Numbers& right)
	{
		if (!(*this == right))
		{
			save();
			delete[] collection;
			setEmpty();
			if (right.collection != nullptr)
			{
				originalFlag = false;
				collection = new double[right.collectionSize];

				for (int i = 0; i < right.collectionSize; i++)
				{
					collection[i] = right.collection[i];
				}

				strcpy(fileName, right.fileName);

				collectionSize = right.collectionSize;
			}
		}
		return *this;
	}

	//Checks if object if valid
	Numbers::operator bool() const
	{
		return (collectionSize != 0 && collection);
	}

	//calls the provided sort function to sort the Collection double array
	void Numbers::sort()
	{
		sort(collection, collectionSize);
	}

	//add a single double value to the list of numbers in the array
	Numbers& Numbers::operator+=(double toAdd)
	{
		if (*this)
		{
			double* temp;

			temp = new double[ collectionSize + 1];
			
			for (int i = 0; i < collectionSize; i++)
			{
				temp[i] = collection[i];
			}

			temp[collectionSize ] = toAdd;
			
			
			delete[] collection;


			collection = temp;

			collectionSize++;

			addedFlag = true;

		}

		return *this;
	}

	std::ostream& Numbers::display(std::ostream& ostr) const
	{
		if (!*this)
		{
			ostr << "Empty list";
		}
		else
		{
			if (originalFlag == false)
			{
				ostr << "Copy of ";
			}
			ostr << fileName;
			ostr << '\n';
			for (int i = 0; i < collectionSize; i++)
			{
				if (i == collectionSize - 1)
				{
					ostr << fixed << setprecision(2) << collection[i];
				}
				else
				{
					ostr << fixed << setprecision(2) << collection[i] << ", ";
				}
			}

			ostr << '\n';

			for (int i = 0; i < 76; i++)
			{
				ostr << '-';
			}


			ostr << endl;
			ostr << "Total of " << collectionSize << " number(s), Largest: "
				<< max() << ", Smallest: " << min() << ", Average: " << average();
			ostr << '\n';

			for (int i = 0; i < 76; i++)
			{
				ostr << '=';
			}
		}
		return ostr;
	}

	//Set the current object to an empty state
	void Numbers::setEmpty()
	{
		collection = nullptr;
		fileName[0] = '\0';
		collectionSize = 0;
		originalFlag = false;
		addedFlag = false;
	}

	//This function returns true if all the double values are read from the data file and stored in the Collection, otherwise returns false.
	bool Numbers::load()
	{
		delete[] collection;

		int linesNum = countLines(fileName);

		if (linesNum > 0)
		{
			collection = new double[linesNum];
			int linesRead = 0;
			ifstream myFile(fileName);
			double readX;

			for (int i = 0; i < linesNum && !myFile.eof(); i++) {
				myFile >> readX;
				collection[linesRead] = readX;
				linesRead++;
			}
			myFile.close();

			if (linesRead != linesNum)
			{
				delete[] collection;
				setEmpty();
			}
			else
			{
				collectionSize = linesRead;
				originalFlag = true;
			}
		}

		return (linesNum > 0 ? true : false) ;
	}

	//If the current object is an original and new values are added to it
	void Numbers::save()
	{

		if (originalFlag == true && addedFlag == true)
		{
			ofstream myFile(fileName);
			for (int i = 0; i < collectionSize; i++)
			{
				myFile << fixed << setprecision(2) << collection[i] << '\n';
			}
		}
	}

	//Returns the largest double number in the Collection
	double Numbers::max() const
	{
		double max = -999999;

		for (int i = 0; i < collectionSize; i++)
		{
			if (collection[i] > max)
			{
				max = collection[i];
			}
		}

		return max;
	}

	//Returns the smallest double number in the Collection
	double Numbers::min() const
	{
		double min = 999999;

		for (int i = 0; i < collectionSize; i++)
		{
			if (collection[i] < min)
			{
				min = collection[i];
			}
		}

		return min;
	}

	//Returns the average of the double numbers in the Collection
	double Numbers::average() const
	{
		double sum = 0;

		for (int i = 0; i < collectionSize; i++)
		{
			sum += collection[i];
		}

		return (sum / collectionSize);
	}

	unsigned int Numbers::countLines(const char* filename) { /**/
		unsigned int lines = 0u;
		ifstream nums(filename);
		while (nums) {
			lines += (nums.get() == '\n');
		}
		return lines;
	}

	// Comparison operator
	bool operator==(const Numbers& c1, const Numbers& c2)
	{
		return (c1.getColSize() == c2.getColSize() && c1.fName() == c2.fName());
	}

	int Numbers::getColSize() const
	{
		return collectionSize;
	}

	const char* Numbers::fName() const
	{
		return fileName;
	}

	//Overload the insertion operator so a Numbers object can be inserted into an ostream object
	std::ostream& operator<<(std::ostream& os, Numbers& c)
	{
		c.display(os);
		return os;
	}

	//Overload the extraction operator so a Numbers object can be extracted an istream object. (without using friend statement)
	std::istream& operator>>(std::istream& is, Numbers& c)
	{
		double d;

		is >> d;

		c += d;
		


		return is;
	}
}