/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: reader.cpp
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: contains implementations of the algorithms to read in
 * lines from a file with each of the data structures in this project
 *****************************************************************************/
#include "reader.h"

/* please note that each function in this module returns a unique_ptr only as
 * a check that the operation succeeded. I would have used std::optional but
 * it does not accept non-copyable classes.
 *
 * Also I have used the string_view class which is simply a thin wrapper around
 * a char pointer as is more efficient (both in time and space ) to pass around
 * than a std::string especially if we don't need to modify it. You should have
 * a read over its documentation.
 */

#ifdef USELIST
/**
 * load a file into a custom linked list
 **/
std::unique_ptr<cpt323::list::list> cpt323::reader::readfile(
    std::string_view filename)
{
        std::unique_ptr<cpt323::list::list> thelist = nullptr;
        /* open the file and check for errors */
        std::ifstream in(filename.data());
        if (!in)
        {
                perror("failed to open file for reading");
                return nullptr;
        }
        /* we should throw an io exception when the fail or bad bits are set
         * on the stream
         */
        in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
                /* create the list */
                thelist = std::make_unique<cpt323::list::list>();
                /* read each line from the file */
                std::string line;
                while (std::getline(in, line))
                {
                        thelist->add(line);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle the memory allocation errors */
                perror("memory allocation error");
                return nullptr;
        }
        catch (std::ios::failure& iff)
        {
                /* check if we are at the end of the file and if we are not,
                 * display an error appropriate to the io error that has occured
                 */
                if (!in.eof())
                {
                        perror("failed to read file");
                        return nullptr;
                }
        }
        catch (std::exception& ex)
        {
                /* handle any other errors */
                std::cerr << ex.what() << "\n";
        }
        return thelist;
}

#elif defined(USETREE)
/**
 * read a file from the specified filename into a custom binary search tree
 **/
std::unique_ptr<cpt323::tree::tree> cpt323::reader::readfile(
    std::string_view filename)
{

        std::unique_ptr<cpt323::tree::tree> newtree = nullptr;

        /* open the file and check for errors */
        std::ifstream in(filename.data());
        if (!in)
        {
                perror("failed to open file");
                return nullptr;
        }
        /* specify which exceptions to throw */
        in.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* create the tree */
                newtree = std::make_unique<cpt323::tree::tree>();
                /* read in each word from the file into our tree */
                std::string line;
                while (std::getline(in, line))
                {
                        newtree->add(line);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle memory allocation errors */
                perror("failed to allocate memory");
                return nullptr;
        }
        catch (std::ios::failure& iff)
        {
                /* handle errors other than if we have reached the end of the
                 * file */
                if (!in.eof())
                {
                        perror("failed to read file");
                        return nullptr;
                }
        }
        catch (std::exception& ex)
        {
                std::cerr << "An error occured: " << ex.what() << "\n";
        }
        return std::move(newtree);
}

#elif defined(USESTDLIST)
/**
 * reads in a file into a std::list
 **/
std::unique_ptr<std::list<std::string> > cpt323::reader::readfile(
    std::string_view filename)
{
        /* create the list to insert into */
        std::unique_ptr<std::list<std::string> > newlist = nullptr;

        /* open the file and deal with errors */
        std::ifstream in(filename.data());
        if (!in)
        {
                perror("failed to open file");
                return nullptr;
        }
        in.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                newlist = std::make_unique<std::list<std::string> >();
                /* read in each line  and add to the end of the std::list */
                std::string line;
                while (std::getline(in, line))
                {
                        newlist->push_back(line);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle memory allocation errors */
                perror("failed to allocate memory");
                return nullptr;
        }
        catch (std::ios::failure& iff)
        {
                /* if we are not at the end of the file, display the memory
                 * errors */
                if (!in.eof())
                {
                        perror("failed to read file");
                        return nullptr;
                }
        }
        catch (std::exception& ex)
        {
                /* catch any leftover exceptions */
                std::cerr << "An error occured: " << ex.what() << "\n";
                return nullptr;
        }
        return std::move(newlist);
}
#elif defined(USESET)
/**
 * load the specified data file into a std::multiset
 **/
std::unique_ptr<std::multiset<std::string> > cpt323::reader::readfile(
    std::string_view filename)
{
        /* the pointer to our set */
        std::unique_ptr<std::multiset<std::string> > newset = nullptr;

        /* open the file and validate that the open succeeded */
        std::ifstream in(filename.data());
        if (!in)
        {
                perror("failed to open file");
                return nullptr;
        }
        /* specify what exceptioins to throw in regards to io */
        in.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* allocate space for the set */
                newset = std::make_unique<std::multiset<std::string> >();
                /*read in each line from the list and insert it into the set*/
                std::string line;
                while (std::getline(in, line))
                {
                        newset->insert(line);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle memory allocatioin errors */
                perror("failed to allocate memory");
                return nullptr;
        }
        catch (std::ios::failure& iff)
        {
                /* if we are not at the end of the file, handle io errors */
                if (!in.eof())
                {
                        perror("failed to read file");
                        return nullptr;
                }
        }
        catch (std::exception& ex)
        {
                std::cerr << "An error occured: " << ex.what() << "\n";
        }
        return std::move(newset);
}

#elif defined(USEVECTOR)
/**
 * load the data into a vector
 **/
std::unique_ptr<std::vector<std::string> > cpt323::reader::readfile(
    std::string_view filename)
{
        /* the pointer to our vector */
        std::unique_ptr<std::vector<std::string> > newvec = nullptr;

        /* open the file for reading and validate that it opened successfully */
        std::ifstream in(filename.data());
        if (!in)
        {
                perror("failed to open file");
                return nullptr;
        }
        /* specify the exceptioins to handle */
        in.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* allocate space for our vector */
                newvec = std::make_unique<std::vector<std::string> >();
                /* read in each line and store it in the vector */
                std::string line;
                while (std::getline(in, line))
                {
                        newvec->push_back(line);
                }
        }
        catch (std::bad_alloc& ba)
        {
                /* handle memory allocation errors */
                perror("failed to allocate memory");
                return nullptr;
        }
        catch (std::ios::failure& iff)
        {
                /* if we are not at end of the file, display an error to let the
                 * user of the program know what has gone wrong */
                if (!in.eof())
                {
                        perror("failed to read file");
                        return nullptr;
                }
        }
        catch (std::exception& ex)
        {
                /* handle any other possible errors */
                std::cerr << "An error occured: " << ex.what() << "\n";
                return nullptr;
        }
        return std::move(newvec);
}
#endif
