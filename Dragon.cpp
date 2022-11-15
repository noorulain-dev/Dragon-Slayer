#include <iostream>
#include "Dragon.h"

using namespace std;

// Default constructor
Dragon::Dragon() 
{

}

// Destructor
Dragon::~Dragon() 
{ 

}

// Overloaded constructor
Dragon::Dragon(string aName, int aHealth, vector<Super> aSuperSet, int aHitPower, int aStrength) : User(aName, aHealth, aSuperSet, aHitPower) 
{
	fStrength = aStrength;
}

// returns dragon strength
int Dragon::getStrength() 
{
	return fStrength;
}

// sets dragon strength
void Dragon::setStrength(int aStrength) 
{
	fStrength = aStrength;
}

// slayer attack
void Dragon::hit(User& aUser) 
{
	if (aUser.getHP() > 0) 
	{
		aUser.setHP(aUser.getHP() - this->getDamage());
	}
}
