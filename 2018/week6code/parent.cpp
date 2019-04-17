#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
class parent
{
        int prvint;

      public:
        parent() : prvint(0) {}
        parent(int i) : prvint(i) {}
        int get_prv() { return prvint; }
        virtual int get_value(void)
        {
                std::cout << "hello from parent"
                          << "\n";
                return prvint;
        }
};

class child : public parent
{
        int myint;

      public:
        using parent::parent;
        int get_my_int() { return myint; }

        virtual int get_value(void) override
        {
                std::cout << "hello from child\n";
                return myint;
        }
};

int
main()
{
        std::vector<std::unique_ptr<parent>> parents;
        child ch(3);
        ch.get_value();
        parent* pptr = dynamic_cast<parent*>(&ch);
        assert(pptr);
        pptr->get_value();
        for (const auto& par : parents)
        {
                child* chptr = dynamic_cast<child*>(par.get());
                if (chptr)
                {
                        /* we reach in here if the object is a child */
                }
        }
        int i = 5;
        char thechar = static_cast<char>(i);
        const char conchar = 'c';
        char* d = const_cast<char*>(&conchar);
        *d = 's';
        std::cout << conchar << "\n";
}
