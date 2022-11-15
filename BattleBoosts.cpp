#include "BattleBoosts.h"

// BattleBoosts Interface
string BattleBoosts::Visit(Slayer& aSlayer) 
{ 
	return " "; 
}

// Overloaded Constructor
BattleBoostsMighty::BattleBoostsMighty(int aStrength) 
{
	fStrength = aStrength;
}

// boost mighty visitor which increases the hp of slayer
string BattleBoostsMighty::Visit(Slayer& aSlayer)
{
	aSlayer.setHP(aSlayer.getHP() + fStrength);
	return "Increasing slayer's HP by" + to_string(fStrength) + "HP";
}

// stealth visitor which decreases the hp of the dragon
string BattleBoostsStealth::Visit(Dragon& aDragon) 
{
	aDragon.setHP(aDragon.getHP() - 200);
	return "Dragon's HP descreased by a 100 units HP";
}