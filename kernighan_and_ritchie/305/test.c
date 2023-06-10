#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "sol.h"

int main()
{
   char s[MAXLINE];

   itob(1, s, 16);
   assert(strcmp(s, "1") == 0);

   itob(10, s, 16);
   assert(strcmp(s, "a") == 0);

   itob(17, s, 16);
   assert(strcmp(s, "11") == 0);

   itob(100, s, 16);
   assert(strcmp(s, "64") == 0);

   itob(999, s, 16);
   assert(strcmp(s, "3e7") == 0);

   itob(101, s, 8);
   assert(strcmp(s, "145") == 0);

   printf("All tests passed.\n");

   return 0;
}
