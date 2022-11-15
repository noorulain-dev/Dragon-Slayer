#pragma once
#include <iostream>

using namespace std;

//template class info
template<class Info>

class Keys 
{
private:
	//array of keys
	Info* fArr;
	//index of last item in the stack of keys
	int fIndex;
	//size of array
	int fSize;

public:
	// Default Constructor
	Keys() 
	{

	};

	// Constructor
	Keys(int aSize) 
	{
		if (aSize <= 0) {
			throw invalid_argument("Illegal Keys Size");
		}
		else 
		{
			fArr = new Info[aSize];
			fSize = aSize;
			fIndex = 0;
		}
	}

	//Destructor
	~Keys() 
	{
		delete[] fArr;
	}

	// checks whether the array is empty
	bool isEmpty() const 
	{
		return fIndex == 0;
	}

	// returns size of array
	int checkSize() const 
	{
		return fIndex;
	}

	// adds object at the end of the array
	void push(const Info& aObject) 
	{
		if (fIndex <= fSize) 
		{
			fArr[fIndex] = aObject;
			fIndex += 1;
		}
		else 
		{
			throw overflow_error("Keys: No Space Left");
		}
	}
	 
	//removes object which is at the end of the array
	void pop() 
	{
		if (isEmpty()) 
		{
			throw underflow_error("Keys: Empty");
		}
		else 
		{
			fIndex -= 1;
		}
	}

	//checks out last object in the array
	Info& peek() 
	{ 
		if (isEmpty()) 
		{
			throw underflow_error("Keys: Empty");
		}
		else 
		{
			return fArr[fIndex - 1]; // O(1)
		}
	}
};