#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   /* x = 0000 */ 
   assert(rightrot(0, 10) == 0);
   /* x = 0001, result = 1000 0000 0000 0000 0000 0000 0000 0000 = */
   assert(rightrot(1, 1) == 2147483648);
   /* x = 1111, result = 1111 0000 0000 0000 0000 0000 0000 0000 = */
   assert(rightrot(15, 4) == 4026531840);

   printf("All tests passed.\n");

   return 0;
}
