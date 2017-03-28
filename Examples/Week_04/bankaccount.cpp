/******************************************************************************
 *                                                                            *
 *  Object Oriented Programming Lecture 3 inheritance src example code        *
 *  This program refers to the example on slide 21 of lecture 3               *
 *  Sample code provided by Jesse Archer                                      *
 *                                                                            *
 *****************************************************************************/

#include <iostream>

//---New---
#include "bankaccount.h"

int main(int argc, char **argv)
{
  CheckingAccount ca;
  ca.deposit(30.0);

  //When we have declared a pointer for a class, we use the keyword new to
  //call its constructor, this will also allocate memory for the class.
  //We could use malloc to allocate memory for this object, although then
  //we would not be calling the class's constructor, which is what new does
  Check *cp = new Check;

  cp->amount = 5.0;
  ca.writeCheck(cp);

  std::cout << ca.getBalance() << "\n";

  //Now that we have finished with cp, calling delete will act similar to
  //the free function from C, except it will also call the class's
  //destructor, you will learn more about this later. Note that this will
  //cause problems if you try to access this object from the check_list inside
  //the CheckingAccount class once you have deleted it.
  delete cp;

  //---End new---

  return 0;
}
