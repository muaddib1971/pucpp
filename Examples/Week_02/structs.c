#include <stdlib.h>
#include <stdio.h>

// A struct in C is similar to a class in C++, both can store member variables,
// and function pointers can be used to act as methods on a class.
typedef struct EventLog;
struct EventLog
{
        int count;

        int (*increment)(struct EventLog *e);
        void (*set)(struct EventLog *e, int value);
        void (*print)(struct EventLog *e);
};

// Actual functions need to be defined that the function pointers can use.
int eventLog_increment(EventLog *e)
{
        e->count++;
        return e->count;
}

void eventLog_set(EventLog *e, int value)
{
        e->count = value;
}

void eventLog_print(EventLog *e)
{
        printf("%d\n", e->count);
}

// This function acts as a constructor, creating and returning a new "object."
EventLog *createEventLog()
{
        EventLog *newEventLog = (EventLog *)malloc(sizeof(EventLog));
        newEventLog->count = 0;

        // In C++ this would happen behind the scenes, but in C we need to tell
        // the struct where it can find these functions.
        newEventLog->increment = eventLog_increment;
        newEventLog->set = eventLog_set;
        newEventLog->print = eventLog_print;
        return newEventLog;
}

int main(int argc, char **argv)
{
        EventLog *e = createEventLog();

        // In C++ e would be passed to these functions implicitly, but in C we
        // need
        // to tell the functions what struct to act on.
        e->print(e);
        e->set(e, 10);
        e->increment(e);
        e->print(e);

        return EXIT_SUCCESS;
}
