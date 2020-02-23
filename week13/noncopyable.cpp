#include <memory>
class noncopyable {
   public:
    noncopyable() = default;
    noncopyable(const noncopyable& other) = delete;

    noncopyable(noncopyable&& other) = delete;
};

void doit(noncopyable&& nc) {}

int main(void) {
    noncopyable xerox;
    doit(std::move(xerox));
}
