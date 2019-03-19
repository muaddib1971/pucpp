#include <boost/program_options.hpp>
#include <boost/algorithm/string/split.hpp>
#include <string>
#include <exception>
#include <vector>
#include "split.h"

int main(int argc, char** argv)
{

        std::string thestring;
        int len;

        boost::program_options::options_description desc("program options");
        desc.add_options()("help,h", "prints a help message")(
            ",s",
            boost::program_options::value<std::string>(&thestring)->required())(
            ",l", boost::program_options::value<int>(&len)->required());
        boost::program_options::variables_map vm;

        try
        {
                boost::program_options::store(
                    boost::program_options::command_line_parser(argc, argv)
                        .options(desc)
                        .run(),
                    vm);
                if (vm.count("help") > 0)
                {
                        std::cout << "help has been invoked"
                                  << "\n";
                }

                boost::program_options::notify(vm);
                std::vector<std::string> output;
                splitter thesplitter;
                output = thesplitter.split(thestring, len);
                for (auto line : output)
                {
                        std::cout << line << "\n";
                }
                std::cout << std::flush;
        }
        catch (std::exception& ex)
        {
                std::cerr << ex.what() << "\n";
                std::cerr << std::flush;
        }
}
