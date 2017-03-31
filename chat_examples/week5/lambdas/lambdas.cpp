#include <functional>
void foo(std::function<int(int,int)> doit)
{
}

struct game
{
    int score;
};

int main(void)
{
    int i = 5;
    int j;
    /* capturing */
    auto mylambda = [&i] (int a, int b) -> int
    {
        /* have access to i in here or any other local variable 
         * declared in the function the lambda is declared before the lambda
         */

        int k = i; /* valid */
        i = 42;
    }
    std::vector<game> games;

    foo(mylambda);


    std::vector<int> randints;
    struct
    {
        int a, b;
    } mystruct, someotherstruct;
    
    auto sort_criterion = [](const game& game_a, const game& game_b) -> bool
    {
        return game_a.score < game_b.score;
    }

    auto rev_ints = [](int a, int b) -> bool
    {
        return a > b;
    }

    std::sort(games.begin(), games.end(), sort_criterion);
}
