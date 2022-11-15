#include <iostream>
#include "User.h"

using namespace std;

// Default Constructor
User::User() 
{ 

}

// Destructor
User::~User() 
{

}

// Overloaded Constructor
User::User(string aName, int aHP, vector<Super> aSuper, int aDamage) 
{
	fHP = aHP;
	fSuper = aSuper;
	fDamage = aDamage;
	fName = aName;
}

// returns user name
string User::getUserName() 
{
	return fName;
}

// returns user hp
int User::getHP() 
{
	return fHP;
}

// sets user hp
void User::setHP(int aHP) 
{
	fHP = aHP;
}

// displays the chosen super power
Super& User::getSuper(int aUserInput) 
{
	return fSuper[aUserInput];
}

//adds super power
void User::addSuper(Super aSuper) 
{
	fSuper.push_back(aSuper);
}

// returns user damage
int User::getDamage() 
{
	return fDamage;
}

// user user damage
void User::setDamage(int aDamage) 
{
	fDamage = aDamage;
}

// to be overridden in derived classses
void User::hit(User& aUser) { }

// apply super power to the user
string User::useSuper(User& aTarget, Super aSuper) 
{
	string returnedString = "";
	if (aTarget.getDamage() == 5) 
	{
		aTarget.setHP(aTarget.getHP() - aSuper.getDamage());
		returnedString = "The powerful dragon attacks you viciously " + aSuper.getName() + "\nDamage: " + to_string(aSuper.getDamage());
	}
	else if (aTarget.getDamage() == 15) 
	{ 
		this->fDamage = aSuper.getDamage();
		this->hit(aTarget); 
		this->fDamage = 5;
		returnedString = "You mercilessly attack the dragon " + aSuper.getName() + "\nDamage: " + to_string(aSuper.getDamage());
	}
	return returnedString;
}