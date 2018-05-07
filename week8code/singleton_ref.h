#include <memory>
#include <iostream>
class singleton
{
        int i;
        singleton(void);

      public:
        static singleton& get_instance(void);
        singleton(const singleton&) = delete;
};
