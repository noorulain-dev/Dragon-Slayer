#include <iostream>
#include "Impact.h"
#include "Slayer.h"

using namespace std;

// Destructor
Impact::~Impact() 
{ 

}

// Impact on the slayer
void Impact::applyImpact(Object& aObject, Slayer& aSlayer) 
{
	aSlayer.setHP(aSlayer.getHP() + aObject.getPower());
}