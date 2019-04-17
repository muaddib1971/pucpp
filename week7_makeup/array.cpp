#include <iostream>
#include <random>
#include <stdexcept>

template <class T, int I>
class array {
    T myarray[I];
    int currsize;

   public:
    struct iterator {
        T* current;
        /* where are we up to in iteration ? */
        int curcount;
        /* the size of the collection to iterate over */
        int currsize;
        iterator(nullptr_t null) : current(nullptr) {}
        iterator(T* array, int _currsize, int _currcount = 0) {
            current = array;
            curcount = _currcount;
            currsize = _currsize;
        }

        iterator operator++(void) {
            if (curcount == I - 1) {
                return iterator(nullptr);
            } else {
                current++;
                curcount++;
                /* when we reach the end of the array, set current to nullptr so
                 * it will match the definition of the end pointer */
                if (curcount == currsize) {
                    current = nullptr;
                }
                return *this;
            }
        }

        /* i++ , ++i */
        iterator operator++(int) {
            iterator current = *this;
            operator++();
            return current;
        }

        T& operator*(void) {
            if (curcount > currsize) {
                throw std::invalid_argument(
                    "gone beyond the end of the array.");
            }
            return *current;
        }

        bool operator==(const iterator& other) {
            return current == other.current;
        }
        bool operator!=(const iterator& other) { return !operator==(other); }
    };

   public:
    array() : currsize(0) {}
    T& operator[](int offset) { return myarray[offset]; }
    bool add(const T& data) {
        myarray[currsize++] = data;
        return true;
    }
    iterator begin(void) { return iterator(&myarray[0], currsize); }
    iterator end(void) { return iterator(nullptr); };
};

int main(void) {
    array<int, 20> myarray;
    std::mt19937 generator;
    std::uniform_int_distribution<int> dist(10, 1000);

    for (int count = 0; count < 10; ++count) {
        myarray.add(dist(generator));
    }

    for (typename array<int, 20>::iterator it = myarray.begin();
         it != myarray.end(); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "\n\n";
    for (auto i : myarray) {
        std::cout << i << "\n";
    }
}

/*
class parent {
    int i;
};
class child : pubic parent {
    int j;
}

parent p;
child ch;
slicing problem:
p = ch;
*/

/* invalid covariant type - a function must specify a generic type that can
 * always be returned from the function*/
