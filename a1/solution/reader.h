/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: reader.h
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/******************************************************************************
 * purpose of this file: specifies the prototype for the functions to read
 * from a text file into each data structure.
 *****************************************************************************/
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <memory>
#include <string_view>
#include <vector>
#include "list.h"
#include "tree.h"

#pragma once

namespace cpt323::reader
{
#ifdef USELIST
        std::unique_ptr<cpt323::list::list> readfile(std::string_view);
#elif defined(USETREE)
        std::unique_ptr<cpt323::tree::tree> readfile(std::string_view);
#elif defined(USESTDLIST)
        std::unique_ptr<std::list<std::string> > readfile(std::string_view);
#elif defined(USESET)
        std::unique_ptr<std::multiset<std::string> > readfile(std::string_view);
#elif defined(USEVECTOR)
        std::unique_ptr<std::vector<std::string> > readfile(std::string_view);
#endif
} // namespace cpt323::reader
