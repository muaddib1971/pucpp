#include "tree.h"

bool cpt323::week04::tree::add(int val) {
    if (!root) {
        root = new node(val);
    } else {
        if (val < root->data) {
            if (root->left) {
                root->left->add(val);
            } else {
                root->left = new node(val);
            }
        } else {
            /* repeat above for the right */
        }
    }
    return true;
}

bool cpt323::week04::tree::contains(int val) {}

bool cpt323::week04::tree::node::add(int val) {
    if (val < this->data) {
        if (left) {
            left->add(val);
        } else {
            left = new node(val);
        }
    } else {
        /* same logic for the right as we have above for left */
    }
}
