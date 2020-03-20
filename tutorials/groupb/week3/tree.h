namespace cpt323::tree {
class tree {
    struct node {
        int data;
        node* left;
        node* right;
        node(int _data) : data(_data), left(nullptr), right(nullptr) {}
        bool add(int _data) {
            if (_data < data) {
                if (left) {
                    return left->add(_data);
                }
                left = new node(_data);
                return true;
            }
            if (right) {
                return right->add(_data);
            }
            right = new node(_data);
            return true;
        }
    };
    node* root;
    tree() : root(nullptr) {}
    bool add(int data) {
        if (root == nullptr) {
            root = new node(data);
            return true;
        }
        return root->add(data);
    }
};
}  // namespace cpt323::tree

/*
 *
 *
 *       *
 *     *
 */
