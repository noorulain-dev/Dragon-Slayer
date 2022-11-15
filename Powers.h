#pragma once
#include <iostream>
#include <string>
#include "Slayer.h"

using namespace std;

class Powers 
{
private:
	//status of powers
	bool fStatus; 
	//type of powers
	string fType; 
	//magnitude of powers
	int fSize;

public:
	//Default Constructor
	Powers(); 

	//Destructor
	~Powers(); 

	//Overloaded Constructor
	Powers(string aType, int aSize);

	//slayer impact by powers
	void affectSlayer(Slayer& aSlayer);

	//getter for power status
	bool getStatus(); 

	//getter for power type
	string getType();

	//getter for power magnitude
	int getSize(); 

	//setter for power status
	void setStatus(bool aStatus);

};