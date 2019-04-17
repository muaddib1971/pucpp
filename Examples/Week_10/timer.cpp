#include <chrono>
#include <iostream>
#include <thread>

class Timer
{
      private:
        std::chrono::time_point<std::chrono::system_clock> lastTime;

      public:
        Timer()
        {
                time();
        }
        float time();
};

void runit(void)
{
        std::this_thread::sleep_for(std::chrono::seconds(3));
}

float Timer::time()
{
        auto thisTime = std::chrono::high_resolution_clock::now();
        lastTime = thisTime;
        runit();
        thisTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = thisTime - lastTime;
        return deltaTime.count() * 1000.0f;
}

int main()
{
        Timer time;
        std::cout << time.time() << "\n";
        std::cout << time.time() << "\n";
        return 0;
}
