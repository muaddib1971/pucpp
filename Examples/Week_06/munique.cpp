#include <cstdio>
#include <cstdlib>
#include <memory>

struct A
{
        A(int i) : i(i)
        {
                printf("Constructing<%d>...\n", i);
        }
        ~A()
        {
                printf("Destructing<%d>...\n", i);
        }
        int i;
        A& operator=(const A& a)
        {
                i = a.i;
                return *this;
        }
};

int main(int argc, char** argv)
{
        std::unique_ptr<A> a = std::make_unique<A>(1);
        printf("======\n");
        a = std::make_unique<A>(3);
        printf("======\n");
        a = std::make_unique<A>(5);
        printf("======\n");
        printf("leaving main.\n");
        return EXIT_SUCCESS;
}
