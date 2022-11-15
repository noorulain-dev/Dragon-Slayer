#pragma once

#include <iostream>
#include <string>
#include "Impact.h"

using namespace std;

//froward declaration
class Slayer;

class Object 
{
private:
	//name of object
	string fName;
	//object details
	string fDetails;
	//power of object in int
	int fPower;
	//status of object usage in boolean
	bool fStatus;
	//status of potion usage in boolean
	bool fPotion;

public:
	//default constructor
	Object();

	//destructor
	~Object();

	//overloaded constructor
	Object(string aName, string aDesc, int aPower, bool aPotion);

	//getter for object name
	string getName(); 

	//setter for object power
	int getPower(); 

	//getter for object status
	bool getStatus();

	//setter for object status
	void setStatus(bool aStatus);

	//getter for potion status
	bool getPotion(); 

	//setter for potion status
	void setPotion(bool aStatus); 

	//function for impacting the slayer
	void impact(Impact& aImpact, Slayer& aSlayer);

	//equivalence operator
	bool operator== (const Object& aOther) const;

	//inequiavalnce oeprator
	bool operator!= (const Object& aOther) const;

	//friend operator overload
	friend ostream& operator<< (ostream& aOstream, const Object& aObject);
};