#pragma once

class EventLog
{
private:
	int count;

public:
	EventLog(int init = 0) : count(init) {}

	int increment()
	{
		return ++count;
	}

	void set(int value = 0)
	{
		count = value;
	}
};

#endif
