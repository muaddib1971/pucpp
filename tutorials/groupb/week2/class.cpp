#include <string>
#include <vector>
class some_class {
    int i;
    double d;
    std::string s;
};

int main() {
    int i;
    some_class sc(i);
    some_class* aclass = new some_class;
    std::vector<int> ints;
    ints.push_back(3);
    ints.push_back(4);
    ints.push_back(4);
    ints.push_back(7);

    std::vector<std::string> names = {"fred", "barney", "wilma"};
}

using word = std::pair<std::string, std::size_t>;
