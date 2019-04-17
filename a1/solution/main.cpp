/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: main.cpp
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: contains the main() function for this application. it
 * validates command line arguments and if accepted, intialises data structures,
 * calls the sort function and then calls the function that writes data out to a
 * file.
 *****************************************************************************/
#include "main.h"

int main(int argc, char* argv[])
{
        /* filenames used in this program */
        std::string outname;
        std::string filename;

        /* create the options description for the program_options boost library
         */
        boost::program_options::options_description desc("options");
        desc.add_options()("help,h", "print help messages")
            /* specify -f which is a required argument for specifying the file
             * to sort */
            ("file,f",
             boost::program_options::value<std::string>(&filename)->required(),
             "the input file name to sort")
            /* specify -o which is a required argument for specifying the file
               to
               output the sorted list of words to */
            ("output,o",
             boost::program_options::value<std::string>(&outname)->required(),
             "The file to output the sorted data into");

        /* the variables map filled out by processing the command line
         * argumemnts
         */
        boost::program_options::variables_map vm;
        try
        {
                /* store the results of processing the command line in the
                 * variables map
                 */
                boost::program_options::store(
                    boost::program_options::command_line_parser(argc, argv)
                        .options(desc)
                        .run(),
                    vm);

                /* if the user requested help, display help information */
                if (vm.count("help") > 0)
                {
                        display_usage(argv[0]);
                        std::cout << "help text here\n";
                        return EXIT_SUCCESS;
                }
                /* parsing is done so the boost library can validate that the
                 * arguments
                 * passed in are correct */
                boost::program_options::notify(vm);
/* for each data structure, read the file and validate that it loaded
 * correctly. Next, sort the data structure and then save it out to
 * the output file
 */
#ifdef USELIST
                auto thelist = cpt323::reader::readfile(filename);
                if (thelist)
                {
                        thelist->sort();
                        cpt323::saver::saver::savefile(outname, *thelist);
                }
#elif defined(USETREE)
                auto thetree = cpt323::reader::readfile(filename);
                if (thetree)
                {
                        thetree->sort();
                        cpt323::saver::saver::savefile(outname, *thetree);
                }
#elif defined(USESTDLIST)
                auto thelist = cpt323::reader::readfile(filename);
                if (thelist)
                {
                        thelist->sort();
                        cpt323::saver::saver::savefile(outname, *thelist);
                }
#elif defined(USESET)
                auto theset = cpt323::reader::readfile(filename);
                if (theset)
                {
                        cpt323::saver::saver::savefile(outname, *theset);
                }
#elif defined(USEVECTOR)
                auto thevec = cpt323::reader::readfile(filename);
                if (thevec)
                {
                        std::sort(thevec->begin(), thevec->end());
                        cpt323::saver::saver::savefile(outname, *thevec);
                }
#endif
                /* if the file failed to load, set the failure value back to the
                 * operating system
                 */
                else
                {
                        return EXIT_FAILURE;
                }
        }
        catch (std::exception& ex)
        {
                /* handle any errors in loading of the file or processing the
                 * data
                 * structure */
                std::cerr << ex.what() << "\n";
                display_usage(argv[0]);
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

/**
 * If the user entered the wrong arguments, this function is called. It simply
 * explains how to correctly use the program
 **/
void display_usage(std::string_view view)
{
        std::cout << "You should call this program in the following way: \n\t"
                  << view << " [args]\n";
        std::cout
            << "\n\tWhere [args] must include the following options: \n\n";
        std::cout
            << "-f followed by a filename path: the filename to read data "
               "from to sort.\n";
        std::cout
            << "-o followed by a filename path: the filename of the file to "
               "output data into.\n";
}
