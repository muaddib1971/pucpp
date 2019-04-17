#include <string>
class stat
{
        static std::string mystring;

      public:
        std::string get_string(void)
        {
                return mystring;
        }
        void set_string(const std::string& astring)
        {
                mystring = astring;
        }
};
