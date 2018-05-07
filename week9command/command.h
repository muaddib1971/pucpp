#include <iostream>
/* have pointers to the model and and view here */
struct command
{
        virtual void operator()(void) = 0;
};

struct quit_command : public command
{
        virtual void operator()(void)override
        {
                exit(EXIT_SUCCESS);
        }
};

struct a_command : public command
{
        virtual void operator()(void)override
        {
                std::cout << "a\n";
        }
};

struct b_command : public command
{
        virtual void operator()(void)override
        {
                std::cout << "b\n";
        }
};

struct c_command : public command
{
        virtual void operator()(void)override
        {
                std::cout << "c\n";
        }
};
