#include <stdio.h>
#include "module1.h"
#include "module2.h"

int main ()
{
  printf ("start\n");
  printf ("at first, n_operations = %d\n", n_operations);
  printf ("Module name is '%s'\n", module_name);
  int a=5, b=12;
  int c = operate (a, b);
  printf ("operate(%d,%d) = %d\n", a, b, c);
  printf ("stop\n");
  printf ("at end, n_operations = %d\n", n_operations);
  return 0;
}
