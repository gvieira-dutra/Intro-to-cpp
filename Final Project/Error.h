//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H

#include <iostream>

namespace sdds {
	class Error {

		char* errorMsg = nullptr;

	public:

		//Default Constructor
		Error();

		//One Argument Constructor
		Error(const char* message);

		//Copy Constructor
		Error(const Error& right);

		//Destructor
		~Error();

		//Copy Operator Overload
		Error& operator=(const Error& right);

		// != operator overload, will return true if objects are different
		bool operator!=(const Error& rhs) const;

		//This function will return the current error message
		const char* getMsg() const;

		//Boolean type conversion. It will return true if msg is not null
		operator bool() const;

		// It will clear the error message.
		Error& clear();

		//This function will display the error message, if it exists.
		void display(std::ostream& os) const;

		//This function will set the error message
		void setMsg(const char* msg);
	};

	//Comparison Operator Overload
	bool operator==(const Error& e1, const Error& e2);

	//Ostream insertion
	std::ostream& operator<<(std::ostream& os, const Error& msg);
}

#endif