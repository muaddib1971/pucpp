#pragma once

class Account
{
private:
	int balance;

public:
	Account() : balance(0) {}

	int get_balance() { return balance; }
	int set_balance(int new_balance) { balance = new_balance; }
	bool withdraw(int amount);
	bool deposit(int amount);
};

