#pragma once

class EventLog
{
        private:
                int count;
        protected: 
                int k;
        public:
                EventLog() : count( 0) {}

                EventLog(int _count) 
                        : count(_count) {} 
                int increment()
                {
                        return ++count;
                }

                void set(int value)
                {
                        count = value;
                }
};

class special_event_log : public EventLog
{
        //k, constructor and increment and set all visible here.
        //count is not visible here.
};
