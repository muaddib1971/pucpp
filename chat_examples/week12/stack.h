#include <vector>
template <class T>
class stack : protected std::vector<T>
{
    public:

        virtual void push(const T& t);
        void pop(void);
        T top(void);
        T peek(void);
};

class int_stack : public stack<int>
{
    public:
        virtual void push(const int& i) override
        {
            push_back(i);
        }
};

int main(void)
{
    stack<int> int_stack;
    int_stack.push_back(3);
}
