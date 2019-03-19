#include <iostream>
#include <cstdlib> //for EXIT_SUCCESS
#include <string>
#include <memory>
#include <cassert>

struct person
{
        std::string fname;
        std::string lname;
        int age;
        person(std::string first, std::string last, int years)
            : fname(first), lname(last), age(years)
        {
        }

        virtual ~person()
        {
                std::cout << "destroying a person\n";
        }
};

void doit(person* ap)
{
        std::cout << "inside the pointer version"
                  << "\n";
        std::cout << ap->fname << "\n";
}

void doit(person& rp)
{
        std::cout << "inside the reference version"
                  << "\n";
        std::cout << rp.fname;
}

void change_owner(std::unique_ptr<person>&& newp)
{
        std::cout << "newp is a rvalue reference!\n";
        std::cout << "rvalue references are \"new\" objects that allow us to "
                     "change owners\n";
        std::cout << newp->fname << " " << newp->lname << " " << newp->age
                  << "\n";
}
nullptr_t == nullptr int* pi = nullptr;

int main(void)
{
        auto i = 3;
        std::unique_ptr<person> p =
            std::make_unique<person>("fred", "flinstone", 28);
        doit(p.get());
        doit(*p);
        change_owner(std::move(p));
        std::cout << p->fname << " " << p->lname << " " << p->age << "\n";
}
