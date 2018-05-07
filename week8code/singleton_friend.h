#include <memory>
#include <iostream>
class singleton
{
        static std::unique_ptr<singleton> instance;
        int i;
        singleton(void);
        friend std::unique_ptr<singleton> std::make_unique<singleton>();

      public:
        static singleton* get_instance(void);
};
