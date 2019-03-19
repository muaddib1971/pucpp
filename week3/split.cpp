#include "split.h"

std::vector<std::string> splitter::split(const std::string& origstr, int len)
{
        std::vector<std::string> output;
        boost::split(output, origstr, [len](char ch)->bool
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
        });
        return output;
}
