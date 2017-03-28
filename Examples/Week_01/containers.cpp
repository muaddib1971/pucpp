#include <iostream>

// ---New---
// Here we are making use of the vector template
#include <vector>

// Vector is in the namespace std, so we need to specify that, also when
// making use of templates we always specify what data type the template is
// dealing with using '<' and '>'. We can store any data type we want inside
// a vector
std::vector<int> int_input;

int main(int argc, char **argv)
{
  std::cout << "Enter numbers, terminate with a non-number\n";
  int num, sum = 0;
  while(std::cin >> num)
    {
      // We use the push_back method to add elements to the end of the vector
      int_input.push_back(num);
    }
  // We use the size() method to get the number of elements inside a vector, we
  // also need to cast this to an int to avoid the comparison between signed
  // and unsigned integer warning
  for(int i = 0; i < (int)int_input.size(); i++)
    {
      sum += int_input[i];
    }
  std::cout << "Their sum is " << sum << "\n";
  // ---End new---

  return 0;
}
