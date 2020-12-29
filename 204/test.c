#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   assert(htoi("0") == 0);
   assert(htoi("1") == 1);
   assert(htoi("123") == 291);
   assert(htoi("123456789") == 4886718345);
   assert(htoi("a") == 10);
   assert(htoi("A") == 10);
   assert(htoi("abcdef") == 11259375);

   printf("All tests passed.\n");
   return 0;
}
