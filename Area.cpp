#include <iostream>
#include "Area.h"
#include "War.h"

using namespace std;

/// Default Constructor
Area::Area() 
{

}

// Destructor
Area::~Area() 
{

}

// Overloaded Constructor
Area::Area(Zone aZoneList[4], bool aPermission) 
{
	for (int i = 0; i < 4; i++) 
	{
		fZoneList[i] = aZoneList[i];
	}
	fPermission = aPermission;
}

// Ask the War to regulate the battle
string Area::launchFight(War& aWar) 
{
	return aWar.battle();
}

// returns permission
bool Area::getPermission() 
{
	return fPermission;
}

// sets permission
void Area::setPermission(bool aPermission) 
{
	fPermission = aPermission;
}

// returns the detail of the the zone
string Area::DisplayArea(int aIndex) 
{
	return fZoneList[aIndex].getDesc();
}