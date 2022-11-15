#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class Info>

class Itr 
{
public:
	// Default Constructor
	Itr() 
	{

	}

	//Destructor
	virtual ~Itr() 
	{ 

	}

	// * operator overload
	virtual Info operator*() = 0;
	
	// Prefix ++ operator overload
	virtual Itr<Info>& operator++() = 0;

	// Postfix ++ operator overload
	virtual Itr<Info>& operator++(int) = 0;

	// Prefix -- operator overload
	virtual Itr<Info>& operator--() = 0;

	// Postfix -- operator overload
	virtual Itr<Info>& operator--(int) = 0;

	// == operator overload
	virtual bool operator== (Itr<Info>& aOther) = 0;

	//!= Operator overload
	bool operator!= (Itr<Info>& aOther) 
	{
		return !(*this == aOther);
	}
	
	// find the first object in array
	virtual Itr<Info>& begin() = 0;

	// find the last object in array
	virtual Itr<Info>& end() const = 0;
};