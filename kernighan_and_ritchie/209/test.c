#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   /* x = 0000 */ 
   assert(bitcount(0) == 0);
   /* x = 0001 */
   assert(bitcount(1) == 1);
   /* x = 1111 */
   assert(bitcount(15) == 4);
   /* x = 1010 1010 */
   assert(bitcount(170) == 4);

   printf("All tests passed.\n");

   return 0;
}
