#pragma once

// ---New---
// We define classes using
class Customer
{
	// Private variables/methods/operators cannot be accessed from outside
	// this class
private:
	int number;

	// Public variables/methods/operators can be accessed from anywhere
public:
	// I've provided a constructor so that we can see what the code is doing when
	// we create a new Customer object
	Customer()
	{
		number = 5;
	}

	// Normally we provide the implementation for our methods inside the cpp
	// file for non-inline methods. You will learn more about this later.
	// This is a simple accessor method that returns the value stored in the
	// number variables inside this class
	int getNumber()
	{
		return number;
	}
}; // Make sure we terminate the class with a semicolon
//---End new---

