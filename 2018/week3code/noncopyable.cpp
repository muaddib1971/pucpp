#include <memory>

class noncopyable
{
        std::unique_ptr<int> intptr;

      public:
        noncopyable(int i) : intptr(std::make_unique<int>(i))
        {
        }

        noncopyable(const noncopyable& nc)
            : intptr(std::make_unique<int>(*nc.intptr))
        {
        }

        noncopyable operator=(const noncopyable& nc)
        {
                noncopyable mync = nc;
                return mync;
        }
};

class invalid_copy
{

        int* theint;

      public:
        invalid_copy(int i) : theint(new int(i))
        {
        }
        /* && rvalue reference */
        /* a=3; 3 is an r value */
        /* you cannot take the address of 3 */
        /* you cannot assign to 3 */
        /* "hello" */
        /* can only pass by move */
        invalid_copy(invalid_copy&& orig) : theint(std::move(orig.theint))
        {
        }

        virtual ~invalid_copy(void)
        {
                if (theint)
                {
                        delete theint;
                }
        }
};

class game
{
        int score;

      public:
        explicit game(const int i) : score(i)
        {
        }
};

int main(void)
{
        noncopyable nc(3);
        noncopyable ac(0);

        invalid_copy ic(4);
        invalid_copy myic = ic;
        ac = nc;
        /* std::string(const char *) */
        std::string newstr = "foo";
        game g = 5;
        game g(5);
}
