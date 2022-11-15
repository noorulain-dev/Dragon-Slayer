#pragma once
#include <iostream>
#include "Slayer.h"
#include "Boost.h"
using namespace std;
//interface
class BattleBoosts 
{
public:
	//virtual function
	virtual string Visit(Slayer& aSlayer);
};

//concrete mighty class
class BattleBoostsMighty : public BattleBoosts 
{
private:
	//strength in int
	int fStrength; 
public:
	//overloaded constructor
	BattleBoostsMighty(int aStrength);
	//function to empower and strengthen the slayer
	virtual string Visit(Slayer& aSlayer); 
};

// concrete stealth class
class BattleBoostsStealth : public BattleBoosts 
{
public:
	//function to weaken the dragon
	virtual string Visit(Dragon& aDragon);
};