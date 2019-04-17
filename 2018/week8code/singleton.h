#include <memory>
#include <iostream>
class singleton
{
        static std::unique_ptr<singleton> instance;
        int i;
        singleton(void);

      public:
        static singleton* get_instance(void);
};
