#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
	class Numbers {
		double* collection = nullptr; //Dynamic array
		char fileName[255] = { 0 };
		int collectionSize = 0;
		bool originalFlag = 0;
		bool addedFlag = 0;

		unsigned int countLines(const char* filename);
		void sort(double* collectionPtr, unsigned int size);

		//Set the current object to an empty state
		void setEmpty();

		//This function returns true if all the double values are read from the data file and stored in the Collection, otherwise returns false.
		bool load();

		//If the current object is an original and new values are added to it
		void save();

		//Returns the largest double number in the Collection
		double max() const;

		//Returns the smallest double number in the Collection
		double min() const;

		//Returns the average of the double numbers in the Collection.
		double average() const;

	public:
		//One argument constructor
		Numbers(const char* fName);

		//Default constructor
		Numbers();

		//Destructor
		~Numbers();

		//Copy Constructor
		Numbers(const Numbers& right);

		//Copy Assignment Operator
		Numbers& operator=(const Numbers& right);

		//Checks if object if valid
		operator bool() const;

		//calls the provided sort function to sort the Collection double array
		void sort();

		//add a single double value to the list of numbers in the array
		Numbers& operator+=(double toAdd);

		std::ostream& display(std::ostream& ostr = std::cout) const;

		int getColSize() const;

		const char* fName() const;


	};

	//Helper functions
	
	// Comparison operator
	bool operator==(const Numbers& c1, const Numbers& c2);

	//Overload the insertion operator so a Numbers object can be inserted into an ostream object
	std::ostream& operator<<(std::ostream& os, Numbers& c);

	//Overload the extraction operator so a Numbers object can be extracted an istream object. (without using friend statement)
	std::istream& operator>>(std::istream& is, Numbers& c);
}
#endif // !SDDS_NUMBERS_H_
