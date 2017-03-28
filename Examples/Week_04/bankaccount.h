#pragma once

// ---New---
// Definition for the list template is contained here
#include <list>

typedef float Money;

class BankAccount
{
private:
	Money balance;
	int account_num;

public:
	// Once again, I've provided a constructor so that we can see how this works
	BankAccount()
	{
		balance = 10.0;
	}

	Money getBalance()
	{
		return balance;
	}

	// Extra method to allow the CheckingAccount to work
	void setBalance(Money m)
	{
		balance = m;
	}
};

// I've created a check class so that we can make use of it inside the
// CheckingAccount
class Check
{
public:
	Money amount;
};

// Here we are creating a CheckingAccount class, which, in terms of a java
// class, extends the BankAccount class. We declare the BankAccount class as
// public so that the CheckingAccount can access members of the BankAccount
// class. Note that classes in C++ can extend multiple base classes, unlike
// classes in java, which can only extend a single class
class CheckingAccount : public BankAccount
{
private:
	std::list<Check *> check_list;

public:
	void deposit(Money m)
	{
		// Here we are calling the setBalance and getBalance methods from the
		// BankAccount class
		setBalance(getBalance() + m);
	}

	void withdraw(Money m)
	{
		setBalance(getBalance() - m);
	}

	void writeCheck(Check *cp)
	{
		// Just like in the vector template, we use the push_back method to add
		// elements to the end of the list
		check_list.push_back(cp);
	}
};

// ---End new---

#endif
