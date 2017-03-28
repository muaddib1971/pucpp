#include <stdio.h>

// ---New---
// Although it is deprecated, we can use ordinary C-strings in our C++ programs
// by including the appropriate header, note that we can use the header string.h
// or cstring, the same also works with stdio.h, which has a cstdio header
#include <string.h>

int main(int argc, char **argv)
{
  // Here we are just using ordinary C functions
  const char *name1 = "bat";
  char name2[9] = "fruit";
  strcat(name2, name1);
  // char *name3; -- This might seg fault, changed to name3[9]
  char name3[9];
  strcpy(name3, name2);
  printf("%s\n", name3);
  // ---End new---

  return 0;
}
