#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

   assert(binsearch1(6,v,10) == 5);
   assert(binsearch1(1,v,10) == 0);
   assert(binsearch1(11,v,10) == -1);

   assert(binsearch2(6,v,10) == 5);
   assert(binsearch2(1,v,10) == 0);
   assert(binsearch2(11,v,10) == -1);

   printf("All tests passed.\n");

   return 0;
}
