#pragma once

#include "account1.h"

class FlexiAccount : public Account
{
private:
	int overdraft_limit;

public:
	FlexiAccount() : overdraft_limit(0) {}

	bool set_overdraft_limit(int limit);
};

