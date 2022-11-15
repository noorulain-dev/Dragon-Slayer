#pragma once
#include <iostream>

using namespace std;

//declaration
class Slayer;
class Object;

//Interface
class Impact 
{
public:
	//Destructor
	virtual ~Impact(); 

	//apply impact on slayer
	virtual void applyImpact(Object& aObject, Slayer& aSlayer);
};