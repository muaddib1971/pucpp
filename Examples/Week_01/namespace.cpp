#include <iostream>

// --New--
// We have declared that we are using the namespace std, so now when we want to
// use anything from that namespace, we need not put the std:: in front
using namespace std;

int main(int argc, char **argv)
{
  // As we have declared that we are using the namespace std, we can now call
  // cout directly
  cout << "Hello world\n";
  // --End new--

  return 0;
}
