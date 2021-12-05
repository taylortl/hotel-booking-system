// hotel.h file 
// Description: 
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

// assign different room to customer according to their needs and avialability
bool assignRoom(Room *rooms, Customer *customer, string CHECKIN, int duration, int beds);
// contains repeated work in assignRoom function
// assign more than one bed room to customers that needs more beds
bool assignMutliRoom(Room *rooms, Customer *customer, string CHECKIN, int duration, int max);
// get a line from the data and allocate the information
void assignData(string data, vector<Customer> &list, Room *rooms);

#endif


