#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"

#define swap(t, x, y) { t temp; temp = x; x = y; y = temp; }

int main()
{
   int x, y;
   double a, b;

   x = 1;
   y = 2;
   swap(int, x, y);
   assert(x == 2);
   assert(y == 1);

   a = 101.1;
   b = 202.2;
   swap(double, a, b);
   assert(fabs(a - 202.2) < 0.01);
   assert(fabs(b - 101.1) < 0.01);

   printf("All tests passed.\n");

   return 0;
}
