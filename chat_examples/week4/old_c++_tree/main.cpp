#include <iostream>
#include <cstdlib>
#include <vector>
#include "tree.h"

int main(void)
{
    std::vector<int>myints{1,4,2,6,3,7,-5};
    tree mytree;
    for(int i : myints)
    {
        if(mytree.add(i))
        {
            std::cout << "successfully added " << i << std::endl;
        }
    }
    mytree.print();
}
