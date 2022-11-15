#include <iostream>
#include "Super.h"

using namespace std;

// Default Constructor
Super::Super() 
{ 

}

// Destructor
Super::~Super() 
{

}

// Overloaded Constructor
Super::Super(string aName, int aDamage) 
{
	fName = aName;
	fDamage = aDamage;
}

// returns name of super power
string Super::getName() 
{
	return fName;
}

// returns damage of super pwoer
int Super::getDamage() 
{
	return fDamage;
}

// sets damage of super power
void Super::setDamage(int aDamage) 
{
	fDamage = aDamage;
}
