#include <boost/tokenizer.hpp>
#include <string>

int main(void)
{
        std::string line("This is a test,string");
        // separator chars being comma space
        boost::char_separator<char> sep{ ", " };
        boost::tokenizer<boost::char_separator<char> > tok(line, sep);
        for (auto const& token : tok)
        {
                std::cout << token << "\n";
        }
        return EXIT_SUCCESS;
}
