#include "skillsMap.h"

// nil node
skillsMap skillsMap::NIL;

// Default Constructor
skillsMap::skillsMap() 
{
	fContent = nullptr;
	fLeft = &NIL;
	fRight = &NIL;
}

// Destructor
skillsMap::~skillsMap() 
{

}

// Overloaded Constructor
skillsMap::skillsMap(Boost& aBoost) 
{
	fContent = &aBoost;
	fLeft = &NIL;
	fRight = &NIL;
}

//checks whether tree is empty
bool skillsMap::isEmpty() 
{
	return this == &NIL;
}

//getter for tree content
Boost& skillsMap::getContent() 
{
	if (isEmpty()) 
	{
		throw domain_error("Empty Node");
	}
	return *fContent;
}

//getter for left node
skillsMap& skillsMap::left() 
{
	if (isEmpty()) 
	{
		throw domain_error("Empty Left Node");
	}
	return *fLeft;
}

//getter for right node
skillsMap& skillsMap::right() 
{
	if (isEmpty()) 
	{
		throw domain_error("Empty Right Node");
	}
	return *fRight;
}

//attach node to left
void skillsMap::attachLeft(Boost& aBoost) 
{
	if (isEmpty()) 
	{ 
		throw domain_error("Empty skillsMap");
	}
	if (fLeft != &NIL) 
	{
		throw domain_error("Filled Node");
	}
	fLeft = new skillsMap(aBoost);
}

//attach node to right
void skillsMap::attachRight(Boost& aBoost) 
{
	if (isEmpty()) 
	{
		throw domain_error("Empty skillsMap");
	}
	if (fRight != &NIL) 
	{
		throw domain_error("Filled Node");
	}
	fRight = new skillsMap(aBoost);
}

// remove left node
skillsMap& skillsMap::detachLeft() 
{
	if (isEmpty()) 
	{ 
		throw domain_error("Empty skillsMap");
	}
	skillsMap& Result = *fLeft;
	fLeft = &NIL;
	return Result;
}

//remove right node
skillsMap& skillsMap::detachRight() 
{ 
	if (isEmpty()) 
	{
		throw domain_error("Empty skillsMap");
	}
	skillsMap& Result = *fRight; 
	fRight = &NIL; 
	return Result;
}

//call to accept visitor
string skillsMap::acceptVisitor(BattleBoosts& aBattleBoosts, Slayer& aSlayer) 
{
	return aBattleBoosts.Visit(aSlayer);
}

//display boost details
void skillsMap::displayBoost() 
{
	QueueInTree<skillsMap> lQueue(*this, 7); //The data will be stored in a queue
	while (!lQueue.isEmpty()) 
	{
		skillsMap& head = lQueue.dequeue(); //Take the first element of the queue
		if (!head.isEmpty()) 
		{
			if (head.getContent().getStatus() == true) 
			{
				cout << "Boost Level: " << head.getContent().getLevel() << endl;
				cout << "Boost Name: " << head.getContent().getName() << endl;
				cout << "Ability: \n" << head.getContent().getDesc() << endl;
				cout << "===============================" << endl;
			}
		}
		if (!head.left().isEmpty()) 
		{ 
			lQueue.enqueue(head.left()); 
		}
		if (!head.right().isEmpty()) 
		{ 
			lQueue.enqueue(head.right()); 
		}
	}
}

//check if boost is working
Boost& skillsMap::checkBoost() 
{
	Keys<skillsMap> lKeys(7); //The data will be stored in a stack
	if (!isEmpty()) 
	{
		lKeys.push(*this); //Put in the value to the stack
	}
	while (!lKeys.isEmpty()) 
	{
		skillsMap head = lKeys.peek(); //returns the first element
		if (!head.isEmpty()) 
		{
			if (head.getContent().getStatus() == true) 
			{
				return head.getContent();
			}
			lKeys.pop(); //remove object from stack
		}
		if (!head.right().isEmpty()) 
		{ //Push back the left node
			lKeys.push(head.right()); // O(1)
		}
		if (!head.left().isEmpty()) 
		{ //Push back the right node
			lKeys.push(head.left()); // O(1)
		}
	}
}
