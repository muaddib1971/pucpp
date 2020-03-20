#include <cstdlib>
#include "extern1.h"
#include "extern2.h"

struct foo;
void doit(foo* f);
int i;
int main() {
    i = 5;
    /* incomplete type */
    foo* f;
    return EXIT_SUCCESS;
}

struct foo {
    int a, b;
};

void func(foo* f) {
    f->a = 5;
    f->b = 42;
}
