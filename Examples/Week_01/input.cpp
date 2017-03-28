#include <iostream>

int main(int argc, char **argv)
{
  // --New--
  std::cout << "Enter 2 numbers: ";

  // Note that we do not need to declare our variables at the start of a
  // function, as we would in C89
  int i, j;

  // We use cin to get input from the user, note that we use ">>" instead
  // of "<<" as the stream will be putting results from cin into the variables
  // i and j, as opposed to using "<<" which we have been using to put the
  // contents of a string into cout.
  if(!(std::cin >> i) || !(std::cin  >> j))
      //std::cin.operator>>(std::cin, i)
      //if(std::cin.good())
  {
      int i = stoi(std::string&);
      //stol, stoul, ...

          //error
  }

  //stoi()

  std::cout << "\nThe sum is: " << i + j  << "\n";

  // ---End new---

  return 0;
}
