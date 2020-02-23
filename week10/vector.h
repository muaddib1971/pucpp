#include <initializer_list>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>

template <typename T, int SIZE>
class vector
{
        std::unique_ptr<T[]> array;
        int cursize;

      public:
        class iterator
        {
                T* current;

              public:
                iterator(T* start) : current(start)
                {
                }

                iterator& operator++(void)
                {
                        ++current;
                        return *this;
                }

                iterator operator++(int)
                {
                        iterator iter = *this;
                        ++*this;
                        return iter;
                }

                T& operator*(void) const
                {
                        return *current;
                }

                iterator operator+=(int i)
                {
                        return iterator(current + i);
                }

                iterator operator+(int i)
                {
                        iterator iter = *this;
                        return iter += i;
                }

                bool operator==(const iterator& other)
                {
                        return current == other.current;
                }

                bool operator!=(const iterator& other)
                {
                        return !(*this == other);
                }
        };

        vector() : array(std::make_unique<T[]>(SIZE)), cursize(0)
        {
        }

        vector(std::initializer_list<T> list) : vector()
        {
                for (auto item : list)
                {
                        add(item);
                }
        }

        int size()
        {
                return cursize;
        }

        iterator begin(void)
        {
                return iterator(&array[0]);
        }

        iterator end(void)
        {
                return iterator(&array[cursize]);
        }

        void add(const T& a_t)
        {
                if (cursize >= SIZE)
                {
                        throw std::out_of_range("array is already full");
                }
                array[cursize++] = a_t;
        }

        T& operator[](int i)
        {
                if (i < 0 || i >= SIZE)
                {
                        std::ostringstream oss;
                        oss << "Index specified is out of range: " << i;
                        throw std::out_of_range(oss.str());
                }
                return array[i];
        }

        int index_of(const T& needle) const
        {
                int count;
                for (count = 0; count < cursize; ++count)
                {
                        if (array[count] == needle)
                        {
                                return count;
                        }
                }
                return EOF;
        }

        T remove_at(int i)
        {
                if (i > cursize)
                {
                        std::ostringstream oss;
                        oss << "index specified is out of range: " << i;
                        throw std::out_of_range(oss.str());
                }
                T removed = array[i];
                for (int remcount = i; remcount < cursize - 1; ++remcount)
                {
                        array[remcount] = array[remcount + 1];
                }
                --cursize;
                return removed;
        }

        void erase(const iterator& begin, const iterator& end)
        {
                int start = index_of(*begin);
                int finish = index_of(*end);
                if (start == EOF || finish == EOF || start > finish)
                {
                        throw std::invalid_argument("invalid iterators");
                }
                for (int remcount = start; remcount <= finish; ++remcount)
                {
                        remove_at(start);
                }
        }
};
