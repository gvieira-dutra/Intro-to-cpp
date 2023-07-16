#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include <iostream>
#include "Person.h"
#include "Tools.h"

namespace sdds {
	class Contact : public Person {
		char* Address = nullptr;
		char* City = nullptr;
		char Province[3] = { '\0' };
		char Postal[7] = { '\0' };
	public:

		Contact();
        Contact(const Contact& copyFrom);
        Contact& operator=(const Contact& RightOperand);
        ~Contact();
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        // returns true if the name is valid; 
        // a valid name has a first and a last name
        // and they are not empty
        operator bool()const;
        // deallocates the dynamic memory
        void operator~();
    };
    std::istream& operator>>(std::istream& is, Person& rightOperand);
    std::ostream& operator<<(std::ostream& os, const Person& rightOperand);
}

#endif