#include <iostream>

// --New--
// We can have global variables defined in either .cpp or .h files, just as we
// would in C
int result;

// We can define functions in C++ in either .cpp or .h files, just as we
// would in C, note that this function is recursive and uses an if else
// statement which behaves in the same way as it would in C
int factorial(int n)
{
  int f_val = n;
  if(f_val == 1)
    return f_val;
  else
    return f_val + factorial(n - 1);
}

int main(int argc, char **argv)
{
  std::cout << "Enter a number: ";
  int n;
  std::cin >> n;

  // We can call functions and have their return value go directly into a
  // stream, as below where the result goes into cout as an int
  std::cout << "\nThe factorial is: " << factorial(n) << "\n";
  // --End new--

  return 0;
}
