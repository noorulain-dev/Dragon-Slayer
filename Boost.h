#pragma once
#include <iostream>
#include <string>

using namespace std;

class Boost {
private:
	//level of boost in int
	int fLevel; 
	//name of boost in string
	string fName; 
	//description of boost in string
	string fDesc; 
	//status of boost in boolean
	bool fStatus;

public:
	//Default constructor
	Boost(); 

	//Destructor
	~Boost(); 

	//Overloaded constructor
	Boost(int aLevel, string aName, string aDesc, bool aStatus);

	//getters and setters
	//getter for boost level
	int getLevel(); 

	//getter for boost name
	string getName(); 

	//getter for boost description
	string getDesc();

	//getter for boost status
	bool getStatus();

	//setter for boost status
	void setStatus(bool aTaken);

};