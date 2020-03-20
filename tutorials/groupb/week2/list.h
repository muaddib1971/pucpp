#include <cstdlib>
namespace cpt323::list {
class list {
    struct node {
        int data;
        node* next;
        node() : data(0), next(NULL) {}
        node(int newdata) : data(newdata), next(NULL) {}
    };
    node* head;
    std::size_t size;

   public:
    list() : head(NULL), size(0) {}
    bool add(int newdata);
    bool remove(int olddata);
    ~list();
};
};  // namespace cpt323::list
