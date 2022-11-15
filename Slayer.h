#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Super.h"
#include "User.h"
#include "Area.h"
#include "DoublyNode.h"
#include "DoublyList.h"
#include "Object.h"
#include "Dragon.h"
#include "Itr.h"

using namespace std;

class Slayer : public User {
public:
	//Doubly List node collection
	typedef DoublyNode<Object>::Node Collection; 

private:
	//slayer energy in int
	int fEnergy; 

	//object equipped by slayer
	Object fObjectEquipped;

	//collection of objects
	Collection fCollection;

	//check if player has energy left
	bool fEnergised;

	//check whether player has health points left
	bool fStatus;

	//check if the slayer is revived
	bool fRestart;

	// amount of gold
	int fGold;

	//level of slayer
	int fLevel;

public:
	//Default Constructor
	Slayer(); 

	//Destructor
	virtual ~Slayer(); 

	//Overloaded Constructor
	Slayer(string aName, int aHP, vector<Super> aSuper, int aHitDamage, int aEnergy, int aGold, int aLevel); 

	//returns the energy
	int getEnergy();

	//sets the energy
	void setEnergy(int aEnergy);

	//displays the collection
	void showCollectionList(Itr<Object>& aItr);

	//adds object to the collection
	void addObject(Object& aNewObject);

	//remove object from collection
	void throwObject(Collection& aObject);

	//get first object in the collection
	DoublyNode<Object>& getFirstObject();

	//returns the equipped object
	Object& getObjectEquipped();

	// slayer hits the dragon
	void hit(User& aUser) override;

	//returns the fEnergised
	bool getEnergised(); 

	//sets the fEnergised
	void setEnergised(bool aHaveEnergy);

	//returns the slayer status
	bool getStatus();

	//sets the slayer status
	void setStatus(bool aAlive);

	//checks if an object is in the collection
	bool checkObject(Itr<Object>& aItr, Object& aObject);

	//returns if slayer is revived
	bool getRestart();

	//sets slayer revived
	void setRestart(bool aRevived); 

	//returns amount of gold
	int getGold();

	//sets amount of gold
	void setGold(int aGold);

	//returns level of slayer
	int getLevel();

	//sets level of slayer
	void setLevel(int aLevel);
};