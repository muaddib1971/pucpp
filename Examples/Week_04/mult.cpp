#include <iostream>
#include <fstream>
#include <cstdlib>

int main(void)
{
  std::ifstream in("foo");
  return EXIT_SUCCESS;
}

class shape
{
};

class rect : public shape
{
};

class ellipse : public shape
{
};

class roundedrect : public rect, public ellipse
{
};
