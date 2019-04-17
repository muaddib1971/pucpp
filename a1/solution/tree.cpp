/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: list.h
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: implements the functions for the custom binary search
 * tree required by the assignment 1 specification.
 ******************************************************************************/
#include "tree.h"

/**
 * constructor for the tree - just put everything in a 0 state.
 **/
cpt323::tree::tree::tree(void) : root(nullptr), num_nodes(0)
{
}

/**
 * adds a new node to the tree that stores the string in the right position in
 * the tree.
 **/
void cpt323::tree::tree::add(const std::string& newstring)
{
        bool error = false;
        /* if we have no root, store the data in the root */
        try
        {
                if (!root)
                {
                        root = std::make_unique<node>(newstring);
                }
                else
                {
                        /* otherwise, pass the data to the root node to decide
                         * where to
                         * store it
                         */
                        root->add(newstring);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle any memory allocation errors */
                perror(ba.what());
                error = true;
        }
        /* increment the count of nodes if the insertion is successful */
        if (!error)
        {
                ++num_nodes;
        }
}

/**
 * gets an iterator to the beginning of the tree - if the tree is empty,
 * the beginning and end of the iteration is the same
 **/
cpt323::tree::tree::iterator cpt323::tree::tree::begin(void) const
{
        return root ? iterator(root.get()) : end();
}

/**
 * conceptually the end of the tree is one element past the valid objects. We
 * can similate this by an iterator that holds then null value.
 **/
cpt323::tree::tree::iterator cpt323::tree::tree::end(void) const
{
        return iterator(nullptr);
}

/**
 * get the number of nodes in the tree.
 **/
std::size_t cpt323::tree::tree::size(void)
{
        return num_nodes;
}

/**
 *  recursive function to find the right place in a tree to add a new node based
 *  on the string passed in and then add it.
 **/
void cpt323::tree::node::add(const std::string& newstring)
{
        /* if the data is less than the data in the current node, go left */
        if (data < newstring)
        {
                if (left)
                {
                        left->add(newstring);
                }
                else
                {
                        left = std::make_unique<node>(newstring);
                }
        }
        else
        {
                /* otherwise, go right */
                if (right)
                {
                        right->add(newstring);
                }
                else
                {
                        right = std::make_unique<node>(newstring);
                }
        }
}

/**
 * default constructor or iterator - creates an iterator that holds the null
 * pointer
 **/
cpt323::tree::tree::iterator::iterator(void) : current(nullptr)
{
}

/**
 * constructor that takes a node pointer. This node pointer is taken to be the
 * root node and we'll add all child nodes into a node stack in the order they
 * will be iterated over. We then grab the top node from the stack as that's the
 * first node in traversal order.
 **/
cpt323::tree::tree::iterator::iterator(node* newnode) : current(nullptr)
{
        /* if newnode is not null, add all children nodes to the node stack */
        if (newnode)
        {
                push_nodes(newnode);
        }
        else
        {
                return;
        }
        /* remove the last one we added as that's the first to iterate over */
        current = nodestack.top();
        nodestack.pop();
}

/**
 * recursive function that iterates over the nodes of the tree adding them to
 * the stack in the reverse order to how they will be traversed over.
 **/
void cpt323::tree::tree::iterator::push_nodes(node* root)
{
        if (root->left)
        {
                push_nodes(root->left.get());
        }
        nodestack.push(root);
        if (root->right)
        {
                push_nodes(root->right.get());
        }
}

/**
 * dereference operator that returns the data held in a node
 **/
std::string& cpt323::tree::tree::iterator::operator*(void) const
{
        return current->data;
}

/**
 * increments the iterator from the current node to the next node in the tree.
 **/
cpt323::tree::tree::iterator cpt323::tree::tree::iterator::operator++(void)
{
        /* if the node stack is empty, we are at the end of the tree and so
         * set the current to nullptr. Otherwise, pop from the stack */
        if (nodestack.empty())
        {
                current = nullptr;
                return iterator(*this);
        }
        current = nodestack.top();
        nodestack.pop();
        return iterator(*this);
}

/**
 * post-increment operator. grabs the pointer at the current location and stores
 * it. It then calls increment on the iterator to move it forward. We return the
 * iterator from the previous state as that is the requirement of the post-
 * increment operator.
 **/
cpt323::tree::tree::iterator cpt323::tree::tree::iterator::operator++(int)
{
        iterator it = *this;
        operator++();
        return it;
}

/**
 * equivalence operator - do the two iterators point at the same node?
 **/
bool cpt323::tree::tree::iterator::operator==(
    const cpt323::tree::tree::iterator& it)
{
        return it.current == current;
}

/**
 * inequivalence operator. Simply implemented to return the opposite of the
 * equivalence operator.
 **/
bool cpt323::tree::tree::iterator::operator!=(
    const cpt323::tree::tree::iterator& it)
{
        return !(*this == it);
}
