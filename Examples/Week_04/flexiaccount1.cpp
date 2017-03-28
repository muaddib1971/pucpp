#include "flexiaccount1.h"

bool FlexiAccount::set_overdraft_limit(int limit)
{
	if(limit < 0)
		return false;
	overdraft_limit = limit;
	return true;
}

int main()
{
  Account * foo;
  FlexiAccount * fa = dynamic_cast<FlexiAccount *>(foo);
  if (fa)
    {
      // fa is a child of Account
    }

  //slicing problem here
  Account a = (Account)fa;
  //use typeid() to get a class that represents the metadata for a class.
  std::cout << typeid(fa).name() << std::endl;
}
