#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   /* x = 0001, result = 0101 = 5 decimal */
   assert(invert(1,2,1) == 5);
   /* x = 1111, result = 1011 = 11 decimal */
   assert(invert(15,2,1) == 11);
   /* x = 11000000, result = 11001100 = 204 decimal */
   assert(invert(192,2,2) == 204);

   printf("All tests passed.\n");

   return 0;
}
