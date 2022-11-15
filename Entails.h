#pragma once
#include <iostream>

using namespace std;

template <class Temp>

class Entails 
{
private:
	//objects stored in the array
	Temp* fObjects;
	//array size 1
	Temp fArr[1]; 
	//maximum size of array
	int fMax;
	//current size of array
	int fCurrent; 
	//index of array
	int fIndex;

public:
	//Default Constructor
	Entails() 
	{

	};

	//Destructor
	~Entails() 
	{

	}; 

	// Overloaded Constructor
	Entails(Temp& aObjects, int aSize) 
	{
		fObjects = new Temp[aSize];
		fMax = aSize;
		fObjects[0] = aObjects;
		fIndex = 0;
		fCurrent = 1;
	};

	//function to check if the list is empty
	bool isEmpty() 
	{
		return fCurrent == 0;
	};

	//returns size of the list
	int getSize() 
	{
		return fCurrent;
	}

	// adds object to the list
	void append(Temp& aObject) 
	{
		if (fCurrent >= fMax) 
		{
			Temp* newObjects = new Temp[2 * fMax];
			for (int i = 0; i < fMax; i++) 
			{ 
				newObjects[i] = fObjects[i];
			}
			fMax = fMax * 2;
			delete[] fObjects;
			fObjects = newObjects;
		}
		// increase the index array
		fIndex++;
		// save object in the empty index
		fObjects[fIndex] = aObject;
		//move to the next position from current position in array
		fCurrent++;
	};
	
	//remove object from array
	void removeAtIndex(int aIndex) 
	{
		while (aIndex + 1 < fCurrent) 
		{
			fObjects[aIndex] = fObjects[aIndex + 1];
			aIndex++;
		}
		// decrease the array which has the same impact as removing the object from the array
		fIndex--;
		fCurrent--;
	};
	
	//gets the first element in array
	Temp& getFirstElement() 
	{
		fArr[0] = fObjects[0];
		return fArr[0];
	}
};