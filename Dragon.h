#pragma once
#include <iostream>
#include <vector>
#include "Super.h"
#include "User.h"

using namespace std;

//derived dragon class
class Dragon : public User 
{
private:
	//dragon strength in int
	int fStrength; 

public:
	//Default Constructor
	Dragon(); 

	//Destructor
	virtual ~Dragon(); 

	//Overloaded Constructor
	Dragon(string aName, int aHealth, vector<Super> aSuper, int aHitPower, int aStrength); 
	
	//Getter for strength
	int getStrength(); 

	//Setter for strength
	void setStrength(int aStrength); 

	 //function to hit the user
	void hit(User& aUser) override;
};