#include <iostream>
#include "War.h"

using namespace std;

// Default constructor
War::War() 
{

}

// Destructor
War::~War() {

}

// Overloaded Constructor
War::War(Slayer& aSlayer, Dragon& aDragon, Action& aAction, skillsMap& askillsMap) 
{
	fSlayer = &aSlayer;
	fDragon = &aDragon;
	fAction = &aAction;
	fskillsMap = &askillsMap;
}

// Set the visitor for the battle
void War::setVisitor(BattleBoosts& aBattleBoosts) 
{
	fVisitor = &aBattleBoosts;
}

// start the war
string War::battle() 
{ 
	string result = ""; //message to be displayed
	int keyPressed; 
	int tempStorage;
	User& nextChar = fAction->nextUser();
	if (nextChar.getUserName() == "Dragon") 
	{ 
		//Dragon turn to attack
		cout << "************************************" << endl;
		cout << " DRAGON " << endl;
		cout << "************************************" << endl;
		system("pause");
		keyPressed = (rand() % 3) + 1; //Random number between 1, 2 and 3.
		switch (keyPressed) 
		{
		case 1: 
			tempStorage = fDragon->getDamage(); //get attack damage
			fDragon->hit(*fSlayer); //substract it from slayer's hp
			result = "Dragon attacks you with fire and dagger like paws\nDamage: " + to_string(fDragon->getDamage());
			fDragon->setDamage(tempStorage); //damage value is reset
			break;
		case 2: 
			tempStorage = fDragon->getSuper(0).getDamage(); //get damage of attack
			result = fDragon->useSuper(*fSlayer, fDragon->getSuper(0)); //get message
			fDragon->getSuper(0).setDamage(tempStorage); //damage value reset after imparting it
			break;
		case 3:
			tempStorage = fDragon->getSuper(1).getDamage(); //get damage of attack
			result = fDragon->useSuper(*fSlayer, fDragon->getSuper(1));
			fDragon->getSuper(1).setDamage(tempStorage); //damage value reset after imparting it
			break;
		default: //Invalid Input
			keyPressed = (rand() % 3) + 1; //generate random number
			break;
		}
	}
	else 
	{
		hitLists();
		cout << "*********************************" << endl;
		cout << "				SLAYER			  " << endl;
		cout << "*********************************" << endl;
		keyPressed = _getch();
		switch (keyPressed) {
		case 49: 
			//Hit dragon
			fSlayer->hit(*fDragon); 
			//subtract the damage from dragons HP
			result = "You attacked \nDamage: " + to_string(fSlayer->getDamage());
			break;
			//if the status of the skill is true, then the visitor is sent to activate the super power boost
		case 50:
			if (fskillsMap->right().left().getContent().getStatus() == true) 
			{
				result = "Prepare to face my mighty wrath. I shall make my kingdom proud!\n"  + fskillsMap->acceptVisitor(*fVisitor, *fSlayer);
			}
			else if (fskillsMap->right().right().getContent().getStatus() == true) 
			{
				result = "Prepare to face my mighty wrath. I shall make my kingdom proud!\n" +  fskillsMap->acceptVisitor(*fVisitor, *fSlayer);
			}
			else 
			{
				result = fSlayer->useSuper(*fDragon, fSlayer->getSuper(0));
			}
			fSlayer->setEnergy(fSlayer->getEnergy() - 2); 
			break;

			//if the status of the skill is true, then the visitor is sent to activate the super power boost
		case 51:
			if (fskillsMap->left().left().getContent().getStatus() == true) 
			{
				result = "Prepare to face my mighty wrath. I shall make my kingdom proud!\n" + fskillsMap->acceptVisitor(*fVisitor, *fSlayer);
			}
			else if (fskillsMap->left().right().getContent().getStatus() == true) 
			{
				result = "Prepare to face my mighty wrath. I shall make my kingdom proud!\n" + fskillsMap->acceptVisitor(*fVisitor, *fSlayer);
			}
			else 
			{
				result = fSlayer->useSuper(*fDragon, fSlayer->getSuper(1));
			}
			fSlayer->setEnergy(fSlayer->getEnergy() - 1); //Consumes 1 energy
			break;
		default: //Invalid Input
			result = "Enter a valid comand to fight the dragon!";
			break;
		}
	}
	return result; //string of message
}

// attacks list which can be used to impart damage on user
void War::hitLists() {
	cout << "********************************" << endl;
	cout << "			ATTACKS" << endl;
	cout << "********************************" << endl;
	cout << "1. Stab" << endl;
	if (fskillsMap->left().getContent().getStatus() == true ||
		fskillsMap->left().left().getContent().getStatus() == true ||
		fskillsMap->left().right().getContent().getStatus() == true) 
	{
		cout << "2. Burn" << endl;
	}
	if (fskillsMap->right().left().getContent().getStatus() == true) 
	{
		cout << "2. Drown" << endl;
	}
	if (fskillsMap->right().right().getContent().getStatus() == true) 
	{
		cout << "2. Melt" << endl;
	}
	if (fskillsMap->right().getContent().getStatus() == true ||
		fskillsMap->right().left().getContent().getStatus() == true ||
		fskillsMap->right().right().getContent().getStatus() == true) 
	{
		cout << "3. Blind" << endl;
	}
	if (fskillsMap->left().left().getContent().getStatus() == true) 
	{
		cout << "3. Bury" << endl;
	}
	if (fskillsMap->left().right().getContent().getStatus() == true) 
	{
		cout << "3. Impair" << endl;
	}
	cout << "**********************************************" << endl;
}