#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "sol.h"

int main()
{
   char s[MAXLINE];

   itoa(1, s, 1);
   assert(strcmp(s, "1") == 0);

   itoa(1, s, 2);
   assert(strcmp(s, " 1") == 0);

   itoa(1, s, 3);
   assert(strcmp(s, "  1") == 0);

   itoa(-1, s, 3);
   assert(strcmp(s, " -1") == 0);

   itoa(-101, s, 4);
   assert(strcmp(s, "-101") == 0);

   printf("All tests passed.\n");

   return 0;
}
