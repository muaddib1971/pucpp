#pragma once

#include "account3.h"

class FlexiAccount : public Account
{
private:
	int overdraft_limit;
	int overdraft;

public:
	FlexiAccount() : overdraft_limit(0), overdraft(0) {}

	bool set_overdraft_limit(int limit);
	bool withdraw(int amount);
	bool deposit(int amount);
	int get_balance();
};

