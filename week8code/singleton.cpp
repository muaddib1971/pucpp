#include "singleton.h"
std::unique_ptr<singleton> singleton::instance = nullptr;
/* in the cpp file */

singleton::singleton(void) : i(0)
{
}

singleton* singleton::get_instance(void)
{
        if (instance == nullptr)
        {
                instance = std::unique_ptr<singleton>(new singleton);
        }
        return instance.get();
}

/* in main */

int main(void)
{
        singleton* single = singleton::get_instance();
        singleton* second = singleton::get_instance();
        std::cout << single << '\t' << second << std::endl;
}
