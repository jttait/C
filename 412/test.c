#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"

#define TOLERANCE 0.001

int main()
{
   char s[MAXLINE];
   int i;

   i = 0;
   itoa(1, s, &i);
   assert(strcmp(s, "1") == 0);

   i = 0;
   itoa(123, s, &i);
   assert(strcmp(s, "123") == 0);

   i = 0;
   itoa(-1, s, &i);
   assert(strcmp(s, "-1") == 0);

   i = 0;
   itoa(-123, s, &i);
   assert(strcmp(s, "-123") == 0);

   printf("All tests passed.\n");

   return 0;
}
