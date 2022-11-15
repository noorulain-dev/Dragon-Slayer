#pragma once
#include <iostream>
#include "SinglyNode.h"
#include "Itr.h"

using namespace std;

//template class info
template<class Info>

class SinglyList : public Itr<Info> 
{
private:
	//first node in the singly list
	SinglyNode<Info> fFirstNode; 
	// pointer pointing to the node in the singly list
	SinglyNode<Info>* fPtr;

public:
	// Default Constructor
	SinglyList() 
	{

	}

	//Destructor
	virtual ~SinglyList() 
	{ 

	}

	// Overloaded constructor
	SinglyList(SinglyNode<Info>& aObject) 
	{
		//sets the first node
		fFirstNode = aObject;
		//pointer pointing to first node
		fPtr = &fFirstNode;
		SinglyNode<Info>* lDefaulPointerOfObject = &aObject;
		//save the first node
		SinglyNode<Info>* passingPointer = &aObject; 
		//copy the next node if there is any
		if (passingPointer->next != nullptr) 
		{ 
			while (passingPointer->next != nullptr) 
			{
				fPtr->next = passingPointer->next; 
				passingPointer = passingPointer->next;
				fPtr = fPtr->next; 
			}
			//reset the tracking pointer 
			fPtr = &fFirstNode; 
			passingPointer = lDefaulPointerOfObject; 
		}
		else 
		{
			//if next node is the last node then the next node must be null
			fFirstNode.next = nullptr;
		}
	}

	// Getter for pointer
	SinglyNode<Info>& getIterPointer() 
	{
		return *fPtr;
	}

	// Setter for pointer
	void setIterPointer(SinglyNode<Info>& aNode) 
	{
		fPtr = &aNode;
	}

	// -- operator
	Itr<Info>& operator--() override 
	{
		return *this;
	}

	// -- (int) operator
	Itr<Info>& operator--(int) override 
	{
		return *this;
	}

	
	// overriding from the abstract class function
	Itr<Info>& begin() override 
	{ 
		return *this; 
	}

	// Dereference operator
	Info operator*() override 
	{
		return fPtr->object;
	}

	// moves to the next node
	Itr<Info>& operator++() override 
	{
		fPtr = fPtr->next;
		return *this;
	}

	// returns node and moves to next node
	Itr<Info>& operator++(int) override 
	{
		SinglyList* temp = new SinglyList(*this);
		++(*this);
		return *temp;
	}

	// equivalence operator
	bool operator== (Itr<Info>& aOther) override 
	{
		SinglyList* castedItr = dynamic_cast<SinglyList*>(&aOther);
		return (fPtr == castedItr->fPtr);
	}

	// returns the pointer pointing to the last node
	Itr<Info>& end() const override 
	{
		SinglyList* temp = new SinglyList(*this);
		while (temp->fPtr->next != nullptr) 
		{
			temp->fPtr = temp->fPtr->next;
		}
		return *temp;
	}
};