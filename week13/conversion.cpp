#include <iostream>
class game {
    int score;

   public:
    game(int ascore) : score(ascore) {}
    game(double another) : score(int(another)) {
        std::cout << "hello from double constructor\n";
    }
    int get_score() { return score; }
#if 0
    operator int() { return score; }
#endif
    game operator++(void) {
        ++score;
        return *this;
    }

    game(game &other) { other.score = 42; }

    game operator--(void) {
        --score;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &, const game &);
};

std::ostream &operator<<(std::ostream &out, const game &agame) {
    out << agame.score;
    return out;
}

int main() {
    game g = 5;
    game h = 7.6;
    ++g;
    std::cout << g << "\n";
    --h;
    std::cout << h << "\n";
}

class shared_ptr {
    int refcount;

   public:
    shared_ptr(shared_ptr &orig) : refcount(orig.refcount) {
        refcount++;
        orig.refcount = refcount;
    }
    int get_option(int s, int t, int i = 0, int j = 0, int k = 0) {}
    const int &doit(const foo &afoo) const {}
};
