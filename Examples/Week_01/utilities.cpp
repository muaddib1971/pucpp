/******************************************************************************
 *                                                                            *
 *  Object Oriented Programming Lecture 2 utilities src example code          *
 *  This program refers to the example on slide 17 of lecture 2               *
 *  Sample code provided by Jesse Archer                                      *
 *                                                                            *
 *****************************************************************************/

#include <iostream>

//--New--
//We can include our own header files just as we would in C
#include "utilities.h"

int main(int argc, char **argv)
{
  std::cout << "Enter two numbers: ";
  int i, j;
  std::cin >> i >> j;

  //We can call anything defined in our header file just as we would in C
  std::cout << "Their max is " << MAX(i, j) << "\n";
  //--End new--

  return 0;
}
