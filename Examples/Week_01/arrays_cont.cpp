#include <iostream>

const int MAX = 5;
int list[MAX];
int sum = 0, i;

int main(int argc, char **argv)
{
  // --New--
  // Pointers work exactly the same in C++ as they do in C, knowing this we
  // can expect the output to be 42
  int *ip = &i;
  *ip = 42;
  std::cout << i << "\n";

  std::cout << "\nEnter " << MAX << " numbers: ";

  // Once again, as pointers work exactly the same in C++ as they do in C, we
  // can iterate through the array using a pointer to each element
  for(ip = list; ip < list + MAX; ++ip)
    {
      std::cin >> *ip;
      sum += *ip;
    }
  // --End new--

  std::cout << "\nTheir sum is " << sum << "\n";

  return 0;
}
