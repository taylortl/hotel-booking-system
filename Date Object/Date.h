// date.h file
// Description: Date class that provide day, month, year of the date in integer.
// Author: Taylor Leong
// Date: 2021/05/15

#ifndef DATE_H
#define DATE_H

class Date {

	int day, month, year;

public:

	// default constructor
	Date();
	// parameterized constructor
	Date(int d,int m,int y);
	// copy constructor
	Date(const Date &anotherDate);
	// destructor
	~Date();
	// overloading operator = 
	Date &operator=(const Date &anotherDate);

	// getter: provide the day of the date
	int getDay();
	// getter: provide the month of the date
	int getMonth();
	// getter: provide the year of the date
	int getYear();

	// setter: set the day of the date
	void setDay(int d);
	// setter: set the month of the date
	void setMonth(int m);
	// setter: set the year of the date
	void setYear(int y);
	
};

#endif