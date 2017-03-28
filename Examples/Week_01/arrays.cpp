#include <iostream>

// --New--
// We have declared the variable MAX using capital letters, as this is the
// standard naming convention for all constant variables
const int MAX = 5;

// Arrays in C++ are declared in exactly the same way as they are in C
int list[MAX];

int sum = 0;

int main(int argc, char **argv)
{
  std::cout << "Enter " << MAX << " numbers: ";

  // We can declare new variables inside the declaration of the for loop,
  // just as we would in java
  for(int i = 0; i < MAX; i++)
    {
      // Here we are getting input from the user for each each element of the
      // array
      std::cin >> list[i];
      sum += list[i];
    }

  std::cout << "\nTheir sum is " << sum << "\n";
  // --End new--

  return 0;
}
