// Hotel.cpp file
// Desctiption: This is the hotel program.
// Author: Taylor Lenog
// Date: 2021/05/15

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Customer.h"
#include "Date.h"
#include "Hotel.h"

using namespace std;

//default constructor
Hotel::Hotel() {
	// assigning rooms with different beds
	for(int i = 0 ; i < oneBedRoom ; i++){
		rooms[i] = Room(1);
	}
	for(int i = oneBedRoom ; i < oneBedRoom + twoBedRoom ; i++){
		rooms[i] = Room(2);
	}
	for(int i = oneBedRoom + twoBedRoom ; i < totalRooms; i++){
		rooms[i] = Room(3);
	}
}
//destructor
Hotel::~Hotel() {
	delete[] rooms;
	rooms = nullptr;
}


// assign more than one bed room to customers that needs more beds
bool Hotel::assignMutliRoom(Customer *customer, string CHECKIN, int duration, int max){
	bool booking = 0;
	// first check if there's still rooms needed
	if( (customer->getbedRequested() % max) != 0 ){
		// check if there's room available for the remaining ones
		if( assignRoom(customer, CHECKIN, duration, (customer->getbedRequested() % max) ) ){
			// if yes, then assign all the rooms
			for(int i = 0 ; i < (customer->getbedRequested() / max) ; i++){
				booking = assignRoom(customer, CHECKIN, duration, max);
			}
		}else{
			// do not assign any rooms if the remaining ones are not assigned
			booking = 0;
		}
	}else{
		for(int i = 0 ; i < (customer->getbedRequested() / max) ; i++){
			booking = assignRoom(customer, CHECKIN, duration, max);
		}
	}
	return booking;
}


// assign different room to customer according to their needs and avialability
bool Hotel::assignRoom(Customer *customer, string CHECKIN, int duration, int beds){
	bool booking = 0;
	if(beds == 1){

		if(oneBedServed < oneBedRoom){ // if there are empty rooms
			booking = rooms[oneBedServed].changeCustomer(CHECKIN, customer, duration); // assign room
			oneBedServed++;
		}else{ // if there are no empty rooms
			for(int i = 0 ; i < oneBedRoom ; i++){ // check if any room is available on the check in date
				booking = rooms[i].changeCustomer(CHECKIN, customer, duration); // reallocate customer for the room
				if(booking){
					break;
				}
			}
			if(!booking){ 
				booking = assignRoom(customer, CHECKIN, duration, beds + 1); // check if bigger rooms are available
			}
		}

	}else if(beds == 2){

		if(twoBedServed < twoBedRoom){ // if there are empty rooms
			booking = rooms[twoBedServed].changeCustomer(CHECKIN, customer, duration); //assign room2
			twoBedServed++;
		}else{
			for(int i = oneBedRoom ; i < twoBedRoom + oneBedRoom ; i++){ // check if any room is available on the check in date
				booking = rooms[i].changeCustomer(CHECKIN, customer, duration); // reallocate customer for the room
				if(booking){
					break;
				}
			}
			if(!booking){
				booking = assignRoom(customer, CHECKIN, duration, beds + 1); // check if bigger rooms are available
			}
		}

	}else if(beds == 3){

		if(threeBedServed < threeBedRoom){ // if there are empty rooms
			booking = rooms[threeBedServed].changeCustomer(CHECKIN, customer, duration); //assgin room3
			threeBedServed++;
		}else{
			for(int i = twoBedRoom + oneBedRoom; i < totalRooms ; i++){ // check if any room is available on the check in date
				booking = rooms[i].changeCustomer(CHECKIN, customer, duration); // reallocate customer for the room
				if(booking){
					break;
				}
			}
		}

	}else{ // more ppl than max #beds

		if(threeBedServed < threeBedRoom && ( threeBedServed + (beds / 3) ) < threeBedRoom){ // check if three-bed room is available and how many of them is needed
			booking = assignMutliRoom(customer, CHECKIN, duration, 3);
		}else if(twoBedServed < twoBedRoom && ( twoBedServed + (beds / 2) ) < twoBedRoom){ // check if two-bed room is available and how many of them is needed
			booking = assignMutliRoom(customer, CHECKIN, duration, 2);
		}else if(oneBedServed < oneBedRoom && ( oneBedServed + (beds / 1) ) < oneBedRoom){ // check if one-bed room is available and how many of them is needed
			booking = assignMutliRoom(customer, CHECKIN, duration, 1);
		}

	}
	
	return booking;
}


// get a line from the data and allocate the information
void Hotel::assignData(string data) {
	// get all the positions for the commmas
	int *position = new int[3];
	position[0] = data.find(',');
	position[1] = data.find(',', position[0] + 1);
	position[2] = data.find(',', position[1] + 1);

	// assign the informations to variables
	string checkIn = data.substr(0, position[0]);
	string id = data.substr(position[0] + 2, position[1] - position[0] - 2);
	int beds = stoi(data.substr(position[1] + 2, position[2] - position[1] - 2));
	int days =  stoi(data.substr(position[2] + 2));
	Customer tmp_customer(id,beds); 

	// check if we can serve the customer
	bool booking = assignRoom(&tmp_customer, checkIn, days, beds);
	if(booking){
		// save the customer into the list if we can serve them
		customerList.push_back(tmp_customer);
	}else{
		// send a message telling the customer that we cannot serve them
		// cout << "Customer " << tmp_customer.getID() << ": Sorry, the rooms are full" << endl;
	}
	// free up memory
	delete[] position;
	position = nullptr;
}

