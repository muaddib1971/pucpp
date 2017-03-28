#include <iostream>
#include "constructors.h"

using namespace std;

int main(int argc, char **argv)
{
	EventLog log;
        //increment and set and constructor visible here
        //k and count not visible here.
	cout << log.increment();
	return 0;
}
