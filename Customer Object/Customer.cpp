// Customer.cpp file
// Description: definition of functions of the Customer object
// Author: Taylor Leong
// Date: 2021/05/15

#include <string>
#include "Customer.h"

using namespace std;

//default constructor
Customer::Customer() : id(""), bedRequested(0) {}
// parameterized constructor 
Customer::Customer(string ID,int BEDREQUESTED) : id(ID), bedRequested(BEDREQUESTED) {}
// copy constructor
Customer::Customer(const Customer &anotherCustomer) {
	id = anotherCustomer.id;
	bedRequested = anotherCustomer.bedRequested;
}
//destructor
Customer::~Customer() {}


// getter: get the id of the customer
string Customer::getID() {
	return id;
}
// getter: get the number of requested beds of the customer
int Customer::Customer::getbedRequested() {
	return bedRequested;
}


//setter: set the id of the customer
void Customer::setID(string ID) {
	id = ID;
}
// setter: set the number of requested beds of the customer
void Customer::setRequestedBeds(int BEDREQUESTED) {
	bedRequested = BEDREQUESTED;
}