#include <iostream>
#include <memory>
class abstract
{
      public:
        virtual void doit(void) = 0;
};

class concrete : public abstract
{
      public:
        virtual void doit(void) override
        {
                std::cout << "hello from concrete";
        }
};

void doit(std::unique_ptr<abstract>& anobj)
{
        anobj->doit();
}

void doit(std::unique_ptr<abstract>&& anobj)
{
        anobj->doit();
}

void doit(abstract* aptr)
{
        aptr->doit();
}

int main(void)
{
        std::unique_ptr<concrete> aconc = std::make_unique<concrete>();
        // doit(aconc); - this one will call a compiler error.
        doit(aconc.get());
        std::unique_ptr<abstract> aabs = std::move(aconc);
        doit(aabs);
        doit(std::move(std::make_unique<concrete>()));
        std::unique_ptr<abstract> another_abs = std::make_unique<concrete>();
        doit(another_abs);
}
