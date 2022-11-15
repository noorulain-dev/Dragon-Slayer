#include <iostream>
#include <string>
#include <conio.h>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <random>
#include <fstream>
#include "User.h"
#include "DoublyNode.h"
#include "Impact.h"
#include "Powers.h"
#include "War.h"
#include "Zone.h"
#include "Object.h"
#include "Itr.h"
#include "DoublyList.h"
#include "SinglyList.h"
#include "Dragon.h"
#include "Slayer.h"
#include "Area.h"
#include "SinglyNode.h"
#include "Super.h"
#include "Keys.h"
#include "QueueInTree.h"
#include "Entails.h"
#include "Boost.h"
#include "BattleBoosts.h"
#include "skillsMap.h"
#include "Action.h"

using namespace std;
//string to store warriors name
string warriorName;
//string to store text
string answer;
//status of gameplay
bool gameStatus = true;


void Weapon(Slayer& aSlayer) 
{
	//checking if the user is objected with any key
	//then the key is shown on the screen
	if (aSlayer.getObjectEquipped().getName() == "Metal Key" || aSlayer.getObjectEquipped().getName() == "dragon Key" || aSlayer.getObjectEquipped().getName() == "Iron Key" || aSlayer.getObjectEquipped().getName() == "Steele Key" || aSlayer.getObjectEquipped().getName() == "Marble Key") 
	{
		if (aSlayer.getObjectEquipped().getStatus() == false) 
		{
			cout << "\n" << endl;
			cout << "  ,o.          8 8" << endl;
			cout << " d   bzzzzzzzza8o8b" << endl;
			cout << "  `o'" << endl;
		}
	}

	//checking if the user has equipped a potion
	//if yes, then the user is upgraded
	else if (aSlayer.getObjectEquipped().getName() == "Warm Potion") 
	{
		if (aSlayer.getObjectEquipped().getStatus() == false) 
		{ //Show the healing potion that has not been usedand apply the effect of the potion
			cout << "\nI feel much better now" << endl;
			aSlayer.setHP(aSlayer.getHP() + aSlayer.getObjectEquipped().getPower()); //Get additional HP
			aSlayer.getObjectEquipped().setStatus(true);
		}
		else 
		{
			cout << "\nHmm empty warm bottle" << endl; //Potion has been used
		}
	}
}

//status bar of the slayer
//displays the name, gold, level, health, and energy of the player throughout the game
void Stat(Slayer& aSlayer) 
{
		Weapon(aSlayer);
		cout << "Warrior Name: " << warriorName << endl;
		Weapon(aSlayer); //Show the Object equipped by the slayer
		if (aSlayer.getHP() <= 0)
		{ //shows health of the slayer
			cout << "HP: 0" << endl;
		}

		else 
		{
			cout << "HP: " << aSlayer.getHP() << endl;
		}

		if (aSlayer.getEnergy() <= 0) 
		{ //displays energy of the slayer
			cout << "Energy: 0" << endl;
		}

		else 
		{
			cout << "Energy: " << aSlayer.getEnergy() << endl;
		}

		if (aSlayer.getLevel() <= 0) 
		{ //displays level of the slayer
			cout << "Level: 0" << endl;
		}

		else 
		{
			cout << "Level: " << aSlayer.getLevel() << endl;
		}

		if (aSlayer.getGold() <= 0) 
		{ //displays the gold possessed by the slayer
			cout << "Gold: 0" << endl;
		}

		else 
		{
			cout << "Gold: " << aSlayer.getGold() << endl;
		}

		//art of the dragon slayer
		cout << "        !" << endl;
		cout << "       .-." << endl;
		cout << "     __|=|__" << endl;
		cout << "    (_/`-`\_)" << endl;
		cout << "    //\___/\\" << endl;
		cout << "    <>/   \<>" << endl;
		cout << "     \|_._|/" << endl;
		cout << "      <_I_>" << endl;
		cout << "       |||" << endl;
		cout << "      /_|_\ " << endl;
		cout << "---------------------------------" << endl;
		cout << "---------------------------------" << endl;
}

//status bar of the dragon
void DragonUI(Dragon& aDragon) 
{
	cout << "dragon: " << endl;
	if (aDragon.getHP() <= 0) 
	{ //displays hp of the dragon
		cout << "HP: 0" << endl;
	}
	else 
	{
		cout << "HP: " << aDragon.getHP() << endl;
	}

	if (aDragon.getStrength() <= 0) 
	{ //displays strength of protection armor of the dragon
		cout << "Protection Armor: 0" << endl;
	}
	else 
	{
		cout << "Protection Armor: " << aDragon.getStrength() << endl;
	}

	//dragon art in ascii
	cout << "           ____ __" << endl;
	cout << "          { --.\  |          .)%%%)%%" << endl;
	cout << "           '-._\\ | (\___   %)%%(%%(%%%" << endl;
	cout << "               `\\|{/ ^ _)-%(%%%%)%%;%%%" << endl;
	cout << "           .'^^^^^^^  /`    %%)%%%%)%%%'" << endl;
	cout << "          //\   ) ,  /       '%%%%(%%'" << endl;
	cout << "    ,  _.'/  `\<-- \< " << endl;
	cout << "     `^^^`     ^^   ^^" << endl;
	cout << "" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------" << endl;

}

// the commands for user
void Command() 
{
	cout << "    Mapping     " << endl;
	cout << "******************" << endl;
	cout << "(N) Step north" << endl;
	cout << "(S) Step south" << endl;
	cout << "(E) Step east" << endl;
	cout << "(W) Step west" << endl;
	cout << "(C) Display Collection" << endl;
}

// when invalid command is entered by user
void InvalidInput() 
{
	cout << "Please enter a valid command" << endl;
}

//when the slayer is revived upon death
void Revival(Slayer* slayer, skillsMap* BoostTree) 
{
	system("cls");
	Stat(*slayer);
	cout << "You have selected:\n  " << endl;

	//displays the power selected
	BoostTree->displayBoost(); 
	system("pause");
	system("cls");
	Stat(*slayer);

	//setting the first level powers to false to display the second level power which is chosen
	BoostTree->left().getContent().setStatus(false);
	BoostTree->right().getContent().setStatus(false);

	//display the chosen super power
	cout << "			Super Power:" << BoostTree->checkBoost().getName() << endl;
	cout << "*********************************" << endl;
	Stat(*slayer);
	cout << "Avenge yourself and the ones who came before you!  " << endl;
	system("pause");
	system("cls");

	//reseeting the status of slayer upon revival
	slayer->setHP(slayer->getHP() + 200);
	slayer->setEnergy(100);
}

//main class
int main() 
{
	srand(time(0)); 
	//Seed the random number generator
	//initialising the objects
	// initialising them inside the main class to be used and reused and deleted whenever necessary
	Object* healingPotion = new Object("Healing potion", "\nWhoa, this is a healing potion! What great luck!", 100, false);
	Object* airKey = new Object("Metal key", "\nFound an air key, maybe this will help get us out of here", 0, false);
	Object* earthKey = new Object("Iron key", "\nFound an earth key, maybe this will help get us out of here", 0, false);
	Object* waterKey = new Object("Steel key", "\nFound a water key, maybe this will help get us out of here", 0, false);
	Object* fireKey = new Object("Marble key", "\nFound a fire key, maybe this will help get us out of here", 0, false);
	Object* ring = new Object("Ring", "\nIt is exquisite. This place is filled with treasures of all kinds!", -20, false);
	Object* bandage = new Object("Ointment", "\nThis ointment will help with recoveries", 50, false);
	Object* energyPotion = new Object("Energy Elixir", "\nThis elixir is crucial for me to keep moving ahead", 20, false);
	Object* dragonKey = new Object("dragon key", "\nThis dragon key is the ultimatum which combines the power of all four keys to unlock the potential of fighting a dragon", 0, false);
	
	//Super powers
	//For Dragon
	Super* fire = new Super("Fire", 30);
	Super* lava = new Super("Lava", 25);
	vector<Super> dragonSuperSet = 
	{ 
		*fire, *lava 
	};

	//Super powers
	//For Slayer
	Super* sputify = new Super("Sputify", 35);
	Super* tsunami = new Super("Tsunami", 20);
	vector<Super> slayerSuperSet = 
	{ 
		*sputify, *tsunami 
	};

	//Zones in the game
	//creating objects which are inside the zones
	Zone* winGold = new Zone("Win Gold\n", "For 25 Gold, get a chance to win over 100 bars of gold! or meet your impending doom..");
	Zone* secretChamber = new Zone("Secret Chambers\n", "Head to the chamber of secrets and unravel what lies hidden");
	Zone* horrorChamber = new Zone("Horror Chambers\n", "Head to the chamber of horrors and face the terror");
	Zone* dragonLair = new Zone("dragon's Lair", "Head to the heart of the dragon's Lair and come out stronger than ever");

	Zone* mainChamber = new Zone("Main Chambers\n", "Head back to the Main Chambers");
	Zone* spells = new Zone("Spells", "Oh what magical spells lie here. I need their power to become the ultimate dragon slayer");
	Zone* scroll = new Zone("Ancient Scroll", "This ancient scroll contains the names of all slayed dragons");
	Zone* energyElixir = new Zone("Energy Elixir", "I can Boost my energy by injecting myself with Energy Elixir for 20 gold bars");

	Zone* healthHerb = new Zone("Health Herb", "I can regain my strength by purchasing a health herb from this shop for 25 gold bars");
	Zone* carcass = new Zone("dragon Carcass", "I wonder how long ago this dragon died for its carcass to rot this way");
	Zone* renewData = new Zone("slayer Card", "I can upgrade my dragon slayer name from this database by spending 100 gold bars");

	//Main Chambers zone
	Zone mainCham[4] = 
	{ 
		*winGold, *secretChamber, *horrorChamber, *dragonLair 
	};

	Area* mainChambers = new Area(mainCham, true);

	//Secret chambers zone
	Zone secretCham[4] = 
	{ 
		*mainChamber, *spells, *scroll, *energyElixir
	};

	Area* secretChambers = new Area(secretCham, false);

	//horror chambers zone
	Zone horrorCham[4] = 
	{ 
		*healthHerb, *mainChamber, *carcass, *renewData 
	};

	Area* horrorChambers = new Area(horrorCham, false);

	//Dragons lair zone
	Zone lair[4] = 
	{
		*carcass, *carcass, *carcass, *carcass 
	};

	Area* dragonsLair = new Area(lair, false);

	//Powers
	Powers* paralysis = new Powers("Paralysis", 5);
	Powers* deafness = new Powers("Deafness", 3);

	//impacts of different powers on the slayer
	SinglyNode<Powers> paralysisNode(*paralysis);
	SinglyNode<Powers> deafnessNode(*deafness, &paralysisNode);
	SinglyNode<Powers>* firstSinglyNode = &deafnessNode;

	//Boosts for the slayer
	Boost* warrior = new Boost(0, "A warrior.", "A cursed man doomed to a lifetime of slaying battles with the powers of an ordinary man", true);
	Boost* waterWarrior = new Boost(2, "Aqua Warrior.", "A cursed warrior bequethed with the power to bend water", false);
	Boost* fireWarrior = new Boost(2, "Fire Warrior.", "A cursed warrior bequethed upon with the power to bend fire", false);
	Boost* mightyWarrior = new Boost(1, "Mighty Warrior", "Clothed with immense power, this mighty soldier remains undefeated", true);
	Boost* stealthWarrior = new Boost(1, "Stealth Warrior", "This warrior has wills of steel and armor of gold to defeat whatever comes in his path", true);
	Boost* earthWarrior = new Boost(2, "Earth Warrior", "A cursed warrior bequethed upon with the power to bend Earth to his might", false);
	Boost* airWarrior = new Boost(2, "Air Warrior", "A cursed warrior bequethed upon with the power to bend air", false);

	//Creating a tree of boosts
	skillsMap* BoostTree = new skillsMap(*warrior);

	//Adding boosts to the left of the boost tree
	BoostTree->attachLeft(*mightyWarrior);
	BoostTree->left().attachLeft(*airWarrior);
	BoostTree->left().attachRight(*fireWarrior);

	//Adding booosts to right of the boost tree
	BoostTree->attachRight(*stealthWarrior);
	BoostTree->right().attachLeft(*earthWarrior);
	BoostTree->right().attachRight(*waterWarrior);

	//Implementing queue in boost tree
	//Visitor
	BattleBoosts* airBattleBoosts = new BattleBoostsMighty(100);
	BattleBoosts* waterBattleBoosts = new BattleBoostsStealth();
	BattleBoosts* fireBattleBoosts = new BattleBoostsStealth();
	BattleBoosts* earthBattleBoosts = new BattleBoostsMighty(150);

	//key pressed by the user
	int keyPressed;

	//initialising the slayer
	Slayer* slayer = new Slayer("Warrior", 100, slayerSuperSet, 5, 50, 50, 1);

	//initialising the fight ADT
	Action* action = new Action(*slayer, 2); //Time: O(1), Space: O(n)
												
	//initialising the dragon
	Dragon* dragon = new Dragon("Dragon", 300, dragonSuperSet, 15, 100);

	//inserting the dragon user to the action scene
	action->insertUser(*dragon);

	//doubly linked list initilaised after getting first object
	Itr<Object>* iterDoubly = new DoublyList<Object>(slayer->getFirstObject());
	DoublyList<Object>* doublyPtr = dynamic_cast<DoublyList<Object>*>(iterDoubly);

	//War
	War* battleWar = new War(*slayer, *dragon, *action, *BoostTree);

	//singly list containing slayer powers
	Itr<Powers>* iterSingly = new SinglyList<Powers>(*firstSinglyNode);

	//Stack of keys inside key box
	Keys<Object> keyBox(4);
	keyBox.push(*waterKey);
	keyBox.push(*earthKey); 
	keyBox.push(*fireKey); 
	keyBox.push(*airKey);

	// ******************* START OF GAME *******************
	//dragon ascii art
	cout << "                                        ,   ,                                " << endl;
	cout << "                                        $,  $,     ,                         " << endl;
	cout << "                                       \"ss.$ss..s'                          " << endl;
	cout << "                                ,     .ss$$$$$$$$$$s,                        " << endl;
	cout << "                                $. s$$$$$$$$$$$$$$`$$Ss                      " << endl;
	cout << "                                \"$$$$$$$$$$$$$$$$$$o$$$,  " << endl;
	cout << "                               s$$$$$$$$$$$$$$$$$$$$$$$$s,  ,s               " << endl;
	cout << "                              s$$$$$$$$$\"$$$$$$\"\"\"\"$$$$$$\"$$$$$,             " << endl;
	cout << "                              s$$$$$$$$$$s""$$$$ssssss\"$$$$$$$$\"             " << endl;
	cout << "                             s$$$$$$$$$$'         `\"\"\"ss\"$\"$s\"\"              " << endl;
	cout << "                             s$$$$$$$$$$,              `\"\"\"\"\"$.s$$s        " << endl;
	cout << "                             s$$$$$$$$$$$$s,...               `s$$'  `       " << endl;
	cout << "                         `ssss$$$$$$$$$$$$$$$$$$$$####s.     .$$\"$., s - " << endl;
	cout << "                           `\"\"\"\"$$$$$$$$$$$$$$$$$$$$#####$$$$$$\"     $.$'    " << endl;
	cout << "                                 \"$$$$$$$$$$$$$$$$$$$$$####s\"\".$$$ | " << endl;
	cout << "                                   \"$$$$$$$$$$$$$$$$$$$$$$$$##s.$$\" $    " << endl;
	cout << "                                   $$\"\"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\"   `    " << endl;
	cout << "                                  $$\"  \"$\"$$$$$$$$$$$$$$$$$$$$S\"\"\"\"'         " << endl;
	cout << "                             ,   ,\"     '  $$$$$$$$$$$$$$$$####s             " << endl;
	cout << "                             $.          .s$$$$$$$$$$$$$$$$$####\"            " << endl;
	cout << "                 ,           \"$s.   ..ssS$$$$$$$$$$$$$$$$$$$####\"            " << endl;
	cout << "                 $           .$$$S$$$$$$$$$$$$$$$$$$$$$$$$#####\"             " << endl;
	cout << "                 Ss     ..sS$$$$$$$$$$$$$$$$$$$$$$$$$$$######\"\"              " << endl;
	cout << "                  \"$$sS$$$$$$$$$$$$$$$$$$$$$$$$$$$########\"                  " << endl;
	cout << "           ,      s$$$$$$$$$$$$$$$$$$$$$$$$#########\"\"'                      " << endl;
	cout << "           $    s$$$$$$$$$$$$$$$$$$$$$#######\"\"'      s'         ,           " << endl;
	cout << "           $$..$$$$$$$$$$$$$$$$$$######\"'       ....,$$....    ,$            " << endl;
	cout << "            \"$$$$$$$$$$$$$$$######\"' ,     .sS$$$$$$$$$$$$$$$$s$$            " << endl;
	cout << "              $$$$$$$$$$$$#####\"     $, .s$$$$$$$$$$$$$$$$$$$$$$$$s.         " << endl;
	cout << "   )          $$$$$$$$$$$#####'      `$$$$$$$$$###########$$$$$$$$$$$.       " << endl;
	cout << "  ((          $$$$$$$$$$$#####       $$$$$$$$###\"       \"####$$$$$$$$$$      " << endl;
	cout << "  ) \         $$$$$$$$$$$$####.     $$$$$$###\"             \"###$$$$$$$$$   s'" << endl;
	cout << " (   )        $$$$$$$$$$$$$####.   $$$$$###\"                ####$$$$$$$$s$$' " << endl;
	cout << " )  ( (       $$\"$$$$$$$$$$$#####.$$$$$###'                .###$$$$$$$$$$\"   " << endl;
	cout << " (  )  )   _,$\"   $$$$$$$$$$$$######.$$##'                .###$$$$$$$$$$     " << endl;
	cout << " ) (  ( \.         \"$$$$$$$$$$$$$#######, , , .          ..####$$$$$$$$$$$\"     " << endl;
	cout << "(   )$ )  )        ,$$$$$$$$$$$$$$$$$$####################$$$$$$$$$$$\"       " << endl;
	cout << "(   ($$  ( \     _sS\"  `\"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$S$$,       " << endl;
	cout << " )  )$$$s ) )  .      .   `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\"'  `$$      " << endl;
	cout << "  (   $$$Ss/  .$,    .$,,s$$$$$$##S$$$$$$$$$$$$$$$$$$$$$$$$S\"\"        '      " << endl;
	cout << "    \)_$$$$$$$$$$$$$$$$$$$$$$$##\"  $$        `$$.        `$$.                " << endl;
	cout << "        `\"S$$$$$$$$$$$$$$$$$#\"      $          `$          `$                " << endl;
	cout << "            `\"\"\"\"\"\"\"\"\"\"\"\"\"'         '           '           '" << endl;
	cout << "" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	
	cout << "DRAGON SLAYER \n" << endl;

	system("pause");
	system("cls");

	cout << "Hundreds of years ago, in a far away land, \nthere was peace among humans and the fiery creatures in the sky called dragons \nUntil one day, a little boy was dared to kill a baby dragon to protect his little sister \nThat baby belonged to the king of dragons \nAlas it seemed like peace was never an option \nA war began and that little boy was outcast after swearing to protect his tribe \nHe was hence cursed to fight the dragons forever until in the hopes that peace would again be restored in their kingdom \nThus began the tale of the dragon slayer" << endl;

	//game starts
	while (gameStatus) 
	{
		//main menu to start or exit the game
		cout << "Main Menu:" << endl;
		cout << "1. Start" << endl;
		cout << "0. Exit" << endl;

		//the key pressed will determine the option chosen
		keyPressed = _getch(); 

		//heads to main chambers
		switch (keyPressed) 
		{

		case 49: //Enter the name you have chosen to give your dragon slayer

			system("cls");
			cout << "Here ye Here ye!" << endl;
			cout << "Please enter the name of your dragon slayer: " << endl;
			cin >> warriorName;

			//************Status of slayer is displayed************
			while (true)
			{
				Stat(*slayer);
				keyPressed = _getch();

				//checkpoint in game of opening screen

			openingScreen:
				slayer->setStatus(true);
				slayer->setEnergised(true);
				dragon->setHP(500);
				dragon->setStrength(100);
				slayer->setRestart(false);
				slayer->addObject(*energyPotion);
				slayer->addObject(*healingPotion);

				if (slayer->getHP() > 200) 
				{
					slayer->setHP(200);
				}

				//while the slayer is alive
				while (slayer->getStatus() == true && slayer->getEnergised() == true) 
				{
					//running a loop which will check if the user is under an impact of a power or not starting from first node
					while (*iterSingly != iterSingly->end()) 
					{ //Loop until the end
						Powers checkEffect = *(*iterSingly);
						checkEffect.affectSlayer(*slayer);
						(*iterSingly)++;
					}

					//if the loop reaches the end, then it resets
					if (*iterSingly == iterSingly->end()) 
					{
						Powers checkEffect = *(*iterSingly);
						checkEffect.affectSlayer(*slayer);
						SinglyList<Powers>* lSinglyPtr = dynamic_cast<SinglyList<Powers>*>(iterSingly);
						lSinglyPtr->setIterPointer(deafnessNode); 
					}
					 
					//checks if the slayer has hp and energy to on or not
					if (slayer->getHP() <= 0) 
					{
						slayer->setStatus(false);
					}

					if (slayer->getEnergy() <= 0) 
					{
						slayer->setEnergised(false);
					}

					//if not then it will go back to the first opening screen
					if (slayer->getStatus() == false || slayer->getEnergised() == false) 
					{
						break;
					}

					//checkpoint where the slayer may explore the different chambers
				searchLoop:

					Stat(*slayer);
					Object* objectPtr = &slayer->getObjectEquipped(); 
					//points to the object equipped by the slayer
					Command();
					keyPressed = _getch();

					//*****************************main chambers*****************************

					if (mainChambers->getPermission() == true) 
					{ //checks if slayers has permission to get into the chamber
						switch (keyPressed) 
						{
						case 78: case 110: 
							//N or n to head north
							if (slayer->getObjectEquipped().getName() == "dragon key") 
							{
								//checks if user is holding the dragon key
								cout << mainChambers->DisplayArea(2).c_str() << endl; //displays the info about the chambers
								system("pause");
								system("cls");

								//Move to battle room
								dragonsLair->setPermission(true);
								mainChambers->setPermission(false);
							}

							//if slayer is not equipped with the dragon key
							else 
							{
								cout << "Hmm I cannot access this room for now  " << endl;
								system("pause");
								system("cls");
							}
							break;

						case 83: case 115: 
							//S or s to head south
							//leaves main chambers
							//heads to horror chambers
							cout << mainChambers->DisplayArea(1).c_str() << endl; 
							system("pause");
							system("cls");

							//Move to Box Room
							horrorChambers->setPermission(true);
							mainChambers->setPermission(false);
							continue;

						case 69: case 101: 
							// E or e to head East
							//try to win gold
							//int to store a random number
							int random;
							cout << "Do you wish to try your luck by spending 25 Gold bars \nYou might go from rags to riches.. or riches to rags (y/n)" << endl;
							cin >> answer;
							system("pause");
							system("cls");
							//if the user says yes
							if (answer == "y" || answer == "Y") 
							{
								random_device rd;
								mt19937 gen(rd());
								uniform_int_distribution<> distr(0, 100);
								//then a random number is generated between 0 and 100
								random = distr(gen);
								cout << "You have won " + to_string(random) + " gold" << endl;
								//gold is added to the user's current gold
								slayer->setGold(slayer->getGold() + random);
								system("pause");
								system("cls");
							}
							else 
							{
								//if the user chooses no
								cout << "You are a coward!" << endl;
								system("pause");
								system("cls");
							}

							system("pause");
							system("cls");
							continue;

						case 87: case 119: 
							//w or W to head West
							cout << mainChambers->DisplayArea(3).c_str() << endl; //leaves main chambers
							//heads to secret chambers
							system("pause");
							system("cls");
							//Move to the Speaker Area
							secretChambers->setPermission(true);
							mainChambers->setPermission(false);
							continue;

						case 67: case 99: 
							//C or c to display collection 
							system("cls");
							slayer->showCollectionList(*iterDoubly);
							
							//Show the Collection List
							continue;

						default: 
							//Invalid Input
							system("cls");
							InvalidInput();
							goto searchLoop;
						}
					}

					//===============================================SECRET CHAMBERS===================================================
					if (secretChambers->getPermission() == true) 
					{ //checks if the user has permission to get into the secret chambers
						switch (keyPressed) 
						{
						case 78: case 110: 
							//n or N to head north
							//headed to the elixir shop where the slayer may buy elixir to purchase elixir
							cout << "Welcome to the Energy Elixir shop \nWould you like to purchase an Energy Elixir to boost your energy for 25 gold bars? (y)" << endl;
							cin >> answer;
							//displays info regarding the elixir shop
							cout << secretChambers->DisplayArea(3).c_str() << endl;
							//if the user decides to buy the elixir
							doublyPtr->setDoublyPtr(slayer->getFirstObject());
							if (answer == "y" || answer == "Y") 
							{
								//if user doesnt have enough gold to buy the elixir
								if (slayer->getGold() < 25) 
								{
									cout << "You do not have enough gold" << endl;
								}
								else 
								{
									//else the elixir is enabled in user's collection
									energyPotion->setStatus(false);
									paralysisNode.object.setStatus(true);
									slayer->setGold(slayer->getGold() - 25);
									//the power of paralysis is inflicted on the slayer
									cout << "with a side effect of paralysis till you go back where you came from HAHA" << endl;
								}
								system("pause");
								system("cls");
							}
							else 
							{
								//if user decides not to buy
								cout << "Weakling";
								system("pause");
								system("cls");
							}
							continue;

						case 83: case 115: 
						{
							//S or s to head south
							cout << secretChambers->DisplayArea(2).c_str() << endl; //display info regarding the object
							system("pause");
							system("cls");
							Stat(*slayer);
							cout << "Do you wish to read the legends of dragons that the scroll beholds? (y)" << endl;
							cin >> answer;
							//if user decides yes
							if (answer == "y" || answer == "Y") 
							{
								//taken from: https://www.tor.com/2020/11/24/a-brief-history-of-dragons-throughout-western-literature/
								cout << "Jörmungandr—The Midgard Serpent, or World Serpent, from Norse mythology. The arch-enemy of Thor, God of Thunder.\n" << endl;
								cout << "Typhon—Commonly called the “father of all dragons” in Greek mythology. Had a hundred dragon heads sprouting from his shoulders, which must’ve been inconvenient in social situations.\n" << endl;
								cout << "Ladon—The dragon who guarded the golden apples in the Garden of the Hesperides. Defeated by Hercules.\n" << endl;
								cout << "Tiamat—The primordial dragon-goddess of the cosmos in Babylonian legend. Her death enables the Earth’s creation.\n" << endl;
								cout << "Fáfnir—A man who became a great dragon because of his greed. Defeated by Sigurd.\n" << endl;
								cout << "The dragon from Beowulf—A terrible unnamed dragon from the Anglo-Saxon epic. The dragon-fight ends with the deaths of both Beowulf and the dragon.\n" << endl;
								cout << "The dragon from George and the dragon—An unnamed dragon that was only appeased by human sacrifices. Dramatically defeated by St. George.\n" << endl;
								cout << "Errour—A serpent-dragon from Edmund Spenser’s The Faerie Queen. Defeated by the Redcrosse Knight.\n" << endl;
								cout << "Ancalagon the Black—The greatest of all Middle-earth’s winged dragons, according to The Silmarillion. His fiery death ended the First Age.\n" << endl;
								cout << "Glaurung—The Father of dragons in Middle-earth. Wingless, poisonous, and terrifying.\n" << endl;
								cout << "Smaug the Golden—The last of Middle-Earth’s “great” dragons. Defeated by Bard the Bowman in the Third Age, as recounted in The Hobbit.\n" << endl;
								cout << "The Jabberwock—The eponymous dragon of Lewis Carroll’s “Jabberwocky” nonsense poem, and winner (or perhaps loser) of the best dragon name… and there are certainly a lot to choose from.\n" << endl;
								cout << "The dragon, from The Reluctant dragon—A scholarly dragon who especially loves poetry, and is befriended by a young boy.\n" << endl;
								cout << "Yevaud—The dragon of Pendor in the world of Earthsea. First appears in the 1964 short story “The Rule of Names.”\n" << endl;
								cout << "Orm Irian—The dragon-daughter of Kalessin the Eldest who can turn into a woman at will. First appears in Earthsea’s The Other Wind.\n" << endl;
								cout << "Ramoth—The golden dragon-queen during the Eight Interval and Ninth Pass in dragonriders of Pern. Her rider was Lessa.\n" << endl;
								cout << "Falkor—A luckdragon who plays a major role in Michael Ende’s 1979 The Neverending Story. Befriends Atreyu, a boy warrior.\n" << endl;
								cout << "Eustace Scrubb—A young boy (“There was a boy called Eustace Clarence Scrubb, and he almost deserved it”) from The Voyage of the Dawn Treader. Temporarily turned into a dragon through his own unchecked greed.\n" << endl;
								cout << "Temeraire—A rare Chinese Celestial dragon born during the Napoleonic wars. Bonds with Captain William Laurence in Naomi Novak’s Temeraire series. \n" << endl;
								cout << "Drogon—One of Daenerys Targaryen’s three dragons in George R.R. Martin’s A Song of Ice and Fire. Huge and black, with a wingspan of twenty feet as of A Dance with dragons. \n" << endl;
								cout << "Saphira—Eragon’s dragon from Christopher Paolini’s Inheritance Cycle. One of the last female dragons in Alagaësia. \n" << endl;
								cout << "Toothless—Hiccup Horrendous Haddock III’s dragon in Cressida Cowell’s How to Train Your dragon. Commonly mistaken for a Common or Garden dragon. \n" << endl;
								cout << "Villentretenmerth—One of only two Golden dragons in the history of the world of The Witcher; able to assume many forms through polymorphism. In Common Speech, his name means Three Black Birds.\n" << endl;
							}
							//if user decides no
							else 
							{
								cout << "Illiterate buffoon" << endl;
							}
							system("pause");
							system("cls");
						}
							   continue;
						case 69: case 101: 
							//e or E to head east
							cout << secretChambers->DisplayArea(0).c_str() << endl; 
							//displays object description
							system("pause");
							paralysisNode.object.setStatus(false);
							cout << "You are now free of the paralysis curse... until next time" << endl;
							system("cls");
							//heads back to the main chambers
							//the paralysis curse ends
							secretChambers->setPermission(false);
							mainChambers->setPermission(true);
							continue;

						case 87: case 119: 
							//w or W to head West
							system("cls");
							Stat(*slayer);
							//display info about the object
							doublyPtr->setDoublyPtr(slayer->getFirstObject());
							cout << secretChambers->DisplayArea(1).c_str() << endl;
							//access stack keys
							if (keyBox.isEmpty() == false)
							{
								//if the air key is the next key stacked in key box
								//then that key is added to the collection
								//the status of key is turned true which means it has already been taken
								if (keyBox.peek() == *airKey)
								{
									slayer->addObject(*airKey);
									keyBox.pop();
									objectPtr->setStatus(true);
									cout << "I got an air key!" << endl;
								}

								//if thefire key is the next key stacked in key box
								//then that key is added to the collection
								//the status of key is turned true which means it has already been taken
								else if (keyBox.peek() == *fireKey)
								{
									slayer->addObject(*fireKey);
									keyBox.pop();
									objectPtr->setStatus(true);
									cout << "I got a fire key!" << endl;
								}

								//if the earth key is the next key stacked in key box
								//then that key is added to the collection
								//the status of key is turned true which means it has already been taken
								else if (keyBox.peek() == *earthKey)
								{
									slayer->addObject(*earthKey);
									keyBox.pop();
									objectPtr->setStatus(true);
									cout << "I got an earth key!" << endl;
								}

								//if the water key is the next key stacked in key box
								//then that key is added to the collection
								//the status of key is turned true which means it has already been taken
								else if (keyBox.peek() == *waterKey)
								{
									slayer->addObject(*waterKey);
									keyBox.pop();
									objectPtr->setStatus(true);
									cout << "I got a water key!" << endl;
								}
							}
							else if (dragonKey->getStatus() == false){
								//asked if the user wants to combine all four keys to form the dragon key
								cout << "Would you like to combine the power of all the mighty four keys to fight the dragon (y)" << endl;
								cin >> answer;
								//if yes
								if (answer == "y" || answer == "Y") 
								{
									slayer->addObject(*dragonKey);
									objectPtr->setStatus(true);
									cout << "You got a dragon key!" << endl;
								}
								//not yes
								else 
								{
									cout << "You imbecile" << endl;
								}
							}
							else if(dragonKey->getStatus() == true) {
								cout << "You have obtained all keys" << endl;
							}

							system("pause");
							system("cls");
							continue;

						case 67: case 99: 
							//C or c to display collection
							system("cls");
							slayer->showCollectionList(*iterDoubly);
							break;

						default: 
							//Invalid input
							system("cls");
							InvalidInput();
							goto searchLoop;
						}
					}

					//******************************* HORROR CHAMBERS *****************************
					if (horrorChambers->getPermission() == true) 
					{ //checks if user has access to the horror chambers
						switch (keyPressed) 
						{
						case 78: case 110: //n or N to head north
							//enters the health herb shop
							//can buy health herb to boost energy for 25 gold
							cout << "Welcome to the Health Herb shop \nWould you like to purchase a Health Herb to boost your energy for 25 gold bars? (y)" << endl;
							cin >> answer;
							doublyPtr->setDoublyPtr(slayer->getFirstObject());
							//displays info regarding the chambers
							cout << horrorChambers->DisplayArea(0).c_str() << endl;
							//if yes
							if (answer == "y" || answer == "Y") 
							{
								//if not enough gold
								if (slayer->getGold() < 25) 
								{
									cout << "You do not have enough gold" << endl;
								}
								else 
								{
									//if enough gold
									healingPotion->setStatus(false);
									deafnessNode.object.setStatus(true);
									cout << "with a side effect of deafness till you go back where you came from HAHA" << endl;
								}
								system("pause");
								system("cls");
							}

							//if user doesnt wanna buy
							else 
							{
								cout << "Weakling";
								system("pause");
								system("cls");
							}
							continue;

						case 83: case 115: 
							//s or S to head south
							//displays info regarding secret chambers
							//heads to secret chambers
							//the deafness curse is now lifted off
							cout << secretChambers->DisplayArea(1).c_str() << endl;
							system("pause");
							deafnessNode.object.setStatus(false);
							cout << "You are now free of the deafness curse... until next time" << endl;
							system("cls");

							//Move to the lobby
							secretChambers->setPermission(false);
							mainChambers->setPermission(true);
							continue;

						case 69: case 101: 
							//e or E to head east
							//displays info regarding chambers object
							cout << horrorChambers->DisplayArea(3).c_str() << endl; //Show door detail
							system("pause");
							system("cls");

							//option to change name
							cout << "Do you wish to change your slayer's name for 100 gold bars? (y)" << endl;
							cin >> answer;
							//if yes
							if (answer == "y" || answer == "Y") 
							{
								//if not enough gold
								if (slayer->getGold() < 100) 
								{
									cout << "You do not have enough gold" << endl;
								}
								else 
								{
									//if enough gold
									cout << "Enter your slayer's new name: " << endl;
									cin >> warriorName;
								}
								system("pause");
								system("cls");
							}
							continue;

						case 87: case 119: 
							//w or W to head west
							//display info regarding horror chambers
							cout << horrorChambers->DisplayArea(2).c_str() << endl;
							system("pause");
							system("cls");
							continue;

						case 67: case 99: 
							//c or C to display collection
							system("cls");
							slayer->showCollectionList(*iterDoubly);
							break;

						default: 
							//Invalid input
							system("cls");
							InvalidInput();
							goto searchLoop;
						}
					}
					

					//***************************************DRAGONS LAIR***********************************
					if (dragonsLair->getPermission() == true) 
					{ //checks if user has permission to enter dragons lair
						//Cut Scene
						system("cls");
						Stat(*slayer);
						cout << "You stand in the den of the dragon\nYou have come to fight for your tribe and protect them\nA gigantic dragon with hot blazing fire stands tall infront of you\nPace yourself for the doom that awaits" << endl;
						cout << "\n" << endl;
						system("pause");

						//starting the loop
						bool stillFighting = true;

						//the fight results
						string result = "";

						//hide result when the user is revived
						bool skipText = false;

						//as long as the fight is going on
						while (stillFighting) 
						{
							system("cls");
							cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
							cout << "			WARZONE " << endl;
							cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
							cout << "Boosts: " << BoostTree->checkBoost().getName() << endl; 
							//Print out the Boost
							cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
							Stat(*slayer);

							//when someone attacks
							if (result != "" && skipText == false) 
							{
								cout << result << endl;
								cout << "***************************" << endl;
							}

							//if slayer is revived then the text is displayed after first attack
							skipText = false;
							DragonUI(*dragon);
							 
							//the war begins
							//facade design principle implemented here
							//war takes place inside the war class
							result = dragonsLair->launchFight(*battleWar);

							//checking if slayer is alive or not
							if (slayer->getHP() <= 0 || slayer->getEnergy() <= 0) 
							{
								//if the slayer died
								system("cls");
								Stat(*slayer);
								cout << "The dragon slayer has fallen" << endl;
								system("pause");
								system("cls");

								//the user will be revived
								if (slayer->getRestart() == false) 
								{
									Stat(*slayer);
									cout << "You must return stronger than you left\n  " << endl;
									system("pause");
									bool choosingBoost = true; 
									//option to choose boosts
									system("cls");
									while (choosingBoost == true) 
									{
										Stat(*slayer);
										BoostTree->displayBoost();
										//displays the boost lvl 1 options
										cout << "Choose your first Boost/n==============================" << endl;
										cout << "1. Stealth Warrior/n2. Mighty Warrior" << endl;
										keyPressed = _getch();
										bool revivalOptions = true;

										//For the revived Boost loop
										switch (keyPressed) 
										{
										case 49: //Chosen sealth warrior
											warrior->setStatus(false);
											stealthWarrior->setStatus(false);
											earthWarrior->setStatus(true);
											waterWarrior->setStatus(true);
											system("cls");
											while (revivalOptions) 
											{
												//Choose the boost lvl 2 options
												Stat(*slayer);
												BoostTree->displayBoost(); //displays lvl 2 boosts
												cout << "Choose your super powers/n*****************************" << endl;
												cout << "1. Air Warrior/n 2. Earth Warrior" << endl;
												keyPressed = _getch();
												if (keyPressed == 49) 
												{
													//air warrior chosen
													revivalOptions = false;
													choosingBoost = false;
													earthWarrior->setStatus(false);
													battleWar->setVisitor(*airBattleBoosts);
													//slayer is revived
													Revival(slayer, BoostTree);
												}
												else if (keyPressed == 50) 
												{//earth warrior chosen
													revivalOptions = false;
													choosingBoost = false;
													earthWarrior->setStatus(false);
													//earth warrior triggered in the war class
													battleWar->setVisitor(*earthBattleBoosts);
													//slayer is revived
													Revival(slayer, BoostTree);
												}
												else 
												{ //Invalid input
													system("cls");
													InvalidInput();
												}
											}
											break;
										case 50: // chosen mighty warrior
											warrior->setStatus(false);
											mightyWarrior->setStatus(false);
											airWarrior->setStatus(true);
											fireWarrior->setStatus(true);
											system("cls");
											while (revivalOptions) 
											{
												Stat(*slayer);
												BoostTree->displayBoost(); //displays lvl 1Boosts list
												cout << "Choose your super power/n*****************************" << endl;
												cout << "1. Fire Warrior/n 2. Water Warrior" << endl;
												keyPressed = _getch();
												if (keyPressed == 49) 
												{
													//chosen fire warrior
													revivalOptions = false;
													choosingBoost = false;
													fireWarrior->setStatus(false);
													//fire warrior boost triggered in war class
													battleWar->setVisitor(*fireBattleBoosts);
													//slayer is revived
													Revival(slayer, BoostTree);
												}
												else if (keyPressed == 50) 
												{
													//water warrior chosen
													revivalOptions = false;
													choosingBoost = false;
													airWarrior->setStatus(false);
													//water warrior boost triggered in war class
													battleWar->setVisitor(*waterBattleBoosts);
													//slayer is revived
													Revival(slayer, BoostTree);
												}
												else 
												{ //Invalid input
													system("cls");
													InvalidInput();
												}
											}
											break;
										default:
											system("cls");
											InvalidInput();
										}
									}
									//revival
									slayer->setRestart(true);
									skipText = true;
									system("cls");
									cout << "Boost: " << BoostTree->checkBoost().getName() << "*****************************" << endl; //Print out the awakened Boost
									Stat(*slayer);
									cout << "I am stronger than ever ready to fight you with all my might and will" << endl;
									cout << "\n" << endl;
									system("pause");
									system("cls");
								}
								else 
{ 
								//the slayer is revived and now cannot be revived again
									stillFighting = false;
								}
							}
							else if (dragon->getHP() <= 0) 
							{ 
							//if the dragon falls, then game is reset and slayer moves to main chambers
								system("cls");
								DragonUI(*dragon);
								cout << "The weak dragon with broken wings and bloody body falls to the ground " << endl;
								cout << "\n" << endl;
								system("pause");
								system("cls");
								Stat(*slayer);
								cout << "== Back to the Main Chambers == \n  " << endl;
								system("pause");
								system("cls");
								stillFighting = false;

								//Reset the game
								paralysisNode.object.setStatus(false);
								deafnessNode.object.setStatus(false);

								mainChambers->setPermission(true);
								secretChambers->setPermission(false);
								horrorChambers->setPermission(false);
								dragonsLair->setPermission(false);

								warrior->setStatus(true);
								mightyWarrior->setStatus(true);
								stealthWarrior->setStatus(true);
								airWarrior->setStatus(false);
								fireWarrior->setStatus(false);
								waterWarrior->setStatus(false);
								earthWarrior->setStatus(false);

								if (slayer->getHP() < 100)
								{
									slayer->setHP((slayer->getHP()) + 100);
								}

								if (slayer->getEnergy() < 50) 
								{
									slayer->setEnergy((slayer->getEnergy()) + 50);
								}

								slayer->setLevel((slayer->getLevel()) + 1);
								slayer->setGold((slayer->getGold()) + 50);

								//Back to opening
								goto openingScreen;
							}
						}
						//Move back to lobby if the fight end
						mainChambers->setPermission(true);
						dragonsLair->setPermission(false);
					}
				}

				if (slayer->getHP() <= 0) 
				{ 
					//if the slayer died due to weak hp
					system("cls");
					Stat(*slayer);
					cout << "You were overpowered and lost the war. The curse is stronger than ever!" << endl;
					cout << "\n" << endl;
					system("pause");
					system("cls");

					//Reset the game to go to main chambers
					paralysisNode.object.setStatus(false);
					deafnessNode.object.setStatus(false);

					mainChambers->setPermission(true);
					secretChambers->setPermission(false);
					horrorChambers->setPermission(false);
					dragonsLair->setPermission(false);

					warrior->setStatus(true);
					mightyWarrior->setStatus(true);
					stealthWarrior->setStatus(true);
					airWarrior->setStatus(false);
					fireWarrior->setStatus(false);
					waterWarrior->setStatus(false);
					earthWarrior->setStatus(false);

					slayer->setEnergy(100);
					slayer->setHP(200);

					//Back to the opening scene checkpoint
					goto openingScreen;

				}
				else if (slayer->getEnergy() <= 0) 
				{ //If the slayer died due to weak energy
					system("cls");
					Stat(*slayer);
					cout << "You were overpowered and lost the war. The curse is stronger than ever!" << endl;
					cout << "\n" << endl;
					system("pause");
					system("cls");

					//Reset the game to go back to main chambers
					paralysisNode.object.setStatus(false);
					deafnessNode.object.setStatus(false);

					mainChambers->setPermission(true);
					secretChambers->setPermission(false);
					horrorChambers->setPermission(false);
					dragonsLair->setPermission(false);

					warrior->setStatus(true);
					mightyWarrior->setStatus(true);
					stealthWarrior->setStatus(true);
					airWarrior->setStatus(false);
					fireWarrior->setStatus(false);
					waterWarrior->setStatus(false);
					earthWarrior->setStatus(false);

					slayer->setEnergy(100);
					slayer->setHP(200);

					//Back to opening screen
					goto openingScreen;

				}
				else 
				{ 
					//The user choose other than O or o
					system("cls");
					InvalidInput();
				}
			}
		case 48: 
			//if the user chooses to exit
			system("cls");
			cout << "Game Exit" << endl;
			gameStatus = false;
			break;
		default: 
			//Invalid input
			system("cls");
			InvalidInput();
		}
	}

	BoostTree->left().detachLeft();
	BoostTree->left().detachRight();
	BoostTree->right().detachLeft();
	BoostTree->right().detachRight();
	BoostTree->detachLeft();
	BoostTree->detachRight();
	return 0;
}