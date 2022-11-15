#pragma once
#include <iostream>
#include "Zone.h"

using namespace std;

class War;

class Area {
private:
	//creating an array list of 4 zones
	Zone fZoneList[4];

	//whether the user has permission to enter the zone
	bool fPermission; 

public:
	//Default Constructor
	Area(); 

	//Destructor
	~Area(); 

	//Overloaded Constructor
	Area(Zone aZoneList[4], bool aPermission); 

	//starts the fight 
	string launchFight(War& aWar); 

	//gets the permission
	bool getPermission(); 

	//sets the permission
	void setPermission(bool aPermission);

	//returns details of zone
	string DisplayArea(int aIndex);

};