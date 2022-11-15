#pragma once
#include <iostream>
#include <conio.h>
#include "Slayer.h"
#include "Dragon.h"
#include "Action.h"
#include "skillsMap.h"
#include "BattleBoosts.h"

using namespace std;

class War {
private:
	//slayer
	Slayer* fSlayer;
	//dragon
	Dragon* fDragon; 
	//in action user
	Action* fAction;
	//super power in use determined by tree
	skillsMap* fskillsMap;
	//boosts to be applied
	BattleBoosts* fVisitor;

public:
	//Default constructor
	War(); 

	//Destructor
	virtual ~War(); 

	//Overloaded constructor
	War(Slayer& aSlayer, Dragon& aDragon, Action& aAction, skillsMap& askillsMap); 
	
	//set visitor for battle boosts
	void setVisitor(BattleBoosts& aVisitor);

	//battle scene
	string battle(); 

	//display attack
	void hitLists();
};