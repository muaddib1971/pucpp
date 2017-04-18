#include "singleton.h"
std::unique_ptr<singleton> singleton::instance = nullptr;

void singleton::doit(void)
{
    (void)instance;
}

int main(void)
{
    singleton * single = singleton::get_instance();
    return EXIT_SUCCESS;
}
