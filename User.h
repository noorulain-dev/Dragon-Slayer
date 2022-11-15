#pragma once
#include <iostream>
#include <vector>
#include "Super.h"

using namespace std;

class User 
{
private:
	//name of user
	string fName;
	//user hp
	int fHP;
	// user's super powers
	vector<Super> fSuper;
	//user's damage
	int fDamage;

public:
	//Default Constructor
	User(); 

	//Destructor
	virtual ~User();

	//Overloaded Constructor
	User(string aName, int aHP, vector<Super> aSuper, int aDamage); 
	
	//returns user name
	string getUserName();

	//returns user hp
	int getHP(); 

	//sets user hp
	void setHP(int aHP); 

	//returns super power
	Super& getSuper(int aSuper);

	//add super power
	void addSuper(Super aSuper); 

	// return damage
	int getDamage(); 

	//set damage
	void setDamage(int aDamage); 

	//virtual function for attacks
	virtual void hit(User& aUser);

	//apply super power to user
	string useSuper(User& aUser, Super aSuper);

};
