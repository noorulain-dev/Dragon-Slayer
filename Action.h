#pragma once

#include <iostream>

#include "QueueInTree.h"
#include "User.h"
#include "Slayer.h"
#include "Dragon.h"

using namespace std;

class Action {
private:

	//Action is a queue
	QueueInTree<User>* fQueueInTree; 

public:
	//Default Constructor
	Action(); 

	//Destructor
	~Action(); 

	//Overloaded Constructor
	Action(User& aUser, int aSize);

	//returns next user
	User& nextUser(); 

	//inserts user in war
	void insertUser(User& aUser); 
};