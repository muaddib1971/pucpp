/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: saver.cpp
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: implements the functions to save to a file the contests
 * of a data structure in the order the elements are currently stored.
 *****************************************************************************/
#include "saver.h"
#ifdef USELIST
/**
 * save a custom linked list to a text file
 **/
bool cpt323::saver::saver::savefile(std::string_view filename,
                                    const cpt323::list::list& thelist)
{
        /* open the file for output */
        std::ofstream out(filename.data());
        if (!out)
        {
                perror("failed to open file for saving");
                return false;
        }
        /* specify the io exceptions to throw */
        out.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* iterate over the list, writing out each element */
                for (const auto& item : thelist)
                {
                        out << item << "\n";
                }
                out << std::flush;
        }
        catch (std::ios::failure& iff)
        {
                /* handle any errors in writing */
                perror("failed to save the file");
                return false;
        }
        return true;
}

#elif defined(USETREE)
/**
 * save the custom tree to a file
 **/
bool cpt323::saver::saver::savefile(std::string_view filename,
                                    const cpt323::tree::tree& thetree)
{
        /* open the outpt file for writing */
        std::ofstream out(filename.data());
        if (!out)
        {
                perror("failed to open file for saving");
                return false;
        }
        /* specify the io exceptions to throw */
        out.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* iterate over the tree and write out each line to the file */
                for (const auto& item : thetree)
                {
                        out << item << "\n";
                }
                out << std::flush;
                /* flush data to the file */
        }
        catch (std::ios::failure& iff)
        {
                /* handle all io errors */
                perror("failed to save the file");
                return false;
        }
        return true;
}
#elif defined(USESTDLIST)
/**
 * save the data from the std::list to a file
 **/
bool cpt323::saver::saver::savefile(std::string_view filename,
                                    const std::list<std::string>& alist)
{
        /* open the file specified for output */
        std::ofstream out(filename.data());
        if (!out)
        {
                perror("failed to open file for saving");
                return false;
        }
        /* specify what exceptions will be thrown */
        out.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* output each word to the file */
                for (const auto& item : alist)
                {
                        out << item << "\n";
                }
                /* flush the data to the file once all has been written out */
                out << std::flush;
        }
        catch (std::ios::failure& iff)
        {
                /* handle any io errors */
                perror("failed to save the file");
                return false;
        }
        return true;
}
#elif defined(USESET)
bool cpt323::saver::saver::savefile(std::string_view filename,
                                    const std::multiset<std::string>& theset)
{
        /* open the file specified for writing */
        std::ofstream out(filename.data());
        if (!out)
        {
                perror("failed to open file for saving");
                return false;
        }
        /* specify which exceptions to throw */
        out.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* iterate over the set, writing out each word */
                for (const auto& item : theset)
                {
                        out << item << "\n";
                }
                /* flush the data out to the file */
                out << std::flush;
        }
        catch (std::ios::failure& iff)
        {
                /* handle any io errors */
                perror("failed to save the file");
                return false;
        }
        return true;
}

#elif defined(USEVECTOR)
/**
 * save all data out from the vector to a file
 **/
bool cpt323::saver::saver::savefile(std::string_view filename,
                                    const std::vector<std::string>& thevec)
{
        /* open the output file for writing */
        std::ofstream out(filename.data());
        if (!out)
        {
                perror("failed to open file for saving");
                return false;
        }
        /* specify the exceptions to throw */
        out.exceptions(std::ios::failbit | std::ios::badbit);
        try
        {
                /* iterate over the words in the vector and write them out to
                 * the file */
                for (const auto& item : thevec)
                {
                        out << item << "\n";
                }
                /* flush the data out to the file */
                out << std::flush;
        }
        catch (std::ios::failure& iff)
        {
                /* handle any io errors gracefully */
                perror("failed to save the file");
                return false;
        }
        return true;
}
#endif
