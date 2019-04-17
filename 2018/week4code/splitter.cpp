#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <string>
/*
 * write a function that takes in a std::string and returns a vector of strings
 * where each line is folded at a certain text width
 */

std::vector<std::string> fold(const std::string& orig_string, int fold_width)
{
        std::vector<std::string> lines;
        boost::split(lines, orig_string, [&fold_width](char ch)->bool
        {
                static int char_count = 0;
                if (char_count < fold_width)
                {
                        ++char_count;
                        return false;
                }
                if (isspace(ch))
                {
                        char_count = 0;
                        fold_width += 5;
                        std::cout << "fold width is " << fold_width << "\n";
                        return true;
                }
                return false;
        });
        return lines;
}

int main(void)
{
        std::string mystring = "The third argument passed to boost::split is a "
                               "function (or a function object) that "
                               "determines whether a character is a delimiter. "
                               "For example here, we use a lambda taking a "
                               "char a returning whether this char is a space.";
        std::vector<std::string> folded = fold(mystring, 10);
        for (const auto& line : folded)
        {
                std::cout << line << "\n";
        }
        std::cout << std::flush;
        return EXIT_SUCCESS;
}
