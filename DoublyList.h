#pragma once
#include <iostream>
#include "Itr.h"
#include "DoublyNode.h"

using namespace std;

template<class Info>

class DoublyList : public Itr<Info> 
{
private:
	//first node of doubly linked list
	DoublyNode<Info> fFirstNode;
	//pointer pointing to the nodes
	DoublyNode<Info>* fPtr;

public:
	// Default Constructor
	DoublyList() 
	{ 

	}

	//Destructor
	virtual ~DoublyList() 
	{ 

	}

	// Overloaded constructor
	DoublyList(DoublyNode<Info>& aObject)
	{
		//sets the first node in iterator
		fFirstNode = aObject;

		//the first node in doubly list is null
		fFirstNode.setPrevious(nullptr); 

		//the pointer points to the first node in the list
		fPtr = &fFirstNode; 

		DoublyNode<Info>* trackingPointer = &(aObject);

		//tracking pointer
		if (trackingPointer->getNext() != nullptr) 
		{
			DoublyNode<Info> previousNode = fFirstNode;
			while (trackingPointer->getNext() != &previousNode.NIL) 
			{
				//while the last node isnt reached
				fPtr->setNext(trackingPointer->getNext());

				//pointer will point to next node
				trackingPointer = trackingPointer->getNext();
				fPtr = fPtr->getNext();

				//make pointer point to the back node where the pointer was moved
				*fPtr->getPrevious() = previousNode;

				//the current node pointing to the previous node
				previousNode = *fPtr;
			}
			//pointer reset to point to the first node
			fPtr = &fFirstNode;
		}
		else 
		{
			//if next is null then there are no more nodes left
			fFirstNode.setNext(nullptr);
		}
	}
	
	//dereference operator
	Info operator*() override 
	{
		return fPtr->getValue();
	}
	
	//pointer setter
	void setDoublyPtr(DoublyNode<Info>& aNode) 
	{
		fPtr = &aNode;
	}
	
	//goes back to the node next to it and then returns it
	Itr<Info>& operator++() override 
	{
		fPtr = fPtr->getNext();
		return *this;
	}
	
	//it returns the nodeand then goes back to the node next to it
	Itr<Info>& operator++(int) override 
	{
		DoublyList* temp = new DoublyList(*this);
		++(*this);
		return *temp;
	}
	
	//goes back to the node before it and then returns it
	Itr<Info>& operator--() override 
	{
		fPtr = fPtr->getPrevious();
		return *this;
	}
	
	//it returns the node and then goes back to the node before it
	Itr<Info>& operator--(int) override 
	{
		DoublyList* temp = new DoublyList(*this);
		--(*this);
		return *temp;
	}
	
	//checks whether the passed value is same
	bool operator== (Itr<Info>& aOther) override 
	{
		DoublyList* itr = dynamic_cast<DoublyList*>(&aOther);
		//checks if the both iterators have same pointers
		return (fPtr == itr->fPtr);
	}

	//returns the iterator which has a pointer which points to the first node in the list
	Itr<Info>& begin() override 
	{
		DoublyList* temp = new DoublyList(*this);
		//keeps going until the first nil node is reached
		while (temp->fPtr->getPrevious() != &(temp->fFirstNode.NIL)) {
			temp->fPtr = temp->fPtr->getPrevious();
		}
		return *temp;
	}
	
	//returns the iterator which has a pointer which points to the last node in the list
	Itr<Info>& end() const override 
	{
		DoublyList* temp = new DoublyList(*this);
		//keeps going until the last nil node is reached
		while (temp->fPtr->getNext() != &(temp->fFirstNode.NIL)) {
			temp->fPtr = temp->fPtr->getNext();
		}
		return *temp;
	}
};
