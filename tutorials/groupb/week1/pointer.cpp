struct stuff {};

void doit(stuff* stff) {}

int main() {
    stuff* s = new stuff;
    doit(&somestuff);
    doit(s);
}
