#include "Boost.h"

// Default Constructor
Boost::Boost() 
{ 

}

// Destructor
Boost::~Boost() 
{ 

}

// Overloaded constructor
Boost::Boost(int aLevel, string aName, string aDesc, bool aStatus) 
{
	fLevel = aLevel;
	fName = aName;
	fDesc = aDesc;
	fStatus = aStatus;
}

// returns boost level
int Boost::getLevel() 
{
	return fLevel;
}

// returns boost name
string Boost::getName() 
{
	return fName;
}

// returns boost description
string Boost::getDesc() 
{
	return fDesc;
}

// returns boost status
bool Boost::getStatus() 
{
	return fStatus;
}

// sets boost status
void Boost::setStatus(bool aStatus) {
	fStatus = aStatus;
}
