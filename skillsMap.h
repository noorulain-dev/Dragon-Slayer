#pragma once
#include <iostream>
#include "BattleBoosts.h"
#include "QueueInTree.h"
#include "Boost.h"
#include "Slayer.h"
#include "Keys.h"

using namespace std;

class skillsMap {
private:
	//value of tree
	Boost* fContent; 

	//left node
	skillsMap* fLeft;

	//right node
	skillsMap* fRight;

public:
	//nil node
	static skillsMap NIL; 

	//Default Constructor
	skillsMap(); 

	//Destructor
	~skillsMap(); 

	//Overloaded Constructor
	skillsMap(Boost& aBoost); 

	//checks whether tree is empty
	bool isEmpty();

	//getter for tree content
	Boost& getContent();

	//getter for left node
	skillsMap& left();

	//getter for right node
	skillsMap& right();

	//attach node to left
	void attachLeft(Boost& aBoost);

	//attach node to right
	void attachRight(Boost& aBoost);

	// remove left node
	skillsMap& detachLeft();

	//remove right node
	skillsMap& detachRight();

	//call to accept visitor
	string acceptVisitor(BattleBoosts& aBattleBoosts, Slayer& aSlayer);

	//display boost details
	void displayBoost();

	//check if boost is working
	Boost& checkBoost();
};