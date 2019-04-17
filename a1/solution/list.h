/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: list.h
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * Purpose of this file: to specify the public interface and internal structure
 * of the custom list class for this application
 *****************************************************************************/
#include <cassert>
#include <iostream>
#include <memory>
#include <utility>
#include <sstream>
#pragma once

namespace cpt323::list
{
        /* the node struct for our list */
        class node
        {
                /* each pointer is "owned" by the previous pointer and head is
                 * "owned by the list
                 */
                std::unique_ptr<node> next;
                /* the data for this node */
                std::string data;
                friend class list;

              public:
                /* create a new node that contains the string specified */
                node(const std::string& newstr)
                {
                        data = newstr;
                        next = nullptr;
                }

                /* sets the next unique_ptr */
                void set_next(std::unique_ptr<node>&& next);
                /* frees the node - it is sufficient for this function to be
                 * virtual as all elements of the struct are destructible by
                 * default
                 */
                virtual ~node()
                {
                }
        };

        /* these typedefs come in handy when finding the next element to remove
         * from the list
         */
        /* a nodeptr pair defines the previous and next pointers surrounding the
         * element to remove */
        using nodeptr = std::unique_ptr<node>*;
        using nodeptrpair = std::pair<nodeptr, nodeptr>;
        /**
         * The list class to represent a singly linked list
         **/
        class list
        {
                /* head owns all the other elements of the list because if head
                 * is deleted the rest of the list is deleted
                 */
                std::unique_ptr<node> head;
                std::size_t num_elts;

                /**
                 * inner class iterator of the list - it's an inner class so it
                 * can have access to the private data of the list which it
                 * needs to do to keep track of the current element in an
                 * iteration
                 **/
                class iterator
                {
                        /* the node currently pointed to */
                        node* current;

                      public:
                        /**
                         * default constructor for the iterator - simply set the
                         * current pointer to NULL.
                         **/
                        iterator() : current(nullptr)
                        {
                        }
                        /**
                         * the rest of these functions will be defined in the
                         * cpp file:
                         **/
                        iterator(node*);
                        std::string& operator*(void) const;
                        iterator operator++(void);
                        iterator operator++(int);
                        bool operator==(const iterator&);
                        bool operator!=(const iterator&);
                };

              public:
                /* public function / method members of the list */
                list(void);
                void add(const std::string&);
                iterator begin(void) const;
                iterator end(void) const;
                std::size_t size(void);
                void sort(void);

                void print(void);
                nodeptrpair find_min(void);

                /**
                 * test that the list is empty
                 **/
                virtual bool empty(void)
                {
                        return size() == 0;
                }

                /**
                 * destructor for a list. Needs to be here and empty as the
                 *members of this
                 * class are all destructible
                 **/
                virtual ~list(void)
                {
                }
        };
} // namespace cpt323::list
