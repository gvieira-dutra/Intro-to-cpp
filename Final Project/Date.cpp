//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my project milestones.
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctime>
#include "Date.h"

namespace sdds {
	//Default constructor
	sdds::Date::Date()
	{
		getSystemDate(year, month, day, hour, minute, mDateOnly);
	}

	//Overload constructor for year, month and day only
	sdds::Date::Date(int yr, int mth, int dy)
	{
		year = yr;
		month = mth;
		day = dy;
		mDateOnly = true;
		validate(yr, mth, dy);
	}

	//Overload constructor for all attributes of data
	sdds::Date::Date(int yr, int mth, int dy, int hr, int min)
	{
		year = yr;
		month = mth;
		day = dy;
		hour = hr;
		minute = min;
		mDateOnly = false;
		validate(yr, mth, dy, hr, min);
	}

	//This function will determine how the max number of day a month can have 
	int Date::daysOfMonth(int year, int month) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = month >= 1 && month <= 12 ? month : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	//This function will validate the dates after they are set.
	void Date::validate(int yr, int mth, int dy)
	{
		if (yr < MIN_YEAR || yr > MAX_YEAR)
			m_error.setMsg("Invalid Year");
		else if (mth < 1 || mth > 12)
			m_error.setMsg("Invalid Month");
		else if (dy < 1 || dy > daysOfMonth(yr, mth))
			m_error.setMsg("Invalid Day");
	}

	//This overload function will validate the dates after they are set.
	void Date::validate(int yr, int mth, int dy, int hr, int min)
	{
		if (yr < MIN_YEAR || yr > MAX_YEAR)
			m_error.setMsg("Invalid Year");
		else if (mth < 1 || mth > 12)

			m_error.setMsg("Invalid Month");
		else if (dy < 1 || dy > daysOfMonth(yr, mth))
			m_error.setMsg("Invalid Day");
		else if (hr < 0 || hr > 23)
			m_error.setMsg("Invalid Hour");
		else if (min < 0 || min > 59)
			m_error.setMsg("Invlid Minute");
	}


	//The following function retrieves the current date and time of the system and returns them through the argument list.
	void sdds::Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		day = lt.tm_mday;
		mon = lt.tm_mon + 1;
		year = lt.tm_year + 1900;
		if (dateOnly) {
			hour = min = 0;
		}
		else {
			hour = lt.tm_hour;
			min = lt.tm_min;
		}
	}

	// == operator overload, will return true if objects are equal.
	bool Date::operator==(const Date& curr) const
	{
		return ((year == curr.year) && (month == curr.month) && (day == curr.day) && (hour == curr.hour) && (minute == curr.minute));
	}

	// != operator overload, will return true if objects are different
	bool Date::operator!=(const Date& rhs) const
	{
		return ((year != rhs.year) || (month != rhs.month) || (day != rhs.day) || (hour != rhs.hour) || (minute != rhs.minute));

	}

	// < operator overload, will return true if the current object's date is older than rhs date
	bool Date::operator<(const Date& rhs) const
	{
		bool flag = false;

		if (year < rhs.year)
			flag = true;
		else if (year == rhs.year)
		{
			if (month < rhs.month)
				flag = true;
			else if (month == rhs.month)
			{
				if (day < rhs.day)
					flag = true;
				else if (day == rhs.day)
				{
					if (hour < rhs.hour)
						flag = true;
					else if (hour == rhs.hour)
					{
						if (minute < rhs.minute)
							flag = true;
					}
				}
			}
		}


		return flag;
	}

	// > operator overload, will return true if the current object date is more recent than rhs
	bool Date::operator>(const Date& rhs) const
	{
		bool flag = false;

		if (year > rhs.year)
			flag = true;
		else if (year == rhs.year)
		{
			if (month > rhs.month)
				flag = true;
			else if (month == rhs.month)
			{
				if (day > rhs.day)
					flag = true;
				else if (day == rhs.day)
				{
					if (hour > rhs.hour)
						flag = true;
					else if (hour == rhs.hour)
					{
						if (minute > rhs.minute)
							flag = true;
					}
				}
			}
		}


		return flag;
	}

	// <= operator overload, will return true if this date is more older or equal to rhs
	bool Date::operator<=(const Date& rhs) const
	{
		bool flag = false;

		if (year <= rhs.year)
			flag = true;
		else if (year == rhs.year)
		{
			if (month <= rhs.month)
				flag = true;
			else if (month == rhs.month)
			{
				if (day <= rhs.day)
					flag = true;
				else if (day == rhs.day)
				{
					if (hour <= rhs.hour)
						flag = true;
					else if (hour == rhs.hour)
					{
						if (minute <= rhs.minute)
							flag = true;
					}
				}
			}
		}


		return flag;
	}

	// >= operator overload, will return true if this date is older more recent or equal to rhs
	bool Date::operator>=(const Date& rhs) const
	{
		bool flag = false;

		if (year >= rhs.year)
			flag = true;
		else if (year == rhs.year)
		{
			if (month >= rhs.month)
				flag = true;
			else if (month == rhs.month)
			{
				if (day >= rhs.day)
					flag = true;
				else if (day == rhs.day)
				{
					if (hour >= rhs.hour)
						flag = true;
					else if (hour == rhs.hour)
					{
						if (minute >= rhs.minute)
							flag = true;
					}
				}
			}
		}


		return flag;
	}

	// This method should set the date-only flag to the value received from the argument of the function.
	Date& Date::dateOnly(bool flag)
	{
		if (flag)
		{
			mDateOnly = flag;
			minute = 0;
			hour = 0;
		}
		else
			mDateOnly = flag;

		return *this;
	}

	// Boolean overload operator will return the opposite of the state of the error attribute. if state is true, return false
	Date::operator bool() const
	{
		bool  flag;
		flag = m_error;

		return !flag;
	}

	// This method will return a const reference to the error object
	const Error& Date::error() const
	{
		return m_error;
	}

	//This function will return True if the date is date Only, false if not. 
	bool Date::isDateOnly()
	{
		return mDateOnly;
	}

	//This function will clear the error object and set all time attributes to 0
	void Date::setEmpty(Date& rhs)
	{
		rhs.m_error.clear();
		rhs.year = 0;
		rhs.month = 0;
		rhs.day = 0;
		rhs.hour = 0;
		rhs.minute = 0;
	}

	//Will print the class info in the screen
	void Date::display(std::ostream& os) const
	{
		if (*this)
		{
			if (mDateOnly == true)
			{
				os << year << '/';
				if (month < 10)
				{
					os << '0';
				}
				os << month << '/';
				if (day < 10)
				{
					os << '0';
				}
				os << day ;
			}
			else
			{
				os << year << '/';
				if (month < 10)
				{
					os << '0';
				}
				os << month << '/';
				if (day < 10)
				{
					os << '0';
				}
				os << day << ", ";
				if (hour < 10)
				{
					os << '0';
				}
				os << hour << ':';
				if (minute < 10)
				{
					os << '0';
				}
				os << minute;
			}
		}
		else
		{
			if (mDateOnly == true)
			{
				os << m_error << '(';
				os << year << '/';
				if (month < 10)
				{
					os << '0';
				}
				os << month << '/';
				if (day < 10)
				{
					os << '0';
				}
				os << day <<  ')' ;
			}
			else
			{
				os << m_error << '(';;
				os << year << '/';
				if (month < 10)
				{
					os << '0';
				}
				os << month << '/';
				if (day < 10)
				{
					os << '0';
				}
				os << day << ", ";
				if (hour < 10)
				{
					os << '0';
				}
				os << hour << ':';
				if (minute < 10)
				{
					os << '0';
				}
				os << minute << ')' ;
			}
		}
	}

	//Will read user input
	void Date::read(std::istream& is)
	{
		setEmpty(*this);

		if (is >> year)
		{
			is.ignore(1, '\n');
			if (is >> month)
			{
				is.ignore(1, '\n');
				if (is >> day)
				{
					if (is.peek() != '\n')
					{
						is.ignore(1, '\n');
						if (is >> hour)
						{
							is.ignore(1, '\n');
							if (is >> minute)
							{
								mDateOnly = false;
								validate(year, month, day, hour, minute);
							}
							else 
								this->m_error.setMsg("Cannot read minute entry");

						}
						else
							this->m_error.setMsg("Cannot read hour entry");
					}
					else //If this is executed, user entered date only format
					{
						mDateOnly = true;
						validate(year, month, day);
					}
				}
				else
				this->m_error.setMsg("Cannot read day entry");
				
			}
			else
			this->m_error.setMsg("Cannot read month entry");
		}
		else
		this->m_error.setMsg("Cannot read year entry");
		

	}

	void Date::setErrorMessage(Date& rhs, const char* msg)
	{	
		rhs.m_error.setMsg(msg);
	}

	// Copy sign overload
	Date& Date::operator=(const Date& rhs)
	{
		if (this != &rhs)
		{
			year = rhs.year;
			month = rhs.month;
			day = rhs.day;
			hour = rhs.hour;
			minute = rhs.minute;
			mDateOnly = rhs.mDateOnly;
		}
		return *this;
	}

	const char* Date::getDateErrorMsg() const
	{
		return m_error.getMsg();
	}

	int Date::getYear() const
	{
		return year;
	}

	int Date::getMonth() const
	{
		return month;
	}

	int Date::getDay() const
	{
		return day;
	}



	// >> the insertion operator to insert a Date into the ostream object
	std::ostream& operator<<(std::ostream& os, Date& rhs)
	{
		rhs.display(os);
		return os;
	}

	// << the extraction operator overload will read a date from istream in the same format it is printed
	std::istream& operator>>(std::istream& is, Date& rhs)
	{
		rhs.read(is);
		return(is);
	}


}