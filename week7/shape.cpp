#include <memory>

struct shape {
    virtual void draw() = 0;
};

struct square : public shape {
    virtual void draw() override {}
};

int main() {
    // noexcept
    std::unique_ptr<shape> s = std::make_unique<square>();
    std::unique_ptr<shape> t = std::make_unique<shape>();
    s->draw();
}
