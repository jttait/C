#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "sol.h"

int main()
{
   char s[MAXLINE];

   itoa(1, s);
   assert(strcmp(s, "1") == 0);

   itoa(123, s);
   assert(strcmp(s, "123") == 0);

   itoa(-123, s);
   assert(strcmp(s, "-123") == 0);

   itoa(0, s);
   assert(strcmp(s, "0") == 0);

   itoa(INT_MIN, s);
   assert(strcmp(s, "-2147483648") == 0);

   printf("All tests passed.\n");

   return 0;
}
