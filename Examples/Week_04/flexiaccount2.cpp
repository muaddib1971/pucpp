#include "flexiaccount2.h"

bool FlexiAccount::set_overdraft_limit(int limit)
{
	if(limit < 0)
		return false;
	overdraft_limit = limit;
	return true;
}

#define SLIDE11
#ifdef SLIDE10
bool FlexiAccount::withdraw(int amount)
{
	if(amount <= 0 || amount > balance + overdraft_limit)
		return false;
	balance -= amount;
	return true;
}
#else
bool FlexiAccount::withdraw(int amount)
{
	if(amount <= 0 || amount > get_balance() + overdraft_limit)
		return false;
	set_balance(get_balance() - amount);
	return true;
}
#endif

