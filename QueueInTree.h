#pragma once
#include <iostream>
#include <stdexcept>
#include "Entails.h"

using namespace std;

//template class temp
template <class Temp>

class QueueInTree 
{
private:
	// index in the list
	Entails<Temp> fIndex;
public:
	// Default Constructor
	QueueInTree() 
	{

	};

	//Destructor
	~QueueInTree() 
	{

	};

	// Overloaded constructor
	QueueInTree(Temp& aObject, int aSize) 
	{
		fIndex = Entails<Temp>(aObject, aSize);
	};

	// returns whether the queue is empty
	bool isEmpty() 
	{
		return fIndex.isEmpty(); 
	};

	// returns the size of the queue
	int size() 
	{
		return fIndex.getSize();
	};

	// adds an object in queue
	void enqueue(Temp aObject) 
	{
		fIndex.append(aObject);
	};

	// remove an object from the queue
	Temp& dequeue() 
	{
		if (!isEmpty()) 
		{
			Temp& target = fIndex.getFirstElement(); //O(1)
			fIndex.removeAtIndex(0); //O(n)
			return target; //O(1)
		}
		else 
		{
			throw underflow_error("QueueInTree is empty");
		}
	};
};