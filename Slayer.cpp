#include <iostream>
#include "Slayer.h"

using namespace std;

// Default Constructor
Slayer::Slayer() 
{

}

// Destructor
Slayer::~Slayer() 
{

}

// Overloaded Constructor
Slayer::Slayer(string aUserName, int aHP, vector<Super> aSuperSet, int aHitDamage, int aEnergy, int aGold, int aLevel) : User(aUserName, aHP, aSuperSet, aHitDamage) 
{
	fEnergy = aEnergy;
	fEnergised = true;
	fStatus = true;
	fRestart = false;
	fGold = aGold;
	fLevel = aLevel;
}

// returns slayer energy
int Slayer::getEnergy() 
{
	return fEnergy;
}

// sets slayer energy
void Slayer::setEnergy(int aEnergy) 
{
	fEnergy = aEnergy;
}

// displays collection
void Slayer::showCollectionList(Itr<Object>& aItr) 
{
	//temp pointer pointing at first node
	Collection* ptr = &(fCollection.getFirstNode()); 
	DoublyList<Object>* lDoublyPtr = dynamic_cast<DoublyList<Object>*>(&aItr);
	//collection list displayed on loop
	bool loop = true;
	int keyPressed;
	//if collection is empty
	if (ptr->getValue().getName() == "") {
		cout << "Jeez, I don't have any object" << endl;
		cout << "===============================" << endl;
	}
	//if collection isnt empty
	else {
		system("cls");
		while (loop == true) {
			cout << "*****************************" << endl;
			cout << " Collection " << endl;
			cout << "*****************************" << endl;
			//object name
			cout << *aItr << endl; 
			cout << "1. Previous Object" << endl;
			cout << "2. Next Object" << endl;
			cout << "3. Use Object" << endl;
			cout << "0. Close Collection" << endl;
			cout << "*****************************" << endl;
			keyPressed = _getch(); 
			switch (keyPressed) 
			{
			case 49: 
				//previous object
				system("cls");
				//if the beginning of the list is reached
				if (aItr == aItr.begin()) 
				{ 
					cout << "I have nothing left inside of here" << endl;
				}
				//else
				else if (aItr != aItr.begin()) 
				{
					aItr--;
				}
				break;
			case 50: 
				//Next Object
				//if the end of the list is reached
				if (aItr == aItr.end()) 
				{
					system("cls");
					cout << "I have touched all objects" << endl;
				}
				//else
				else if (aItr != aItr.end()) 
				{ 
					system("cls");
					aItr++;
				}
				break;
			case 51:
				//equip object
				if (ptr->getValue().getPotion() == false) 
				{
					fObjectEquipped = *aItr;
					if (fObjectEquipped.getName() == "Cold Potion" || fObjectEquipped.getName() == "Warm Potion") 
					{
						ptr->getValue().setPotion(true);
					}
					//object equipped
					system("cls");
					loop = false;
				}
				else 
				{
					system("cls");
					cout << "I have already used this object";
				}
				break;
			case 48: 
				//Close Collection
				system("cls"); 
				loop = false;
				break;
			default: //Invalid input
				system("cls");
				cout << "Invalid input" << endl;
			}
		}
	}
}
// Add an object to the Collection
void Slayer::addObject(Object& aNewObject) 
{
	Collection* newNode = new Collection(aNewObject); //Make a node from the passed Object
	if (fCollection.getFirstNode().getValue().getName() == "") 
	{ //If it will be the first node, we set it as the first
		fCollection.setFirstNode(*newNode);
	}
	else 
	{ //If there has been another node, we will take the lastest node and append the new node after it.
		fCollection.getLastNode().append(*newNode);
	}
}

// remove the object from the list
void Slayer::throwObject(Collection& aObject) 
{
	aObject.remove();
}

// return first object of the list
DoublyNode<Object>& Slayer::getFirstObject() 
{
	return fCollection.getFirstNode();
}

// return equipped object
Object& Slayer::getObjectEquipped() 
{
	return fObjectEquipped;
}

// hit the dragon
void Slayer::hit(User& aUser) 
{ 
	Dragon* dragon = dynamic_cast<Dragon*>(&aUser);
	//when dragon strength has ended attack on it
	if (dragon->getStrength() <= 0) 
	{
		dragon->setHP(dragon->getHP() - this->getDamage());
	}
	//else if the attack doesnt end the strength then
	else if (dragon->getStrength() - this->getDamage() >= 0) 
	{ 
		dragon->setStrength(dragon->getStrength() - this->getDamage());
	}
	//else if the attack ends the dragon strength then
	else if (dragon->getStrength() - this->getDamage() < 0) 
	{ 
		dragon->setStrength(0);
		int remainder = abs(dragon->getStrength() - this->getDamage());
		dragon->setHP(dragon->getHP() - remainder);
	}
}
// returns energised status
bool Slayer::getEnergised() 
{
	return fEnergised;
}

// sets energised status
void Slayer::setEnergised(bool aEnergy) 
{
	fEnergised = aEnergy;
}

// returns slayer status
bool Slayer::getStatus() 
{
	return fStatus;
}
// sets slayer status
void Slayer::setStatus(bool aAlive) 
{
	fStatus = aAlive;
}

// search object in collection
bool Slayer::checkObject(Itr<Object>& aItr, Object& aObject) 
{
	//when its not the end of the list
	while (aItr != aItr.end())
	{
		//when object is found, return true
		if (*aItr == aObject) 
		{
			return true;
		}
		//else check the next node in the list
		aItr++; 
	}
	//if the end of the list is reached
	if (aItr == aItr.end()) 
	{
		//if object is found return true
		if (*aItr == aObject) 
		{ 
			return true;
		}
		// else return false
		else 
		{ 
			return false;
		}
	}
	//reset iterator to start from the beginning
	while (aItr != aItr.begin()) 
	{
		aItr--;
	}
}

// return restart status
bool Slayer::getRestart() 
{
	return fRestart;
}
// set restart status
void Slayer::setRestart(bool aRestart) 
{
	fRestart = aRestart;
}

//return slayer level
int Slayer::getLevel() 
{
	return fLevel;
}
// set slayer level
void Slayer::setLevel(int aLevel) 
{
	fLevel = aLevel;
}

// return slayer gold
int Slayer::getGold() 
{
	return fGold;
}

//set slayer gold
void Slayer::setGold(int aGold) 
{
	fGold = aGold;
}