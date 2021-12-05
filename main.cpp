// main.cpp file
// Desctiption: Contains the main program
// Author: Taylor Lenog
// Date: 2021/05/15

#include <fstream>
#include <iostream>
#include <string>
#include "Room.h"
#include "Customer.h"
#include "Date.h"
#include "Hotel.h"

using namespace std;

int main(){
	string fileName = "Customers.txt";
	Hotel ourHotel;

	// read the file
	fstream file;
	file.open(fileName);
	file.ignore(10000,'\n'); // skip the header line
	string line;
	int totalCustomer = 0;
	if(file.is_open()){
		while(!file.eof()){
			getline(file, line);
			ourHotel.assignData(line);
			totalCustomer++;
		}
	}else{
		cout << fileName <<" not found" << endl;
	}
	file.close();


	return 0;
}