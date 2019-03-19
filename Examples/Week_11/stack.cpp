#include <array>
#include <iostream>

template <typename T, int SIZE>
class stack : std::array<T*, SIZE>
{
        int insert_point;

      public:
        stack() : insert_point(0)
        {
        }

        bool push(T a_t)
        {
                (*this)[insert_point++] = &a_t;
                return true;
        }

        const T pop(void)
        {
                return *(*this)[--insert_point];
        }
};

int main(void)
{
        stack<int, 10> int_stack;
        int_stack.push(5);
        int_stack.push(3);
        int_stack.push(7);
        std::cout << int_stack.pop();
}
