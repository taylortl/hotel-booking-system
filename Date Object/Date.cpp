// date.cpp file
// Description: Date class that provide day, month, year of the date in integer.
// Author: Taylor Leong
// Date: 2021/05/15

#include "Date.h"
using namespace std;

// default constructor
Date::Date() : day(0), month(0), year(0){}
// parameterized constructor
Date::Date(int d,int m,int y) : day(d), month(m), year(y){}
// copy constructor
Date::Date(const Date &anotherDate){
	day = anotherDate.day;
	month = anotherDate.month;
	year = anotherDate.year;
}
// destructor
Date::~Date() {}
// overloading operator =
Date &Date::operator=(const Date &anotherDate){
	day = anotherDate.day;
	month = anotherDate.month;
	year = anotherDate.year;
	return *this;
}

//getter: provide the day of the date
int Date::getDay(){
	return day;
}
//getter: provide the month of the date
int Date::getMonth(){
	return month;
}
//getter: provide the year of the date
int Date::getYear(){
	return year;
}

//setter: set the day of the date
void Date::setDay(int d){
	day = d;
}
//setter: set the month of the date
void Date::setMonth(int m){
	month = m;
}
//setter: set the year of the date
void Date::setYear(int y){
	year = y;
}