# This file provided by Ben Cooper as a solution that allows you to create all 
# required binaries for assignment 2. 
# CMAKE Reference:
# Reference: Linked list based off Week 3 chat session
# https://stackoverflow.com/questions/15223779/cmake-when-to-use-add-definitions-instead-of-set-target-propertiestarget-prope
# https://mirkokiefer.com/cmake-by-example-f95eb47d45b1
# https://www.paraview.org/Wiki/CCMake_2.8.12_Docs

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(sorter)
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -pedantic -g")

find_package(Boost 1.53 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories($Boost_INCLUDE_DIRS})

    add_library(tree tree.cpp tree.h)
    add_library(list list.cpp list.h)

    # listsorter
    ADD_EXECUTABLE(listsorter main.cpp main.h list reader.cpp reader.h saver.cpp saver.h)
    target_compile_definitions(listsorter PUBLIC USELIST)
    target_link_libraries(listsorter ${Boost_LIBRARIES})

    # treesorter
    ADD_EXECUTABLE(treesorter main.cpp main.h tree reader.cpp reader.h saver.cpp saver.h)
    target_compile_definitions(treesorter PUBLIC USETREE)    
    target_link_libraries(treesorter ${Boost_LIBRARIES})

    # stdlistsorter
    ADD_EXECUTABLE(stdlistsorter main.cpp main.h reader.cpp reader.h saver.cpp saver.h)
    target_compile_definitions(stdlistsorter PUBLIC USESTDLIST)    
    target_link_libraries(stdlistsorter ${Boost_LIBRARIES})

    # setsorter
    ADD_EXECUTABLE(setsorter main.cpp main.h reader.cpp reader.h saver.cpp saver.h)
    target_compile_definitions(setsorter PUBLIC USESET)    
    target_link_libraries(setsorter ${Boost_LIBRARIES})

    # vectorsorter
    ADD_EXECUTABLE(vectorsorter main.cpp main.h reader.cpp reader.h saver.cpp saver.h)
    target_compile_definitions(vectorsorter PUBLIC USEVECTOR)    
    target_link_libraries(vectorsorter ${Boost_LIBRARIES})

endif()
