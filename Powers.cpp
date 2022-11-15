#include <iostream>
#include "Powers.h"

using namespace std;

// Default Constructor
Powers::Powers() 
{ 

}

// Destructor
Powers::~Powers() 
{ 

}

// Overloaded constructor
Powers::Powers(string aType, int aEffectSize) 
{
	fType = aType;
	fSize = aEffectSize;
	fStatus = false;
}

// impact the slayer of powers
void Powers::affectSlayer(Slayer& aSlayer) 
{
	if (fStatus == true) 
	{
		if (fType == "Paralysis") 
		{
			cout << "My body is getting paralysed, I must leave this place to get rid of the curse" << endl;
			aSlayer.setHP(aSlayer.getHP() - fSize); //Reduce the slayer HP
		}
		else if (fType == "Deafness") 
		{
			cout << "This silence is killing me" << endl;
			aSlayer.setEnergy(aSlayer.getEnergy() - fSize);
			//Reduce the slayer Energy
		}
	}
}

// returns power status
bool Powers::getStatus() 
{
	return fStatus;
}

// returns power type
string Powers::getType() 
{
	return fType;
}

// returns power size
int Powers::getSize() 
{
	return fSize;
}

// sets power status
void Powers::setStatus(bool aStatus) 
{
	fStatus = aStatus;
}