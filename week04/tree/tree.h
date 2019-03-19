namespace cpt323::week04 {
class tree {
    struct node {
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(nullptr), right(nullptr) {}
        bool add(int);
    };
    node* root;

   public:
    tree() : root(nullptr) {}
    bool add(int);
    bool contains(int);
};
}  // namespace cpt323::week04
