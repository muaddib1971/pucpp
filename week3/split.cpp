#include "split.h"

std::vector<std::string> splitter::split(const std::string& origstr, int len)
{
        std::vector<std::string> output;
        auto func = [&](char ch)->bool
        {
                (void)ch;
                static int count = 0;
                count++;
                if (count > len)
                {
                        count = 0;
                        return true;
                }
                return false;
        };
        boost::split(output, origstr, func);
        return output;
}
