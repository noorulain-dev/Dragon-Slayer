#include <iostream>
#include "Object.h"

using namespace std;

// Default Constructor
Object::Object() 
{ 

}

// Destructor
Object::~Object() 
{ 

}

// Overloaded Constructor
Object::Object(string aName, string aDetails, int aPower, bool aPotion) 
{
	fName = aName;
	fDetails = aDetails;
	fPower = aPower;
	fStatus = false;
	fPotion = aPotion;
}

// returns object name
string Object::getName() 
{
	return fName;
}

// returns power
int Object::getPower() 
{
	return fPower;
}

// returns status
bool Object::getStatus() 
{
	return fStatus;
}

// sets status
void Object::setStatus(bool aStatus) 
{
	fStatus = aStatus;
}

//returns potion status
bool Object::getPotion() 
{
	return fPotion;
}

// sets potion status
void Object::setPotion(bool aPotionStatus) 
{
	fPotion = aPotionStatus;
}

// applies impact on slayer
void Object::impact(Impact& aImpact, Slayer& aSlayer) 
{
	aImpact.applyImpact(*this, aSlayer);
}

// equivalence operator for objects
bool Object::operator==(const Object& aOther) const 
{
	if (this->fName == aOther.fName) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

// inequivalence operator for objects
bool Object::operator!=(const Object& aOther) const 
{
	return !(*this == aOther);
}

// << operator overload
ostream& operator<<(ostream& aOstream, const Object& aObject) 
{
	aOstream << aObject.fName << endl;
	aOstream << "Description: " << aObject.fDetails << endl;
	return aOstream;
}