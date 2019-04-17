#include "singleton_ref.h"
/* in the cpp file */

singleton::singleton(void) : i(0)
{
}

singleton& singleton::get_instance(void)
{
        static singleton instance;
        return instance;
}

/* in main */

int main(void)
{
        singleton& single = singleton::get_instance();
        singleton& second = singleton::get_instance();
        std::cout << &single << '\t' << &second << std::endl;
}
