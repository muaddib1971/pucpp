/#include <iostream>

int main(int argc, char **argv)
{
  // --New--
  // Rather than using everything in the std namespace, we can declare that
  // we are using only specific components, such as cin
  using std::cin;

  // As we have not declared that we are using std::cout, we must still
  // declare that it is in the std namespace when we use it
  std::cout << "Enter two numbers: ";

  int i, j;

  // As we have declared that we are using std::cin, we can now call cin
  // directly
  cin >> i >> j;

  // Now we are declaring that we are using the entire std namespace
  using namespace std;

  // We can now call cout directly, as we are using the entire std namespace
  cout << "\nTheir sum is " << i + j << "\n";
  // --End new--

  return 0;
}
