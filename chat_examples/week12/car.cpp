#include <iostream>
#include <cstdlib>

class engine
{
    int cylinders;
    public:
    engine(int numcylinders) : cylinders(numcylinders){}

    void start(void)
    {
        std::cout << "engine with " << cylinders << "started." 
            << std::endl;
    }
};

class car
{
    engine myengine;
    public:
        car() : myengine(8) {}

        void start()
        {
            myengine.start();
        }
};

int main(void)
{
    car c;
    c.start();

    engine * e = (engine*)&c;
    e->start();
    return EXIT_SUCCESS;
}
