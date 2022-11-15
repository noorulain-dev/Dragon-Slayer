#pragma once
#include <iostream>

using namespace std;

//template Info class
template<class Info>

class DoublyNode 
{
public:
	//defining typedef
	typedef DoublyNode<Info> Node;

private:
	//value stored in node
	Info fValue;

	//pointer pointing to next node
	Node* fNext; 

	//pointer pointing to previous node
	Node* fPrevious;

public:
	//nil node
	static Node NIL;

	//default constructor
	DoublyNode() 
	{
		fValue = Info();
		fNext = &NIL;
		fPrevious = &NIL;
	}

	// Overloaded constructor
	DoublyNode(const Info& aValue) 
	{
		fValue = aValue;
		fNext = &NIL;
		fPrevious = &NIL;
	}

	// adding a node before the node which is called
	void prepend(Node& aNode) 
	{
		aNode.fNext = this;
		if (fPrevious != &NIL) 
		{
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}
		fPrevious = &aNode;
	}

	//adding a node after the node which is called
	void append(Node& aNode) 
	{
		aNode.fPrevious = this;
		if (fNext != &NIL) {
			aNode.fNext = fNext; 
			fNext->fPrevious = &aNode;
		}
		fNext = &aNode;
	}

	// removing the node which is called
	void remove() 
	{
		if (fNext == &NIL) 
		{
			fPrevious->fNext = &NIL;
		}
		else if (fPrevious == &NIL) 
		{
			fNext->fPrevious = &NIL;
		}
		else 
		{
			fPrevious->fNext = fNext;
			fNext->fPrevious = fPrevious;
		}
	}

	// getter for the value in node
	Info& getValue() 
	{
		return fValue;
	}

	// getter for the value in next node
	Node* getNext() const 
	{
		return fNext;
	}

	// setter for next node
	void setNext(Node* aNode) 
	{
		fNext = aNode;
	}

	//getter for previous value node
	Node* getPrevious() const 
	{
		return fPrevious;
	}

	//setter for previous nodes value
	void setPrevious(Node* aNode) 
	{
		fPrevious = aNode;
	}

	// getter for first node
	Node& getFirstNode() 
	{ 
		Node* ptr = this;
		while (ptr->getPrevious() != &NIL) 
		{
			ptr = (*ptr).fPrevious;
		}
		return *ptr;
	}

	// setter for the first node
	void setFirstNode(Node& aNode) 
	{ 
		Node* ptr = this;
		while (ptr->getPrevious() != &NIL) 
		{
			ptr = (*ptr).fPrevious;
		}
		*ptr = aNode;
	}

	// getter for last node
	Node& getLastNode() 
	{
		Node* ptr = this;
		while (ptr->getNext() != &NIL) 
		{
			ptr = (*ptr).fNext;
		}
		return *ptr;
	}

	// equivalence operator
	bool operator== (Info& aOther) 
	{
		return (fValue == aOther);
	}
};
//nil node
template<class Info>
DoublyNode<Info> DoublyNode<Info>::NIL;