#pragma once

#include "account2.h"

class FlexiAccount : public Account
{
private:
i	nt overdraft_limit;

public:
	FlexiAccount() : overdraft_limit(0) {}

	bool set_overdraft_limit(int limit);
	bool withdraw(int amount);
};

