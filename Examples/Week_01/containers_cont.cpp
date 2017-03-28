#include <iostream>
#include <vector>

// ---New---
// Typedef statements work exactly the same in C++ as they do in C
typedef std::vector<int> int_container;

int_container int_input;

int main(int argc, char **argv)
{
  std::cout << "Enter numbers, terminate with a non-number\n";
  int num, sum = 0;
  while(std::cin >> num)
    {
      int_input.push_back(num);
    }
  // We can use an iterator to go through the vector template, although as it
  // performs an unnatural iteration, we must tell it when to stop, and
  // increment it at each access
  for(int_container::iterator it = int_input.begin();
      it != int_input.end(); it++)
    {
      sum += *it;
    }
  // ---End new---
  std::cout << "Their sum is " << sum << "\n";

  return 0;
}
