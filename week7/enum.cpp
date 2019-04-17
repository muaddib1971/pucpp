#include <iostream>
enum class emotion { SAD, HAPPY, BLUE };

enum class color { RED, GREEN, BLUE };

enum emotion &operator++(enum emotion &em) {
    int int_em = (int)em;
    if (int_em >= (int)emotion::BLUE) {
        int_em = (int)emotion::BLUE;
    } else {
        ++int_em;
    }
    em = emotion(int_em);
    return em;
}

/* problem? */
int main(void) {
    emotion emo = emotion::SAD;
    color col = color::BLUE;
    emo = emotion::BLUE;

    for (emotion e = emotion::SAD; e < emotion::BLUE; ++e) {
        std::cout << (int)e << "\n";
    }
}
