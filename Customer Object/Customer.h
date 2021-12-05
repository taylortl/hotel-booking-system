// Customer.h file
// Description: Customer object contains the id of the customer,
//				and the number of requested beds of the customer
// Author: Taylor Leong
// Date: 2021/05/15

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer{

	string id;
	int bedRequested;

public:

	//default constructor
	Customer();
	// constructor (given all information) 
	Customer(string ID,int BEDREQUESTED);
	// copy constructor
	Customer(const Customer &anotherCustomer);
	//destructor
	~Customer();

	// getter: get the id of the customer
	string getID();
	// getter: get the number of requested beds of the customer
	int getbedRequested();

	//setter: set the id of the customer
	void setID(string ID);
	// setter: set the number of requested beds of the customer
	void setRequestedBeds(int BEDREQUESTED);

};

#endif
