In this directory there is the sample solution that you want to use as a 
starting point for your assignment 2 attempt.

Some issues you should consider. This is a more advanced solution than what 
I expected most of you to do so don't worry if your varied a lot from this but
I would consider this a relatively professional implementation. 

In particular, I have implemented iterators in the standard way in c++. There
is a begin() function that gives us the starting iterator, and end() function
that gives us a pointer to the "end" of the data structure and an increment and
equivalence operator so we can increment and compare iterators. This is complete
and you will see that in my code I am able to use range based for loops just
like can be used on the STL data structures. 

I have also used std::string_view a fair amount. A string_view is a c++17 
feature that is a very small and basic class for passing around a const pointer 
to a char array. It is safe and fast so long as you don't try to modify the 
underlying data which can be gotten with the data() function. 

Please note that this is not a perfect implementation and I'm sure it's far
from bug-free. It is however an example of what a high distinction 
implementation might look like and you are heavily encouraged to use this as 
base code for assignment 2. 

I do wish to acknowledge Ben Cooper or wrote the CMakeLists.txt file in this 
directory. I also want to acknowledge the CPPCon conference recordings on 
Youtube which have provided a substantial part of my C++ knowledge. 

Ok, best of luck and I hope you have fun with assignment 2.

cheers

Paul
