// Include iostream to make use of cout. Note that we don't use .h extension
// for standard C++ includes.
#include <iostream>
#include <cstdlib>
// The main function acts exactly the same as the main in C, and can be placed
// anywhere in the program, it does not need to be embedded in a class,
// like in Java.
int main(int argc, char **argv)
{
  // Note that if we don't declare use of std namespace, or std::cout, we must
  // put std:: at the beginning of every cout call. You will learn more about
  // this later. We also use the operator "<<" as we are putting the contents
  // the string into the cout stream, you will learn more about this later
  // as well.
  std::cout << "Hello world\n";
  std::cerr << "Where does this go? " << std::endl;
  //cerr goes to stderr
  //./hello 2>/dev/null -- ignore stderr
  //./hello 2>&1 | less -- redirect stderr to stdin and pipe through less

  // Return same values as we would in a C program
  return EXIT_SUCCESS; // return 0? 
}

