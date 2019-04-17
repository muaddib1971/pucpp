/******************************************************************************
 * Author Name: Paul Miller
 * Author ID: E70949
 * File Name: saver.h
 * All copyright in this material resides with RMIT University.
 *****************************************************************************/
/*******************************************************************************
 * purpose of this file: specifies the function prototypes for the functions to
 * save the data structure to a file specified by the string_view parameter.
 ******************************************************************************/
#include <fstream>
#include <iostream>
#include <list>
#include <string_view>
#include <set>
#include <vector>
#include "list.h"
#include "tree.h"
#pragma once
namespace cpt323::saver
{
        class saver
        {
              public:
#ifdef USELIST
                static bool savefile(std::string_view,
                                     const cpt323::list::list&);
#elif defined(USETREE)
                static bool savefile(std::string_view,
                                     const cpt323::tree::tree&);
#elif defined(USESTDLIST)
                static bool savefile(std::string_view,
                                     const std::list<std::string>&);
#elif defined(USESET)
                static bool savefile(std::string_view,
                                     const std::multiset<std::string>&);
#elif defined(USEVECTOR)
                static bool savefile(std::string_view,
                                     const std::vector<std::string>&);
#endif
        };
} // namespace cpt323::saver
