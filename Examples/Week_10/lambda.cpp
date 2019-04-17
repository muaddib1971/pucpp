#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

void print(int i)
{
        std::cout << i << ", ";
}

struct Print
{
        void operator()(int i)
        {
                std::cout << i << ", ";
        }
};

#if 0
void sumFn(int i)
{
	sum += i;
}
#endif

struct Sum
{
        int &sum;
        Sum(int &sum) : sum(sum)
        {
        }
        void operator()(int i)
        {
                sum += i;
        }
};

int main(int argc, char **argv)
{
        std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6 };

        // Sum s(sum);
        Print p;
        p(3);
        auto lambda = [&v]()->int
        {
                int sum = 0;
                for (int i : v)
                        sum += i;
                return sum;
        };

        // std::for_each(v.begin(), v.end(), lambda);
        std::cout << lambda() << "\n";

        return 0;
}
