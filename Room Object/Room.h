// Room.h file
// Description: Room object contains customer, check in and check out date,
// 				and the number of beds available in the room
// Author: Taylor Leong
// Date: 2021/05/15

#ifndef ROOM_H
#define ROOM_H

#include "Customer.h"
#include "Date.h"
#include <string>

using namespace std;

class Room{
	
	Customer *customer;
	Date checkIn;
	Date checkOut;
	int beds;

public:
	
	// default constructor
	Room();
	// parameterized constructor (given #beds) 
	Room(int BEDS);
	// parameterized constructor (given all information)
	Room(Customer *CUSTOMER, const string &CHECKIN, int duration, int BEDS);
	//copy constructor
	Room(const Room &anotherRoom);
	//destructor
	~Room();
	//overloading operator =
	Room &operator=(const Room &anotherRoom);


	// const function: this function cannot modify the members

	// getter: get check in date 
	Date getCheckIn() const;
	// getter: get check out date
	Date getCheckOut() const;
	// getter: get the customer occuping this room
	Customer* getCustomer() const;
	// getter: get te number of bed available of this room
	int getBeds() const;


	// setter: set the check in date with the given date
	void setCheckIn(const string &CHECKIN);
	// setter: set the check out date with the given duration time
	void setCheckOut(int duration);
	// setter: set the customer occuping with the given one
	void setCustomer(Customer *CUSTOMER);
	// set the number of beds available of the room 
	void setBeds(int BEDS);


	// change a date from string to Date data type
	void changeDateType(const string &date, Date &needed);
	// a function to calculate the check out date
	void dateCalculation(int monthDays, int duration);
	// changing customers after checkOutDate, if customer changed, returns true
	bool changeCustomer(const string &CHECKIN, Customer *CUSTOMER, int duration);
};

#endif

