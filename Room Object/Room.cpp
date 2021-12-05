// Room.cpp file
// Description: definition of functions of the Room object
// Author: Taylor Leong
// Date: 2021/05/15

#include <string>
#include <iostream>
#include "Room.h"
#include "Customer.h"

using namespace std;

//default constructor
Room::Room() : customer(nullptr) {
	checkIn.setDay(0);
	checkIn.setYear(0);
	checkIn.setMonth(0);
	checkOut.setDay(0);
	checkOut.setYear(0);
	checkOut.setMonth(0);

	beds = 0;
	
}
// parameterized constructor (given #beds) 
Room::Room(int BEDS) : customer(nullptr) {
	checkIn.setDay(0);
	checkIn.setYear(0);
	checkIn.setMonth(0);
	checkOut.setDay(0);
	checkOut.setYear(0);
	checkOut.setMonth(0);
	beds = BEDS;
}
// parameterized constructor (given all information)
Room::Room(Customer *CUSTOMER, const string &CHECKIN, int duration, int BEDS) : customer(CUSTOMER) {
	setCheckIn(CHECKIN);
	setCheckOut(duration);
	beds = BEDS;
}
// copy constructor
Room::Room(const Room &anotherRoom){
	customer = anotherRoom.customer;
	checkIn = anotherRoom.checkIn;
	checkOut = anotherRoom.checkOut;
	beds = anotherRoom.beds;
}
//destructor
Room::~Room(){
	customer = nullptr;
}
// overloading operator =
Room &Room::operator=(const Room &anotherRoom){
	customer = anotherRoom.customer;
	checkIn = anotherRoom.checkIn;
	checkOut = anotherRoom.checkOut;
	beds = anotherRoom.beds;
	return *this;
}


// getter: get check in date of the customer occuping this room
Date Room::getCheckIn() const {
	return checkIn;
}
// getter: get check out date of the customer occuping this room
Date Room::getCheckOut() const {
	return checkOut;
}
// getter: get the customer occuping this room
Customer* Room::getCustomer() const {
	return customer;
}
// getter: get te number of bed available of this room
int Room::getBeds() const {
	return beds;
}


// setter: set the check in date with the given date
void Room::setCheckIn(const string &CHECKIN) {
	changeDateType(CHECKIN,checkIn);
}
// setter: set the check out date with the given duration time
void Room::setCheckOut(int duration) {
	// months that have 31 days
	if(checkIn.getMonth() == 1 || checkIn.getMonth() == 3 || checkIn.getMonth() == 5 
		|| checkIn.getMonth() == 7 || checkIn.getMonth() == 8 || checkIn.getMonth() == 10 
		|| checkIn.getMonth() == 12){
		dateCalculation(31, duration);
	// months that have 30 days
	}else if(checkIn.getMonth() == 4 || checkIn.getMonth() == 6 
		|| checkIn.getMonth() == 9 || checkIn.getMonth() == 11 ){
		dateCalculation(30, duration);
	// special case for February
	}else{
		dateCalculation(28, duration);
	}
}
// setter: set the customer occuping with the given one
void Room::setCustomer(Customer *CUSTOMER) {
	customer = CUSTOMER;
}
// set the number of beds available of the room 
void Room::setBeds(int BEDS) {
	beds = BEDS;
}


// change a date from string to Date data type
void Room::changeDateType(const string &date, Date &needed){
	int *position = new int[2];
	position[0] = date.find('/');
	position[1] = date.find('/', position[0] + 1);
	needed.setDay( stoi(date.substr(0, position[0])) );
	needed.setMonth( stoi(date.substr(position[0] + 1, position[1] - position[0] - 1)) );
	needed.setYear( stoi(date.substr(position[1] + 1)) );
	delete[] position;
}
// a function to calculate the check out date
void Room::dateCalculation(int monthDays, int duration) {
	if(checkIn.getDay() + duration > monthDays){
		if(checkIn.getMonth() < 12){
			checkOut.setMonth( checkIn.getMonth() + 1 );
			checkOut.setYear( checkIn.getYear() );
		}else{
			checkOut.setMonth(1);
			checkOut.setYear( checkIn.getYear() + 1 );
		}
		checkOut.setDay( checkIn.getDay() + duration - monthDays );
	}else{
		checkOut.setDay( checkIn.getDay() + duration );
		checkOut.setMonth( checkIn.getMonth() );
		checkOut.setYear( checkIn.getYear() );

	}
}
// changing customers after checkOutDate
bool Room::changeCustomer(const string &CHECKIN, Customer *CUSTOMER, int duration){
	Date tmp_CheckIn;
	changeDateType(CHECKIN,tmp_CheckIn);

	if(tmp_CheckIn.getYear() > checkOut.getYear()){
		customer = CUSTOMER;
		checkIn = tmp_CheckIn;
		setCheckOut(duration);
		return 1;
	}else if(tmp_CheckIn.getYear() == tmp_CheckIn.getYear()){
		if(tmp_CheckIn.getMonth() > checkOut.getMonth()){
			customer = CUSTOMER;
			checkIn = tmp_CheckIn;
			setCheckOut(duration);
			return 1;
		}else if(tmp_CheckIn.getMonth() == checkOut.getMonth()){
			if(tmp_CheckIn.getDay() > checkOut.getDay()){
				customer = CUSTOMER;
				checkIn = tmp_CheckIn;
				setCheckOut(duration);
				return 1;
			}
		}
	}
	return 0;
}
