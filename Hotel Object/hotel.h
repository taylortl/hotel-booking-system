// Hotel.h file 
// Description: Definition of Hotel object
// Author: Taylor Leong
// Date 2021/05/15

#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "Room.h"
#include "Customer.h"
#include "Date.h"

using namespace std;

class Hotel{
	vector<Customer> customerList;
	int totalRooms = 3000; // total number of rooms in the hotel 
	int oneBedRoom = 500; // total number of rooms with one bed
	int twoBedRoom = 1500; // total number of rooms with two beds
	int threeBedRoom = 1000; // total number of rooms with three beds
	int oneBedServed = 0; // mark the number of one-bed rooms occupied
	int twoBedServed = 0; // mark the number of two-bed rooms occupied
	int threeBedServed = 0; // mark the number of three-bed rooms occupied
	Room *rooms = new Room[totalRooms];

public:

	//default constructor
	Hotel();
	//destructor
	~Hotel();
	
	// assign different room to customer according to their needs and avialability
	bool assignRoom(Customer *customer, string CHECKIN, int duration, int beds);
	// contains repeated work in assignRoom function
	// assign more than one bed room to customers that needs more beds
	bool assignMutliRoom(Customer *customer, string CHECKIN, int duration, int max);
	// get a line from the data and allocate the information
	void assignData(string data);

};


#endif


