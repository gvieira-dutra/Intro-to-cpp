//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Error.h"

namespace sdds
{
	//Default Constructor
	Error::Error()
	{
		errorMsg = nullptr;
	}

	//One Argument Constructor
	Error::Error(const char* message)
	{
		setMsg(message);
	}

	//Copy Constructor
	Error::Error(const Error& right)
	{
		if (right.errorMsg != nullptr)
		{
			errorMsg = new char[strlen(right.errorMsg) + 1];
			strcpy(errorMsg, right.errorMsg);
		}
		else {
			errorMsg = nullptr;
		}
	}

	//Destructor
	Error::~Error()
	{
		delete[] errorMsg;
		errorMsg = nullptr;
	}

	//Copy Operator Overload
	Error& Error::operator=(const Error& right)
	{
		if (*this != right)
		{
			if(errorMsg)
				delete[] errorMsg;

			if (right.errorMsg != nullptr)
			{
				errorMsg = new char[strlen(right.errorMsg) + 1];

				strcpy(this->errorMsg, right.errorMsg);
			}
			else
			{
				this->errorMsg = nullptr;
			}
		}

		return *this;
	}

	// != operator overload, will return true if objects are different
	bool Error::operator!=(const Error& rhs) const
	{
		{
			return (errorMsg != rhs.errorMsg);
		}
	}

	//This function will return the current error message
	const char* Error::getMsg() const
	{
		return errorMsg;
	}

	//Boolean type conversion. It will return true if msg is not null
	Error::operator bool() const
	{
		return (errorMsg == nullptr ? false : true);
	}

	Error& Error::clear()
	{
		delete[] errorMsg;
		this->errorMsg = nullptr;

		return *this;
	}

	//This function will display the error message, if it exists.
	void Error::display(std::ostream& os) const
	{
		if (errorMsg != nullptr)
			os << errorMsg;
	}

	//This function will set the error message
	void Error::setMsg(const char* msg)
	{
		if (msg != nullptr && msg[0] != '\0') {
			if (errorMsg) {
				delete[] errorMsg;
				errorMsg = nullptr;
			}
			errorMsg = new char[strlen(msg) + 1];
			strcpy(errorMsg, msg);
		}
		else {
			errorMsg = nullptr;
		}
	}

	//Comparison Operator Overload
	bool operator==(const Error& e1, const Error& e2)
	{
		return (e1.getMsg() == e2.getMsg());
	}

	//Ostream insertion
	std::ostream& operator<<(std::ostream& os, const Error& msg)
	{
		msg.display(os);
		return os;
	}
}