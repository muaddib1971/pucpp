#include "account1.h"

bool Account::withdraw(int amount)
{
	if(amount <= 0 || amount > balance)
		return false;
	balance -= amount;
	return true;
}

bool Account::deposit(int amount)
{
	if (amount <= 0)
		return false;
	balance += amount;
	return true;
}
