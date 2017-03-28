#include <memory>
#include <cstdlib>
#include <iostream>

int foo(const unique_ptr<int> myint)
{
  return *myint;
}

int bar(const std::unique_ptr<int> & myint)
{
  return *myint;
}

int baz(std::unique_ptr<int> & myint)
{
  *myint = 3;
  return *myint;
}

int mak(std::shared_ptr<int> myint)
{
  return *myint;
}

int main(void)
{
  std::unique_ptr<int> unique = std::make_unique<int>(5);
  std::shared_ptr<int> shared = std::make_shared<int>(4);
  //all safe pointers are children of weak_ptr
  foo(std::move(unique));
  bar(unique);
  baz(unique);
  mak(shared);
  return EXIT_SUCCESS;
}
