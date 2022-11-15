#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zone 
{
private:
	//zone name
	string fName;
	//zone description
	string fDesc;
	//zonestatus
	bool fStatus;

public:
	//Default Constructor
	Zone(); 

	//Destructor
	~Zone(); 

	//Overloaded Constructor
	Zone(string aName, string aDesc); 

	//returns the name of the zone
	string getName();

	// returns the description of the zone
	string getDesc();

	//returns the status of the zone
	bool getStatus();

	//sets the status of the zone
	void setStatus(bool aStatus); 

	//friend operator overload
	friend ostream& operator<< (ostream& aOstream, const Zone& aZone);
};