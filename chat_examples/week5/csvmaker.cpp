#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

int main(void)
{
    std::uniform_int_distribution<int> dist(-1000000,1000000);
    /* std::chrono - clocks we can get the time from */
    std::time_t now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());
    /* mersenne twister */
    std::mt19937 rand(now);
    std::ofstream out("nums.csv");
    for(int count = 0; count < 1000000; ++count)
    {
        int i = dist(rand);
        out << i << ",";
    }

}
