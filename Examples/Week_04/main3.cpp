#include <iostream>
#include "flexiaccount3.h"

using namespace std;

int main(int argc, char **argv)
{
	Account a;

	cout << a.get_balance();

	FlexiAccount fa;
	fa.deposit(10);
	fa.withdraw(5);
	cout << fa.get_balance();

	fa.set_overdraft_limit(20);
	fa.withdraw(10);
	cout << fa.get_balance();
}
