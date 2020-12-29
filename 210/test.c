#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   assert(lower('A') == 'a');
   assert(lower('a') == 'a');
   assert(lower('M') == 'm');

   printf("All tests passed.\n");

   return 0;
}
