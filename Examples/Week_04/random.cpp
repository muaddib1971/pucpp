#include <random>
#include <iostream>
#include <chrono>
#include <cstdlib>

int main(void)
{
        //get the duration since the unix epoch began
        auto duration = std::chrono::system_clock::now().time_since_epoch();
        //seed with number of milliseconds since the unix epoch began
        long millis = std::chrono::duration_cast<std::chrono::milliseconds>(
        duration).count();
        std::mt19937 gen(millis);
        //set the range for the generator - in this case between 0 and 5 inclusive
        std::uniform_int_distribution<unsigned> dist(0,5);
        unsigned count;
        vector<int>ints(6);
        for(count = 0; count < 20; ++count)
        {
                int i = gen() % 6;
                std::cout << ints[dist(gen)] << std::endl;
        }
        return EXIT_SUCCESS;
}
