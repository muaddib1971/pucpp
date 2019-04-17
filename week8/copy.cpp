#include <iostream>
#include <cstring>
class Array
{
        int* myarray;
        int mysize;

      public:
        Array() : myarray(nullptr), mysize(0)
        {
        }

        explicit Array(int size) : myarray(new int[size]), mysize(size)
        {
        }
#if 0
        Array(const A& orig) : myarray(orig.myarray), mysize(orig.mysize)
        {
        }
#endif

        Array(const A& orig)
            : myarray(new int[orig.mysize]), mysize(orig.mysize)
        {
                memcpy(myarray, orig.myarray, mysize * sizeof(int));

                for (int count = 0; count < orig.size; ++count)
                {
                        myarray[count] = orig.myarray[count];
                }

                // copy data from orig to this class
        }
        /* rvalue reference */
        Array(A&& orig)
            : myarray(std::move(orig.myarray)), mysize(std::move(mysize))
        {
                orig.myarray = nullptr;
        }

        // Array& operator=(Array * this, const A& orig)
        Array& operator=(const A& orig)
        {
                delete[] myarray;
                myarray = new int[orig.mysize];
                mysize = orig.mysize;
                // do copying
                return *this;
        }

        ~Array()
        {
                delete[] myarray;
                std::cout << "you deleted me" << std::endl;
        }
};

enum class day
{
        MON,
        TUES,
        WED,
        THURS,
        FRI,
        SAT,
        SUN,
        INVAL = -1
};

day& operator++(day& aday)
{
        int iday = (int)day;
        if (iday == (int)day::SUN || aday == day::INVAL)
        {
                aday = day::INVAL;
        }
        else
        {
                iday++;
                aday = day(iday);
        }
        return aday;
}

day operator++(day& aday, int)
{
        day orig = aday;
        ++aday;
        return orig;
}

int main()
{
        Array an_a = 4;
        Array another_a = -2;
        std::string astring = "hello";
        Array a(5), b = a;
        Array c = std::move(b);
        b = a;
#if 0
#endif
        std::cout << "end of main" << std::endl;
        for (daynum = day::MON; daynum <= day::SUN; ++daynum)
        {
        }
}
