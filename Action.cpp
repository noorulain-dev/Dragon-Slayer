#include "Action.h"

/// Default Constructor
Action::Action() 
{

}

/// Destructor
Action::~Action() 
{ 

}

/// Overloaded Constructor
Action::Action(User& aUser, int aSize) 
{ 
	fQueueInTree = new QueueInTree<User>(aUser, aSize);
}

// returns the next user in the fight
User& Action::nextUser() 
{
	User& lChar = fQueueInTree->dequeue();
	fQueueInTree->enqueue(lChar);
	return lChar;
}

// add new character in the fight
void Action::insertUser(User& aUser) 
{
	fQueueInTree->enqueue(aUser);
}