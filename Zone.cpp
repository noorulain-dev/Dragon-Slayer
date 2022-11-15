#include <iostream>
#include "Zone.h"

using namespace std;

// Default Contructor
Zone::Zone() 
{

}

// Destructor
Zone::~Zone() 
{ 

}

// Overloaded constructor
Zone::Zone(string aName, string aDesc) 
{
	fName = aName;
	fDesc = aDesc;
}

// returns zone name
string Zone::getName() 
{
	return fName;
}

// returns zone description
string Zone::getDesc() 
{
	return fDesc;
}

// returns zone status
bool Zone::getStatus() 
{
	return fStatus;
}

// returns used status
void Zone::setStatus(bool aStatus) 
{
	fStatus = aStatus;
}

// << operator overload
ostream& operator<<(ostream& aOstream, const Zone& aZone) 
{
	aOstream << aZone.fName;
	return aOstream;
}