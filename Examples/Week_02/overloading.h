#pragma once

class EventLog
{
private:
	int count;

public:
	EventLog() : count(0) {}
	EventLog(int init) : count(init) {}

	int increment()
	{
		return ++count;
	}

	void set()
	{
		set(0);
	}

	void set(int value)
	{
		count = value;
	}
};

