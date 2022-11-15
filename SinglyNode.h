#pragma once
#include <iostream>

using namespace std;

template <class Temp>

class SinglyNode 
{
public:
	//value of the node
	Temp object;

	//pointer pointer to the next node in the list
	SinglyNode* next;

	// Default Constructor
	SinglyNode() 
	{

	}

	//Destructor
	~SinglyNode() 
	{

	};

	// Overloaded constructor for the top node
	SinglyNode(Temp n) 
	{
		object = n;
		next = nullptr;
	}

	// prepend overloaded constructor
	SinglyNode(Temp n, SinglyNode* p) 
	{
		object = n;
		next = p;
	}

	// append
	void insertNode(Temp value, SinglyNode<Temp>* before) 
	{
		SinglyNode<Temp>* newNode = new SinglyNode<Temp>(value);
		newNode->next = before->next;
		before->next = newNode;
	}

	// adding a node in the beginning of the list
	void insertAtBottom(Temp value, SinglyNode<Temp>*& firstNode) 
	{
		SinglyNode<Temp>* newNode = new SinglyNode<Temp>(value, firstNode);
		firstNode = newNode;
	}

	// adding a node at the end of the list
	void insertAtTop(Temp value, SinglyNode<Temp>* firstNode) 
	{
		SinglyNode<Temp>** newNodePtr = &firstNode;
		while (*newNodePtr != nullptr) 
		{
			newNodePtr = &((*newNodePtr)->next);
		}
		*newNodePtr = new SinglyNode<Temp>(value);
	}
};