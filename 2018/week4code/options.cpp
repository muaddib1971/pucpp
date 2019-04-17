#include <string>
#include <vector>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
const int MAXITEMS = 2000;

/* the idea here is to read the count of items to read into the count variable
 * and the actual items into the items vector. If the count does not equal the
 * number of items then there was an error. Please note that you may not assume
 * any associations between the command line arguments unless it is explicitly
 * stated in the assignment specification */
int main(int argc, char** argv)
{
        /* the number of items to read*/
        int count;
        /* vector of the items to read */
        std::vector<std::string> items;
        /* object that holds all the options */
        po::options_description desc("allowed options");
        /* add the options */
        desc.add_options()("help,h", "print usage message")(
            "count,c", po::value<int>(&count), "how many items to expect")(
            "item,i", po::value<std::vector<std::string> >(&items),
            "an item to add to the vector");
        /* the map of all the variables that are associated with the parsers */
        po::variables_map vm;
        /* list of positional options */
        po::positional_options_description podesc;
        podesc.add("count", 1).add("item", MAXITEMS);
        /* parse argv */
        po::store(po::command_line_parser(argc, argv)
                      .options(desc)
                      .positional(podesc)
                      .run(),
                  vm);
        /* notify the system that parsing is complete */
        po::notify(vm);
        /* test each command line variable */
        if (vm.count("help") == 1)
        {
                std::cout << "help!"
                          << "\n";
        }
        if (vm.count("count") == 1)
        {
                std::cout << count << std::endl;
        }
        if (items.size() != count)
        {
                std::cerr << "Error: invalid number of items entered.\n";
        }
        for (auto const& item : items)
        {
                std::cout << item << "\n";
        }
        return EXIT_SUCCESS;
}
