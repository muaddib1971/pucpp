#include <iostream>
#if 0
class shape
{
    public:
        virtual void draw() = 0;
};

class rect : virtual public shape
{
    public:
    void draw()
    {
        shape::draw();
    }
};

class circle : virtual public shape
{
    public:
    void draw()
    {
        shape::draw();
    }
};

class roundedrect : public rect, public circle
{
    public:
    void draw()
    {
        shape::draw();
        shape::area=5;

        std::cout << shape::area;
    }
};
#endif

class engine
{
      public:
        engine()
        {
                std::cout << "broom broom\n";
        }

        void start()
        {
                std::cout << "broooooooooooooooooooooooooooom\n";
        };
};

class car : private engine
{
        using engine::engine;

      public:
        void start()
        {
                engine::start();
        }
};

int main()
{
        car thecar;
        thecar.start();
}
