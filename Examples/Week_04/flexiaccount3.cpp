#include "flexiaccount3.h"
#include <algorithm>

int FlexiAccount::get_balance()
{
	return Account::get_balance() - overdraft;
}

bool FlexiAccount::withdraw(int amount)
{
	if(amount <= 0 || amount > (get_balance() + overdraft_limit))
		return false;
	int from_account = std::min(Account::get_balance(), amount);
	Account::withdraw(from_account),
	overdraft += amount - from_account;
	return true;
}

bool FlexiAccount::deposit(int amount)
{
	if(amount < 0)
		return false;
	int to_overdraft = std::min(amount, overdraft);
	Account::deposit(amount - to_overdraft);
	overdraft -= to_overdraft;
	return true;
}

bool FlexiAccount::set_overdraft_limit(int limit)
{
	if(limit < 0)
		return false;
	overdraft_limit = limit;
	return true;
}

