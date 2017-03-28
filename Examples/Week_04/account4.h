#pragma once

class Account
{
private:
	int balance;

public:
	Account(int init_balance) : balance(init_balance) {}

	int get_balance() { return balance; }
	bool withdraw(int amount);
	bool deposit(int amount);
};

