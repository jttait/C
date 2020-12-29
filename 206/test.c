#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   /* x = 0001, y = 0001, y' << 2 = 0100, result = 0001 | 0100 = 0101 = 5 decimal */
   assert(setbits(1,2,1,1) == 5);

   /* x = 1010, y = 0001, y' << 2 = 0100, result = 1010 | 0100 = 1110 = 14 decimal */
   assert(setbits(10,2,1,1) == 14);

   /* x = 1010, y = 0011, y' << 2 = 0110, result = 1000 | 0110 = 1110 = 14 decimal */
   assert(setbits(10,1,2,3) == 14);

   printf("All tests passed.\n");

   return 0;
}
