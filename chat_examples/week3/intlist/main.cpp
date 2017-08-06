#include <iostream>
#include <cstdlib>
#include <string>
#include "intlist.h"

int main(void)
{
    linked_list list;
    while(std::cin)
    {
        std::string input;
        int value;
        std::cout << "Please enter an int to add to the list: " 
            << std::endl;
        std::getline(std::cin, input);
        if(std::cin && input != "")
        {
            value = std::stoi(input);
            list.add(value);
        }
        else{
            break;
        }
    }
    list.print();
    return EXIT_SUCCESS;
}
