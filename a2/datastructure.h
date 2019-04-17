#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <string>
#include <vector>
#ifndef DS_H
#define DS_H
namespace cpt323::datastructure
{
        /**
         * parent data structure for all
         **/
        struct datastructure
        {
                /* the abstract iterator that all iterators should inherit from
                 */
                struct iterator
                {
                        /* how do we dereference an iterator? */
                        virtual std::string& operator*(void) const = 0;
                        /* how do we increment the iterator (pre-increment) */
                        virtual std::unique_ptr<iterator> operator++(void) = 0;
                        /* how do we increment an iterator? (post-increment) */
                        virtual std::unique_ptr<iterator> operator++(int) = 0;
                        /* how do we define two iterators to be equal? */
                        virtual bool operator==(const iterator&) = 0;
                        /* how do we define that two iterators are unequal? */
                        virtual bool operator!=(const iterator& it) = 0;
                        /* how do we destroy an iterator? */
                        virtual ~iterator()
                        {
                        }
                };

                /* how do we add an item to our datastructure */
                virtual void add(const std::string&) = 0;
                /* returns a unique_ptr<iterator> to the start of the
                 * datastructure */
                virtual std::unique_ptr<iterator> begin(void) = 0;
                /* returns a unique_ptr<iterator> to one element past
                 * the end of our data structure */
                virtual std::unique_ptr<iterator> end(void) = 0;
                /* how many items does our data structure hold? */
                virtual std::size_t size(void) = 0;
                /* how do we sort this data structure? */
                virtual void sort(void) = 0;
                /* is this data structure empty */
                virtual bool empty(void) = 0;
                /* how do I save this data structure to a file */
                void save(const std::string&);
                virtual ~datastructure()
                {
                }
        };
}
#endif
