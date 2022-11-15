#pragma once
#include <iostream>
#include <string>

using namespace std;

class Super 
{
private:
	//name od super power
	string fName;

	//damage of super power
	int fDamage;

public:
	//Default Constructor
	Super(); 

	//Destructor
	~Super(); 

	//Overloaded constructor
	Super(string aName, int aDamage); 

	//returns supoer power name
	string getName(); 

	//returns super power damage
	int getDamage(); 

	//sets super power damage
	void setDamage(int aDamage);
};