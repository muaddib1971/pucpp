/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: tree.h
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: define the specification of the custom tree for this
 * application.
 *****************************************************************************/
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#pragma once

namespace cpt323::tree
{
        /* the node class */
        class node
        {
                /* each node has pointers to left, right and a data element */
                std::unique_ptr<node> left;
                std::unique_ptr<node> right;
                std::string data;
                /* the tree class is a friend and so it can access any of the
                 * internal data
                 */
                friend class tree;

              public:
                /* constructor : initialise the data and set the left and
                 * right pointers to nullptr */
                node(const std::string& _data)
                    : left(nullptr), right(nullptr), data(_data)
                {
                }

                void add(const std::string&);

                /* setting the left and right pointers - we make this node
                 * the owner of all the children of this node */
                void set_left(std::unique_ptr<node>&& newleft)
                {
                        left = std::move(newleft);
                }

                void set_right(std::unique_ptr<node>&& newright)
                {
                        right = std::move(newright);
                }
        };

        /**
         * our tree class
         **/
        class tree
        {
                /* the root node is the owner of all child nodes */
                std::unique_ptr<node> root;
                /* total nodes in the tree */
                std::size_t num_nodes;

              public:
                /* the iterator for our tree */
                class iterator
                {
                        /* the current node in our tree */
                        node* current;
                        /* a stack of nodes we are yet to visit for an
                         * in-order iteration */
                        std::stack<node*> nodestack;

                      public:
                        /* functions implemented in the cpp file */
                        iterator(void);
                        iterator(node*);
                        std::string& operator*(void) const;
                        iterator operator++(void);
                        iterator operator++(int);
                        void push_nodes(node*);
                        bool operator==(const iterator&);
                        bool operator!=(const iterator&);
                };

              public:
                tree(void);
                void add(const std::string&);
                iterator begin(void) const;
                iterator end(void) const;
                std::size_t size(void);

                /* empty sort function for the sake of simulation */
                void sort(void)
                {
                }

                /* is the tree empty ? (no nodes) */
                bool empty(void) const
                {
                        return root == nullptr;
                }

                /* for destruction there is no work to do as all objects have
                 * their own destructors */
                virtual ~tree(void)
                {
                }
        };
} // namespace cpt323::tree
