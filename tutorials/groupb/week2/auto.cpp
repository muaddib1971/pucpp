#include <memory>
#include <string>
#include <vector>
int main(void) {
    std::vector<std::string> strings;
    for (std::vector<std::string>::iterator it = strings.begin();
         it != strings.end(); ++it) {
    }

    auto somevar = 0.6;

    int* i = 0;
    i = new int(0);
#if 0
    nullptr instance of nullptr_t
        object convertible to void *
#endif
    std::unique_ptr<int> myint = std::make_unique<int>(6);
    std::unique_ptr<int> yourint = nullptr;
}
