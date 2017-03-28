#include <iostream>

// ---New---
// Here we are making use of C++ strings instead of C strings
#include <string>

int main(int argc, char **argv)
{
  // Strings are part of the std namespaces, so we need to declare this
  std::string name1 = "bat";
  std::string name2 = "fruit";

  // Some operators are overloaded to make use of strings, so we can perform
  // simple += operations on strings
  name2 += name1;
  std::string name3;
  name3 = name1;
  std::cout << name3 << " " << name2 << " " << name1 << "\n";
  // ---End new---

  return 0;
}
