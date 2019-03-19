#include <chrono>
#include <iostream>

class Timer
{
      private:
        std::chrono::time_point<std::chrono::system_clock> lastTime;

      public:
        Timer() { time(); }
        float time();
};

float
Timer::time()
{
        auto thisTime = std::chrono::system_clock::now();
        lastTime = thisTime;
        runit();
        std::chrono::duration<float> deltaTime = thisTime - lastTime;
        return deltaTime.count() * 1000.0f;
}

int
main()
{
        Timer time;
        std::cout << time.time() << "\n";
        return 0;
}
